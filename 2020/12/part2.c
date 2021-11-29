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

void moveToWaypoint(int *boatHorizontal, int *boatVertical, int waypointHorizontal, int waypointVertical, int value) {
	*boatHorizontal += value * waypointHorizontal;
	*boatVertical += value * waypointVertical;
}

void rotateWaypoint(int *horizontal,int *vertical,char direction,int value) {
	int temp;
	for(int i = 0; i != value; i+=90) {
		if(direction == 'R') {
			if(*horizontal >= 0 && *vertical >= 0) {
				temp = *vertical;
				*vertical = -*horizontal;
				*horizontal = temp;
				continue;
			}

			if(*horizontal >= 0 && *vertical < 0) {
				temp = *horizontal;
				*horizontal = *vertical;
				*vertical = -temp;
				continue;
			}

			if(*horizontal < 0 && *vertical < 0) {
				temp = *vertical;
				*vertical = abs(*horizontal);
				*horizontal = temp;
				continue;
			}

			if(*horizontal < 0 && *vertical >= 0) {
				temp = *horizontal;
				*horizontal = *vertical;
				*vertical = abs(temp);
				continue;
			}

		} else {
			if(*horizontal >= 0 && *vertical >= 0) {
				temp = *horizontal;
				*horizontal = -*vertical;
				*vertical = temp;
				continue;
			}

			if(*horizontal < 0 && *vertical >= 0) {
				temp = *vertical;
				*vertical = *horizontal;
				*horizontal = -temp;
				continue;
			}

			if(*horizontal < 0 && *vertical < 0) {
				temp = *horizontal;
				*horizontal = abs(*vertical);
				*vertical = temp;
				continue;
			}

			if(*horizontal >= 0 && *vertical < 0) {
				temp = *vertical;
				*vertical = *horizontal;
				*horizontal = abs(temp);
				continue;
			}
		}
	}

}

int main() {
	int number;
	char letter;

	char facing = 'E';
	int shipHorizontal = 0, shipVertical = 0, waypointHorizontal = 10, waypointVertical = 1;

	while(scanf("%c%d\n",&letter, &number) != EOF) {
		switch(letter) {
			case 'N':
			case 'S':
			case 'E':
			case 'W':
				sumDirections(letter, &waypointHorizontal, &waypointVertical, number);
				break;
			case 'L':
			case 'R':
				rotateWaypoint(&waypointHorizontal,&waypointVertical, letter, number);
				break;
			case 'F':
				moveToWaypoint(&shipHorizontal, &shipVertical, waypointHorizontal, waypointVertical, number);
				break;
		}
	}

	printf("Got horizontal: %i, vertical: %i\n", shipHorizontal, shipVertical);
	printf("Part 2: %i\n", abs(shipHorizontal) + abs(shipVertical));
}

