#include <stdio.h>
#include <stdlib.h>

void sumDirections(char direction, int *horizontalValue, int *verticalValue, int value) {
	if(direction == 'E')
		*horizontalValue += value;
	else if(direction == 'W')
		*horizontalValue -= value;
	else if(direction == 'N')
		*verticalValue += value;
	else if(direction == 'S')
		*verticalValue -= value;
}

void rotate(char *facing, char direction, int value ) {
	char directions[] = {'N', 'E', 'S', 'W'};

	for(int i = 0; i != value; i+=90) {
		if(direction == 'R') {
			for(int i = 0; i < 4; i++) {
				if(directions[i] == *facing) {
					if(i == 3) *facing='N';
					else *facing = directions[i+1];
					break;
				}
			}
		} else {
			for(int i = 3; i > -1; i--) {
				if(directions[i] == *facing) {
					if(i == 0) *facing='W';
					else *facing = directions[i-1];
					break;
				}
			}
		}
	}
}

int main() {
	int number;
	char letter;

	char facing = 'E';
	int horizontal = 0, vertical = 0;

	while(scanf("%c%d\n",&letter, &number) != EOF) {
		switch(letter) {
			case 'N':
			case 'S':
			case 'E':
			case 'W':
				sumDirections(letter, &horizontal, &vertical, number);
				break;
			case 'L':
			case 'R':
				rotate(&facing, letter, number);
				break;
			case 'F':
				sumDirections(facing, &horizontal, &vertical, number);
				break;
		}
	}

	printf("Got horizontal: %i, vertical: %i\n", horizontal, vertical);
	printf("Part 1: %i\n", abs(vertical) + abs(horizontal));
}
