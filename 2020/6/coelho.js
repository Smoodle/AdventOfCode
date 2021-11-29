const fs = require("fs")

const people = fs
  .readFileSync("input2.txt")
  .toString()
  .split("\n\n")
  .map((person) => {
    person = person.replace(/\n/g, "");
    return new Set(person.split(""));
  });

let sum = 0;
for (const questions of people) {
  sum += questions.size;
}

console.log(sum)
