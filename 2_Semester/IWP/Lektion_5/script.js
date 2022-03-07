/* eslint-disable padded-blocks */
/* eslint-disable indent */
/* eslint-disable quotes */

function listChecked() {
    let htmlelement = document.querySelectorAll(
        '#beerForm input[name="gæringstype"]'
    );

    for (const i of htmlelement) {
        // console.log(i.value);
        console.log(i.checked);
    }
}

function addElement() {
    let title = document.createElement("h1");

    title.append("Vælg en Øl-type");

    document.body.prepend(title);
}

function eventHandler() {
    let knapElem = document.querySelectorAll('#beerform input[type="button"]');

    console.log(knapElem);

    knapElem.addEventListener("click", listChecked);
}

let knapElem = document.querySelectorAll('#beerform input[type="button"]');

knapElem.addEventListener("click", listChecked);
