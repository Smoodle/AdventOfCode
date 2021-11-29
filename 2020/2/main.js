const fs = require("fs")

let data = fs.readFileSync("input.txt").toString().split("\n");

function isValid(low, high, letter, str) {
	if(!low) return;

	let count = 0

	for(let a = 0; a < str.length; a++) {
		if(str.charAt(a) == letter)
			count++;
	}

	if(count >= low && count <= high)
		return true

	return false
}

function newIsValid(low, high, letter, str) {
	if(!low || !high) return;

	if(str[low - 1] == letter && str[high - 1] != letter)
		return true

	if(str[high - 1] == letter && str[low - 1] != letter)
		return true

	return false
}

let result = 0;

for(let value of data) {
	if(value == "") continue

	let low = Number(value.split("-")[0])
	let high = Number(value.split("-")[1].split(" ")[0])
	let letter = value.split("-")[1].split(" ")[1][0]
	let str = value.split("-")[1].split(" ")[2]

	let valid = newIsValid(low, high, letter, str.trim())

	if(valid) {
		result++;
	}
}

console.log(result)
