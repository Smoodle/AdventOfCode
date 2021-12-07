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
* Day 7
*/

#include <limits.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PART 2

int find_max(int *array, size_t array_size) {
  int res = array[0];

  for (size_t i = 1; i < array_size; i++) {
	if (array[i] > res)
	  res = array[i];
  }

  return res;
}

void shortest_path(int *crabs, size_t crabs_size) {
  int min_cost = INT_MAX;

  for (int hor = 0; hor <= find_max(crabs, crabs_size); hor++) {

	int sum = 0;

	for (size_t cost = 0; cost < crabs_size; cost++) {

#if PART == 1
	  sum += abs(crabs[cost] - hor);
#else
	  for (int a = 0; a <= abs(crabs[cost] - hor); a++) {
		sum += a;
	  }
#endif
	}

	if (min_cost > sum)
	  min_cost = sum;
  }

  printf("Got %i;\n", min_cost);
}

int main() {

  char input[9999];
  scanf("%s", input);

  int *crabs;
  crabs = malloc(9999 * sizeof(int));
  size_t crab_size = 0;

  char *token;
  token = strtok(input, ",");

  while (token != NULL) {
	crabs[crab_size++] = atoi(token);

	token = strtok(NULL, ",");
  }

  shortest_path(crabs, crab_size);

  free(crabs);

  return 0;
}
