const fs = require("fs");
const input = fs.readFileSync("input.txt").toString().split("\n");

let seats = [];

for(let elem of input) {
	if(elem == "") break;
	seats.push(elem.split(""));
}

let changed = true;
let swapPositions = []

function checkAdjacents(y, x) {
	let map = {"L":0, "#": 0, ".":0}

	if(seats[y+1])
		map[seats[y+1][x]]++;

	if(seats[y-1])
		map[seats[y-1][x]]++;

	if(seats[y][x+1])
		map[seats[y][x+1]]++;
	
	if(seats[y][x-1])
		map[seats[y][x-1]]++;

	if(seats[y+1] && seats[y+1][x+1])
		map[seats[y+1][x+1]]++;

	if(seats[y+1] && seats[y+1][x-1])
		map[seats[y+1][x-1]]++;

	if(seats[y-1] && seats[y-1][x+1])
		map[seats[y-1][x+1]]++;

	if(seats[y-1] && seats[y-1][x-1])
		map[seats[y-1][x-1]]++;

    return map;
}

while (changed) {
	changed = false;

	for(let y = 0; y < seats.length; y++) {
		for(let x = 0; x < seats[0].length; x++) {

			if(seats[y][x] == "L") {
				let adjacent = checkAdjacents(y,x);

				if(adjacent["#"] == 0)
					swapPositions.push([y, x])

				continue;
			}

			if(seats[y][x] == "#") {
				let adjacent = checkAdjacents(y,x);

				if(adjacent["#"] >= 4)
					swapPositions.push([y, x])
			}
		}
	}

	if(swapPositions.length > 0)
		changed = true;

	for(elem of swapPositions) {
		seats[elem[0]][elem[1]] = seats[elem[0]][elem[1]] == "L" ? "#" : "L";
	}

	swapPositions = [];
}

let occupied = 0;
for(let row of seats) 
	for(let seat of row)
		if(seat == "#") occupied++;

console.log("Parte 1:", occupied)

function checkAdjacentsIgnore(y, x) {
	let map = {"L":0, "#": 0, ".":0}

	if(seats[y+1]) {
		if(seats[y+1][x] == ".") {
			let a = 1;
			while(seats[y+a] && seats[y+a][x] == ".")
				a++;
			if(seats[y+a])
				map[seats[y+a][x]]++;
		} else
			map[seats[y+1][x]]++;
	}

	if(seats[y-1]) {
		if(seats[y-1][x] == ".") {
			let a = 1;
			while(seats[y-a] && seats[y-a][x] == ".")
				a++;
			if(seats[y-a])
				map[seats[y-a][x]]++;
		} else
			map[seats[y-1][x]]++;
	}

	if(seats[y][x+1]) {
		if(seats[y][x+1] == ".") {
			let a = 1;
			while(seats[y][x+a] && seats[y][x+a] == ".")
				a++;
			if(seats[y][x+a])
				map[seats[y][x+a]]++;
		} else
			map[seats[y][x+1]]++;
	}
	
	if(seats[y][x-1]) {
		if(seats[y][x-1] == ".") {
			let a = 1;
			while(seats[y][x-a] && seats[y][x-a] == ".")
				a++;
			if(seats[y][x-a])
				map[seats[y][x-a]]++;
		} else
			map[seats[y][x-1]]++;
	}

	if(seats[y+1] && seats[y+1][x+1]) {
		if(seats[y+1][x+1] == ".") {
			let a = 1;
			while(seats[y+a] && seats[y+a][x+a] && seats[y+a][x+a] == ".")
				a++;
			if(seats[y+a] && seats[y+a][x+a])
				map[seats[y+a][x+a]]++;
		} else
			map[seats[y+1][x+1]]++;
	}

	if(seats[y+1] && seats[y+1][x-1]) {
		if(seats[y+1][x-1] == ".") {
			let a = 1;
			while(seats[y+a] && seats[y+a][x-a] && seats[y+a][x-a] == ".")
				a++;
			if(seats[y+a] && seats[y+a][x-a])
				map[seats[y+a][x-a]]++;
		} else
			map[seats[y+1][x-1]]++;
	}

	if(seats[y-1] && seats[y-1][x+1]) {
		if(seats[y-1][x+1] == ".") {
			let a = 1;
			while(seats[y-a] && seats[y-a][x+a] && seats[y-a][x+a] == ".")
				a++;
			if(seats[y-a] && seats[y-a][x+a])
				map[seats[y-a][x+a]]++;
		} else
			map[seats[y-1][x+1]]++;
	}

	if(seats[y-1] && seats[y-1][x-1]) {
		if(seats[y-1][x-1] == ".") {
			let a = 1;
			while(seats[y-a] && seats[y-a][x-a] && seats[y-a][x-a] == ".")
				a++;
			if(seats[y-a] && seats[y-a][x-a])
				map[seats[y-a][x-a]]++;
		} else
			map[seats[y-1][x-1]]++;
	}

    return map;
}

seats = [];

for(let elem of input) {
	if(elem == "") break;
	seats.push(elem.split(""));
}

changed = true;
swapPositions = [];

while (changed) {
	changed = false;

	for(let y = 0; y < seats.length; y++) {
		for(let x = 0; x < seats[0].length; x++) {

			if(seats[y][x] == "L") {
				let adjacent = checkAdjacentsIgnore(y,x);

				if(adjacent["#"] == 0)
					swapPositions.push([y, x])

				continue;
			}

			if(seats[y][x] == "#") {
				let adjacent = checkAdjacentsIgnore(y,x);

				if(adjacent["#"] >= 5)
					swapPositions.push([y, x])
			}
		}
	}

	if(swapPositions.length > 0)
		changed = true;

	for(elem of swapPositions) {
		seats[elem[0]][elem[1]] = seats[elem[0]][elem[1]] == "L" ? "#" : "L";
	}

	swapPositions = [];
}

occupied = 0;
for(let row of seats) 
	for(let seat of row) 
		if(seat == "#") occupied++;

console.log("Parte 2:", occupied);
