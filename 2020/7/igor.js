const fs = require("fs")

function readFile(inputNumber, constructor = String) {
    return fs.readFileSync("input.txt")
        .toString()
        .split('\n')
        .map(line => constructor(line.replace('\r', '')))
        .filter(line => line);
}

const input7 = readFile();

function numOfBags(color, colorSet = new Set()) {
    input7.filter(rule => rule.split('contain')[1].includes(color)).forEach(rule => {
        const bagColor = rule.split('contain')[0].replace(' bags ', '')
        if (!colorSet.has(bagColor)) {
            colorSet.add(bagColor)
            numOfBags(bagColor, colorSet)
        }
    })

    return colorSet.size
}
console.log(numOfBags('shiny gold'))

function numOfTotalBags(color, counter = 0, multiplier = 1) {
    for (rule of input7) {
        const bagColor = rule.split('contain')[0]

        if (bagColor.includes(color)) {
            const canHold = rule.split('contain')[1]

            counter += canHold.split(', ').reduce((acc, value) => {
                if (value.includes('no other'))
                    return acc
                else {
                    const canHoldColor = value.trim().split(' ').slice(1, 3).join(' ')
                    return acc + Number(value.trim()[0] * multiplier) +
                        numOfTotalBags(canHoldColor, counter, value.trim()[0]) * multiplier
                }
            }, 0)
        }
    }
    return counter
}
console.log(numOfTotalBags('shiny gold'))
