/* eslint-disable prefer-const */
/* eslint-disable comma-dangle */
/* eslint-disable indent */
/* eslint-disable quotes */
/* eslint-disable no-unused-vars */
/* eslint-disable camelcase */
/* eslint-disable space-before-function-paren */
/* eslint-disable semi */

let msgBoard = {
    handlers: [],
    messages: [],
    boardName: "IWP Chat",
    register: function (f) {
        this.handlers.push(f);
    },
    printMessages: function () {
        console.log("Messages History in board " + this.boardName + ":");
        for (let m of this.messages) {
            console.log(m);
        }
    },
    putMessage: function (m) {
        this.messages.push(m);
    },
    sendAndNotifyMessage: function (message) {
        this.messages.push(message);
        for (let f of this.handlers) {
            f(this.boardName.message);
        }
    },
};

function briansHandler(boardName, message) {
    console.log(`Thomas! A message from ${boardName}: ${message}`);
}

msgBoard.register(briansHandler);
msgBoard.register((board, message) =>
    console.log(`oard ${board} says to Michele: ${message}`)
);
msgBoard.sendAndNotifyMessage("URGENT: Opgaveregning nu!");

function MessageBoard(boardname) {
    this.handlers = [];
    this.messages = [];
    this.boardName = boardname;
    this.register = function (f) {
        this.handlers.push(f);
    };
    this.printMessages = function () {
        console.log("Messages History in board " + this.boardName + ":");
        for (let m of this.messages) console.log(m);
    };
    this.putMessage = function (m) {
        this.messages.push(m);
    };
    this.sendAndNotifyMessage = function (message) {
        this.messages.push(message);
        for (let f of this.handlers) f(this.boardName, message);
    };
}

let board2 = new MessageBoard("Opgave Regning");
