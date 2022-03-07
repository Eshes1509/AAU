/* eslint-disable semi */
/* eslint-disable padded-blocks */
/* eslint-disable indent */
/* eslint-disable quotes */

let button = document.querySelector('#beerForm  input[type="button"]');
let htmlElement = document.querySelectorAll(
    '#beerForm input[name="gæringstype"]'
);

function listChecked() {
    for (const i of htmlElement) {
        // console.log(i.value);
        console.log(i.checked);
    }
}

// Exercise 2
let title = document.createElement("h1");

title.append("Vælg en Øl-type");

document.body.prepend(title);

// Exercise 3
button.addEventListener("click", listChecked);

// Exercise 4
function reportEvent(event) {
    console.log(
        event.currentTarget.nodeName +
            " " +
            event.target.nodeName +
            " " +
            event.target.innerHTML
    );
}
// document.body.addEventListener("mouseover", reportEvent);

// Exercise 5
function offline() {
    let beerTypes = {
        ales: [
            "Bitter",
            "Pale Ale",
            "Brown Ale",
            "Trappist",
            "Porter",
            "Weizenbier",
        ],
        lagers: ["Pilsner", "Münchener", "Wiener", "Bock", "Porter"],
        wilds: ["Gueuze", "Faro", "Fruit"],
    };
    buildMenus(beerTypes);
    // showSections();
}

offline();

function buildSelect(list, id) {
    let select = document.createElement("select");
    select.id = id;
    for (let a of list) {
        // construct and append an option element per beer type item
        let opt = document.createElement("option");
        opt.append(a); // assign the text to show, and
        opt.value = a; // assign the value to be returned when selected; here just the option text.
        select.append(opt);
    }
    return select;
}

function buildMenus(beerTypes) {
    //first construct a select menu per beer base type.
    let alesSelect = buildSelect(beerTypes.ales, "selectBeer");
    let lagerSelect = buildSelect(beerTypes.lagers, "selectBeer");
    let wildSelect = buildSelect(beerTypes.wilds, "selectBeer");

    // Show one of the menus as a default, corresponding to the default choice
    //(observe that the he "overgæret" radio button is "checked")
    button.before(alesSelect);

    //Register the event handler on all menus, such that the corresponing beer undertype change when user change the over-type
    //This is implemented by replacing the element representing the current type with the menu representing the newly chosen type
    //as we use the same callback function showSelect on all three radion buttons, the function needs to distinguish its behavior depending on the target.
    //this choice is made by using the information carried to the handler function by the event.target object (reading the value attribue of the HTML element)
    for (let r of htmlElement) r.addEventListener("click", showSelect);

    function showSelect(event) {
        console.log("SELECT" + event.target.value);
        let currentSelect = document.querySelector("#selectBeer");
        console.log(currentSelect);
        switch (event.target.value) {
            case "overgæret":
                currentSelect.replaceWith(alesSelect);
                break;
            case "undergæret":
                currentSelect.replaceWith(lagerSelect);
                break;
            case "vildgæret":
                currentSelect.replaceWith(wildSelect);
                break;
            default:
                console.log("OOPS");
                break;
        }
    }
}
