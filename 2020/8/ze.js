const fs = require('fs');
let commands = [];
// command structure = {command, value, isRan}
try {
    const data = fs.readFileSync('input.txt', 'UTF-8');
    const lines = data.split(/\r?\n/);
    lines.forEach((line) => {
        let [command,value] = line.split(' ');
       commands.push({command, value: Number(value), isRan: false});
    });
} catch (err) {
    console.error(err);
}

let getAcc = () => {
    let acc = 0;
    let i = 0;
    let hasPassed = {};
    while (true) {
        if (i == commands.length) { 
            return acc; 
        }
        if (hasPassed[i] || i < 0 || i > commands.length) {
            return;
        }
        hasPassed[i] = true;
        let currentCommand = commands[i];
        
        if (currentCommand.command == "acc")  acc += currentCommand.value;
        if(currentCommand.command == 'jmp') i += currentCommand.value;
        else i += 1;
    }
}
for(let i = 0; i < commands.length; i += 1){
    currCommand = commands[i];
    if (currCommand.command == "jmp" || currCommand.command == "nop") {
        currCommand.command = (currCommand.command == "jmp") ? "nop" : "jmp";
        let result = getAcc();
        if (result) {
            console.log("Part 2", result);
            return;
        }
        currCommand.command = (currCommand.command == "jmp") ? "nop" : "jmp";
    }
}
