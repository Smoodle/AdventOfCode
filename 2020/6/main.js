const fs = require("fs");

let input = fs.readFileSync("input3.txt").toString().split("\n\n").map((i) => {
	i = i.replace(/\n/g, "");
	return new Set(i.split(""))
});

sum = 0;

for(elem of input)
	sum+=elem.size;

console.log("my sum is: ", sum)

// Part 2
let input2 = fs.readFileSync("input3.txt").toString().split("\n\n").map((i) => {
	let arr = []
	
	for(elem of i.split(/\n/g)) {
		arr.push(new Set(elem.split("")))
	}

	return arr;
});

function countMatchingArray(array) {
	let completeSet = new Set()
	if(array.length == 1)
		return array[0].size;

	//Put all elements in a set
	for(let elem of array)
		for(let elem2 of elem)
			completeSet.add(elem2)

	let setCounter = 0;
	let counter = 0;
	for(let elem of completeSet) {
		for(let set of array) {
			if(set.has(elem))
				setCounter++;

			if(setCounter == array.length)
				counter++;
		}

		setCounter = 0;
	}
			
	return counter;
}


let counter2 = 0;
for(elem of input2) {
	counter2 += countMatchingArray(elem);
}

console.log("Part 2 is: ", counter2)
