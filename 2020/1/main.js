const fs = require("fs")

// Need 50 
//let starts;

// need two enteries that sum 2020 and then multiply those two together

let entries = fs.readFileSync("input.txt").toString().split("\n").map(Number)

for(let entry of entries) {
	let a = entries.find(i => i+entry == 2020 && i != entry)

	if(a) {
		console.log("1: ", a, " 2:", entry)
		console.log(a*entry)
		return
	}
}


//for (let entry of entries) {
//	for(let entry2 of entries)
//		for(let entry3 of entries)
//		{
//		if(entry != 0 && entry2 != 0 && entry3 != 0 && entry + entry2 + entry3 == 2020)
//			{
//				console.log(entry, "  ", entry2, " ", entry3)
//				console.log(entry*entry2*entry3)
//				return
//			}
//		}
//}
