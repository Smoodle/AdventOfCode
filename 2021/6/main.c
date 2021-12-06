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
* Day 6
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lanternfish {
  int timer;
} Lanternfish;

void simulate_time_old(int days, Lanternfish *fish, long long *fish_size,
				   long long *max_array_size) {

  int fish_to_add;

  for (int i = 0; i < days; i++) {
	fish_to_add = 0;

	for (long long j = 0; j < *fish_size; j++) {

	  if (fish[j].timer == 0) {
		fish[j].timer = 6;
		fish_to_add++;
	  } else
		fish[j].timer--;
	}

	for (int f = 0; f < fish_to_add; f++) {
	  Lanternfish lf = {8};
	  fish[*fish_size] = lf;
	  *fish_size = *fish_size + 1;
	}
  }

  printf("FINAL FISH size: %lld;\n", *fish_size);
}

void simulate_time_new(int days, Lanternfish *fish, long long fish_size) {
  long long counter[9] = {0};

  for (int a = 0; a < fish_size; a++) {
	counter[fish[a].timer]++;
  }

  long long day_zero_count = 0;
  for (int day = 0; day < days; day++) {
	day_zero_count = counter[0];

	for (int a = 0; a < 8; a++) {
	  counter[a] = counter[a+1];
	}

	counter[8] = day_zero_count;
	counter[6] += day_zero_count;
  }

  long long sum = 0;
  for (int a = 0; a < 9; a++) {
	sum += counter[a];
  }

  printf("Got %lld \n", sum);
}

int main() {
  char *pt;
  char input_string[1000];

  long long max_array_size = 999;

  Lanternfish *input;
  input = malloc(max_array_size * sizeof(Lanternfish));

  long long input_size = 0;

  scanf("%s", input_string);

  pt = strtok(input_string, ",");

  while (pt != NULL) {
	int num = atoi(pt);
	Lanternfish l = {num};
	input[input_size++] = l;

	pt = strtok(NULL, ",");
  }

  simulate_time_new(256, input, input_size);

  free(input);

  return 0;
}
