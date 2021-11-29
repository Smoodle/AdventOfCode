const fs = require("fs");

const instructions = fs.readFileSync("input.txt").toString().split("\n");

//Parte 1
let accumulator = 0;
let history = [];

for(let i = 0; i < instructions.length; i++) {
    let split = instructions[i].split(" ");
    let action = split[0];
    let amount = parseInt(split[1]);

    if(history.includes(i))
        break;

    history.push(i);

    if(action == "acc") {
        accumulator += amount;
        continue;
    }

    if(action == "jmp") {
        i += amount - 1;

        continue;
    }
}

console.log("Parte 1:", accumulator);

//Parte 2
accumulator = 0;
history = [];
let historyIndex = -1;
let accumulatorHistory = -1;

for(let i = 0; i < instructions.length; i++) {
    let split = instructions[i].split(" ");
    let action = split[0];
    let amount = parseInt(split[1]);

    if(history.includes(i)) {
        accumulator = accumulatorHistory;
        history = [];
        i = historyIndex - 1;
        continue;
    }

    history.push(i);

    if(action == "acc") {
        accumulator += amount;
        continue;
    }

    if(action == "jmp") {
        if(historyIndex == i) {
            i += amount - 1;
            historyIndex = -1;
            continue;
        }

        if(historyIndex == -1) {
            historyIndex = i;
            accumulatorHistory = accumulator;
            continue;
        } else {
            i += amount - 1;
        }
    }

    if(action == "nop") {
        if(historyIndex == i) {
            historyIndex = -1;
            continue;
        }

        if(historyIndex == -1 && amount != 0) {
            historyIndex = i;
            accumulatorHistory = accumulator;
            i += amount - 1;
            continue;
        } 
    }
}

console.log("Parte 2:", accumulator);
