/*     _       _                 _            __    ____          _
*     / \   __| |_   _____ _ __ | |_    ___  / _|  / ___|___   __| | ___
*    / _ \ / _` \ \ / / _ \ '_ \| __|  / _ \| |_  | |   / _ \ / _` |/ _	\
*   / ___ \ (_| |\ V /  __/ | | | |_  | (_) |  _| | |__| (_) | (_| |  __/
*  /_/   \_\__,_| \_/ \___|_| |_|\__|  \___/|_|    \____\___/ \__,_|\___|
*
*   ____   ___ ____  _
*  |___ \ / _ \___ \/ |
*    __) | | | |__) | |
*   / __/| |_| / __/| |
*  |_____|\___/_____|_|
*
* Day 5
*/

#include <stdio.h>
#define GRID_SIZE 1000
#define PART 1

int main() {
  int x1, y1, x2, y2;

  int matrix[GRID_SIZE][GRID_SIZE] = {0};

  while (scanf("%i,%i -> %i,%i", &x1, &y1, &x2, &y2) != EOF) {
	if (x1 == x2) {
	  for (int y = y1; y != y2; y < y2 ? y++ : y--) {
		matrix[x1][y]++;
	  }
	  matrix[x1][y2]++;
	} else if (y1 == y2) {
	  for (int x = x1; x != x2; x < x2 ? x++ : x--) {
		matrix[x][y1]++;
	  }
	  matrix[x2][y1]++;
	}
#if PART == 2
	else {
	  while (x1 != x2 || y1 != y2) {
		matrix[x1][y1]++;

		if (x1 > x2)
		  x1--;
		else if (x1 < x2)
		  x1++;

		if (y1 > y2)
		  y1--;
		else if (y1 < y2)
		  y1++;
	  }

	  matrix[x2][y2]++;
	}
#endif
  }

  int counter = 0;
  for (int x = 0; x < GRID_SIZE; x++) {
	for (int y = 0; y < GRID_SIZE; y++) {
	  if (matrix[x][y] >= 2)
		counter++;
	}
  }

  printf("Got counter %i\n", counter);

  return 0;
}
