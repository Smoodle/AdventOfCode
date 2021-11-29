const fs = require("fs")
let entries = fs.readFileSync("input.txt").toString().split("\n").map(Number)
let set = new Set(entries);

for(let elem of set) {
	if(set.has(2020-elem)) {
		console.log("1: ", elem, " 2:", 2020-elem)
		console.log(elem*(2020-elem))
		return;
	}
}
