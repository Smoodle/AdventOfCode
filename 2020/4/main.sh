#!/bin/sh
cat "$1" | tr '\n' '~' | sed -e 's/~~/ \n/g' -e 's/~/ /g' |
    egrep 'byr:(19[2-9][0-9]|200[0-2]) ' |
    egrep 'iyr:(2020|201[0-9]) ' |
    egrep 'eyr:(2030|202[0-9]) ' |
    egrep 'hgt:((1[5-8][0-9]|19[0-3])cm|(59|6[0-9]|7[0-6])in) ' |
    egrep 'hcl:#[0-9a-f]{6} ' |
    egrep 'ecl:(amb|blu|brn|gry|grn|hzl|oth) ' |
    egrep 'pid:[0-9]{9} ' | 
    wc -l
