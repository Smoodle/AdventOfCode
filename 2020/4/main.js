const fs = require("fs")

//Data import
let data = fs.readFileSync("input2.txt").toString().split("\n").map((v) => {
	if(v == '')
		return;

	let strSplit = v.split(" ");

	return strSplit
});

let finalArray = []
let obj = {}

for (elem of data) {
	if(elem == undefined) {
		finalArray.push(obj)
		obj = {}
		continue;
	}

	for(e of elem) {
		obj[e.split(":")[0]] = e.split(":")[1]
	}
}

//Field checking
const validFields = ["byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"];
const validEyeColors = ["amb", "blu", "brn", "gry", "grn", "hzl", "oth"]
const hairColorRegex = new RegExp("^#([a-f0-9]{6})$");
const passportIdRegex = new RegExp("^[0-9]{9}$");

function validateFields(field) {
	if(!validFields.every(i => Object.keys(field).includes(i)))
		return false;

	if(Number(field["byr"]) < 1920 || Number(field["byr"] > 2002))
		return false;

	if(Number(field["iyr"]) < 2010 || Number(field["iyr"] > 2020))
		return false;

	if(Number(field["eyr"]) < 2020 || Number(field["eyr"] > 2030))
		return false;

	if(field["hgt"].includes("cm"))
		if(Number(field["hgt"].replace("cm", "")) < 150 || Number(field["hgt"].replace("cm", "")) > 193 )
			return false;

	if(field["hgt"].includes("in"))
		if(Number(field["hgt"].replace("in", "")) < 59 || Number(field["hgt"].replace("in", "")) > 76 )
			return false;

	if(!field["hgt"].includes("cm") && !field["hgt"].includes("in"))
		return false;

	if(!hairColorRegex.test(field["hcl"]))
		return false;

	if(!validEyeColors.includes(field["ecl"]))
		return false;

	if(!passportIdRegex.test(field["pid"]))
		return false;

	return true;
}

let counter = 0;
for(o of finalArray) {
	if(validateFields(o))
		counter++;
}

console.log("There are ", counter, " valid");
