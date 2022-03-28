/* eslint-disable space-before-function-paren */
/* eslint-disable semi */
/* eslint-disable quotes */
/* eslint-disable indent */

function ex3aFunction(msg) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            console.log(msg), resolve();
        }, 2000);
    });
}
