const MIN_ROW = 0
const MAX_ROW = 127
const MIN_COLUMN = 0
const MAX_COLUMN = 7

const fs = require("fs")

let input = fs.readFileSync("input.txt").toString().split("\n");

function getSeatID(rowMin, rowMax, columnMin, columnMax, seat) {
	if(rowMin == rowMax && columnMin == columnMax)
		return rowMin * 8 + columnMax;

	if(seat[0] == "F") 
		return getSeatID(rowMin, Math.floor((rowMin + rowMax) / 2), columnMin, columnMax, seat.substring(1))

	if(seat[0] == "B") 
		return getSeatID(Math.round((rowMin + rowMax) / 2), rowMax, columnMin, columnMax, seat.substring(1))

	if(seat[0] == "R") 
		return getSeatID(rowMin, rowMax, Math.round((columnMin + columnMax) / 2), columnMax, seat.substring(1))

	if(seat[0] == "L") 
		return getSeatID(rowMin, rowMax, columnMin, Math.floor((columnMin + columnMax) / 2), seat.substring(1))

	if(seat.length == 0) 
		return -1;
}

let max = 0;
let list = new Set(); // For part 2

for(let str of input) {
	let result = getSeatID(MIN_ROW, MAX_ROW, MIN_COLUMN, MAX_COLUMN, str)
	if(result > max) max = result;

	//Part 2
	list.add(result);
}

console.log("Max is : ", max)

//Part 2
for(let elem of list) {
	if(list.has(elem+2) && !list.has(elem+1)) {
		console.log("My id is: ", elem+1)
		return;
	}
}
