#! /bin/bash

#Part 1
vals=$(while read -r line; do echo $((2#`echo $line | tr FBLR 0101`)); done < input.txt | sort -rn)
echo "Max is: $(echo "$vals" | head -1)"

#Part 2
#lastNum=""
#
#for i in "$vals"
#do
#	if [ -z "$lastNum" ]; then
#		lastNum="$i"
#	fi
#
#	diff=$(($lastNum-$i))
#
#	if [ $diff -ne 1 ]; then
#		echo "My number is $i"
#	fi
#
#	lastNum="$i"
#done
#
