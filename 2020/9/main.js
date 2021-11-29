const fs = require("fs");
const input = fs.readFileSync("input.txt").toString().split("\n").map(Number);

const preamble = 25;

function hasSum(array, value) {
	for(let elem1 of array)  {
		for(let elem2 of array) {
			if(elem1 + elem2 == value)
				return true;
		}
	}

	return false;
}

function arrayMin( array ){
    return Math.min.apply( Math, array );
};

function arrayMax( array ){
    return Math.max.apply( Math, array );
};

let value;

for(let i = preamble - 1; i < input.length; i++) {
	if(!hasSum(input.slice(i-preamble+1, i + 1), input[i+1])) {
		console.log("Parte 1:", input[i+1])
		value = input[i+1];
		break;
	}
}

let sumArray = [];
let sum = 0;

for(let i = 0; i < input.length; i++) {
	for(let a = i; a < input.length; a++) {
		sum += input[a];
		sumArray.push(input[a])
		if(sum == value) {
			console.log("Parte 2: ",arrayMin(sumArray) + arrayMax(sumArray))
			return;
		} 

		if(sum > value) {
			sum = 0;
			sumArray = [];
			break;
		}
	}
}
