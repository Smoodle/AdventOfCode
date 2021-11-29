const fs = require("fs")

let data = fs.readFileSync("input2.txt").toString().split("\n").map((v) => {
	if(v == '')
		return;

	return v.split("");
});

function hasTree(right, down) {
	if(down >= data.length)
		return false;
	
	while(right >= data[down].length) 
		right = right - data[down].length;

	if(data[down][right] == "#")
		return true;

	return false;
}

let slope1 = 0;
let slope2 = 0;
let slope3 = 0;
let slope4 = 0;
let slope5 = 0;

for(let i = 1; i < data.length; i++) {
	if(data[i] == undefined)
		continue;

	if(hasTree(i*1, i)) slope1++;
	if(hasTree(i*3, i)) slope2++;
	if(hasTree(i*5, i)) slope3++;
	if(hasTree(i*7, i)) slope4++;
	if(hasTree(i*1, i*2)) slope5++;
}

console.log(slope1*slope2*slope3*slope4*slope5)
