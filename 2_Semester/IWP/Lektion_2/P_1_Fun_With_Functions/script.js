/* eslint-disable indent */
/* eslint-disable quotes */
/* eslint-disable no-unused-vars */
/* eslint-disable camelcase */
/* eslint-disable space-before-function-paren */
/* eslint-disable semi */

const diceRoll = [1, 6, 6, 2, 3, 4, 6];

function get6s_v1(dice) {
    for (let i = 0; i < dice.length; i++) {
        if (dice[i] === 6) {
            console.log(i + ":" + dice[i]);
        }
    }
}

function is6(d) {
    if (d === 6) {
        return true;
    }
}

function get6s_v2(dice) {
    for (let i = 0; i < dice.length; i++) {
        if (is6(dice[i])) {
            console.log(i + ":" + dice[i]);
        }
    }
}

function get6s_v3(dice, compare) {
    for (let i = 0; i < dice.length; i++) {
        if (compare(dice[i])) {
            console.log(i + ":" + dice[i]);
        }
    }
}

function findDices_v1(dice, compare) {
    for (let i = 0; i < dice.length; i++) {
        if (compare(dice[i])) {
            console.log(i + ":" + dice[i]);
        }
    }
}
