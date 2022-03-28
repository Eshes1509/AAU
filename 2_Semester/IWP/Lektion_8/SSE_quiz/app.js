/* eslint-disable no-unused-vars */
/* eslint-disable eqeqeq */
/* eslint-disable space-before-function-paren */
/* eslint-disable indent */
/* eslint-disable space-before-blocks */
/* eslint-disable padded-blocks */
/* eslint-disable prefer-const */
/* eslint-disable comma-spacing */
/* eslint-disable quotes */
/* eslint-disable space-infix-ops */
/* eslint-disable semi */
const http = require("http");
const fs = require("fs");
const path = require("path");
const util = require("util");

// An array of ServerResponse objects that we're going to send events to
let clients = [];

const publicResources = "PublicResources/";
// secure file system access as described on
// https://nodejs.org/en/knowledge/file-system/security/introduction/
const rootFileSystem = process.cwd();
function securePath(userPath) {
    if (userPath.indexOf("\0") !== -1) {
        // could also test for illegal chars: if (!/^[a-z0-9]+$/.test(filename)) {return undefined;}
        return undefined;
    }
    userPath = path.normalize(userPath).replace(/^(\.\.(\/|\\|$))+/, "");
    userPath = publicResources + userPath;

    let p = path.join(rootFileSystem, path.normalize(userPath));
    return p;
}

const server = http.createServer((req, res) => {
    let date = new Date();
    console.log("GOT: " + req.method + " " + req.url);
    if (req.method == "GET") {
        switch (req.url) {
            case "/":
                fileResponse("index.html", res);
                break;
            default:
                fileResponse(req.url, res);
                break;
        }
    } else if (req.method == "POST" && req.url == "/spy") {
        let spydate = new Date();

        let body = "";
        req.on("data", function (chunk) {
            body += chunk;
        });

        req.on("end", function () {
            let spyfile = path.join(rootFileSystem, "spylog.txt");
            let spymsg =
                JSON.stringify(spydate) +
                ", " +
                req.socket.remoteAddress +
                ":" +
                req.socket.remotePort +
                ", " +
                body;
            console.log(spymsg);
            fs.appendFile(spyfile, spymsg + "\n", (err) => {
                if (err) throw err;
                console.log("Saved!");
            });

            res.writeHead(200, { "Content-Type": "text/html" });
            console.log("I have just spied: ", spymsg);
            res.end(JSON.stringify(spymsg));
        });
    } else {
        res.statusCode = 200;
        res.setHeader("Content-Type", "application/json");
        res.end("\n");
    }
});

/* // When the server gets a new request, run this function
server.on("request", (request, response) => {
    // Parse the requested URL
    let pathname = url.parse(request.url).pathname;
    // If the request was for "/", send the client-side chat UI.
    if (pathname === "/") {
        // A request for the chat UI
        response
            .writeHead(200, {
                "Content-Type": "text/html",
            })
            .end(clientHTML);
    }
    // Otherwise send a 404 error for any path other than "/chat" or for
    // any method other than "GET" and "POST"
    else if (
        pathname !== "/chat" ||
        (request.method !== "GET" && request.method !== "POST")
    ) {
        response.writeHead(404).end();
    }
    // If the /chat request was a GET, then a client is connecting.
    else if (request.method === "GET") {
        acceptNewClient(request, response);
    }
    // Otherwise the /chat request is a POST of a new message
    else {
        broadcastNewMessage(request, response);
    }
}); */

// This handles GET requests for the /chat endpoint which are generated when
// the client creates a new EventSource object (or when the EventSource
// reconnects automatically).
function acceptNewClient(request, response) {
    // Remember the response object so we can send future messages to it
    clients.push(response);
    // If the client closes the connection, remove the corresponding
    // response object from the array of active clients
    request.connection.on("end", () => {
        clients.splice(clients.indexOf(response), 1);
        response.end();
    });
    // Set headers and send an initial chat event to just this one client
    response.writeHead(200, {
        "Content-Type": "text/event-stream",
        Connection: "keep-alive",
        "Cache-Control": "no-cache",
    });
    response.write("event: chat\ndata: Connected\n\n");
    // Note that we intentionally do not call response.end() here.
    // Keeping the connection open is what makes Server-Sent Events work.
}

server.listen(port, hostname, () => {
    console.log(`Server running at http://${hostname}:${port}/`);
});
