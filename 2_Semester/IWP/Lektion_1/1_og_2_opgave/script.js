/* eslint-disable eol-last */
/* eslint-disable space-before-function-paren */
/* eslint-disable semi */
/* eslint-disable no-unused-vars */
/* eslint-disable quotes */
function triangle() {
  let triangle = "#";

  for (let i = 1; i < 8; i++) {
    console.log(triangle);

    triangle += "#";
  }
}
console.log("\n");

// let chess = "";
function chessBoard(size) {
  for (let i = 0; i < size; i++) {
    const size = 8;
    let chess = "";
    for (let j = 0; j < size; j++) {
      if (i % 2 === 0) {
        if (j % 2 === 0) {
          chess += "#";
        } else {
          chess += " ";
        }
      } else {
        if (j % 2 === 0) {
          chess += " ";
        } else {
          chess += "#";
        }
      }
    }
    console.log(chess);
  }
}

console.log("hej");
