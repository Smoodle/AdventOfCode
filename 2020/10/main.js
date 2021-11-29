const fs = require("fs");
const input = fs.readFileSync("input.txt").toString().split("\n").map(Number).sort((a, b) => a - b );

let value1 = 0, value3 = 0;

input.push(input[input.length - 1] + 3); // Biggest Outlet

for(let i = 0; i < input.length; i++) {
	if((input[i] - input[i-1]) == 1) value1++;
	if((input[i] - input[i-1]) == 3) value3++;
}

console.log("Parte 1: ", value1 * value3);

//Adicionar o socket da parede como 1
let adapters = {[input[input.length - 1]] : 1};
let diffs = [1,2,3];

//Começar do valor mais alto
for(let i = input[input.length - 1] - 1; i >= 0; i--) {
	if(input.includes(i)) {

		//Ver as diffs dele
		adapters[i] = diffs.map((skip) => {
			if(adapters[i + skip]) {
				return adapters[i + skip];
			}else return 0;
		}).reduce((a,b) => a+b) // Somar tudo

	}
}

console.log("Parte 2:", adapters[0])
