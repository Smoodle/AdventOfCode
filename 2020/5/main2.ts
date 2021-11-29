import { InputString } from './input';

const idToNumber = (id: string): number => {
    const locationChecker = (input: string, lowerChar: string, upperChar: string, lower: number, upper: number) => {
        const firstElement = input[0];
        let currentHalf = { lower: firstElement === lowerChar ? lower : Math.floor(upper /2)+1, upper: firstElement === lowerChar ? Math.floor(upper /2) : upper };
        for(let i=1; i< input.length - 1; i++) {
            const element = input[i];
            if(element === lowerChar) {
                currentHalf.upper = Math.floor((currentHalf.lower + currentHalf.upper) / 2);
            } else {
                currentHalf.lower = Math.round((currentHalf.lower + currentHalf.upper) / 2);
            }
        }
        const result = input[input.length -1] === upperChar ? currentHalf.upper : currentHalf.lower;
        return result;
    }
    const row = locationChecker(id.slice(0,7), 'F', 'B', 0, 127);
    const col = locationChecker(id.slice(7,10), 'L', 'R', 0, 7);
    return row * 8 + col;
};

function highestId() {
    let highest = "";
    let highestValue = 0;
    for(let i=0; i< InputString.length; i+=10) {
        const id = InputString.slice(i,i+10);
        const idValue = idToNumber(id);

        if(idValue > highestValue) {
            highestValue = idValue;
            highest = id;
        }   
    }
    return highestValue;
}

function findMySeat() {
    let seats = [];
    for(let i=0; i< InputString.length; i+=10) { 
        const id = InputString.slice(i, i+10);
        const idValue = idToNumber(id);
        seats.push(idValue);
    }
    seats.sort((a,b) => a-b);

    let mySeat = 0;
    for(let i=0; i< seats.length; i++) {
        const cur = seats[i];

        if(seats[i+1] - cur > 1) {
            mySeat = cur +1;
            break;
        }
    }
    return mySeat;
}
