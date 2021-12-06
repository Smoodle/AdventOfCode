#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lanternfish {
  int timer;
} Lanternfish;

void print_fish(Lanternfish *fish, long long fish_size) {
  for(long long i = 0; i < fish_size; i++) {
	printf("%i ", fish[i].timer);
  }

	printf("\n ");
}

void simulate_time(int days, Lanternfish *fish, long long *fish_size, long long *max_array_size) {
  printf("FIRST size: %lld;\n", *fish_size);

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
	  if(*max_array_size == *fish_size - 1) {
	  	fish = realloc(fish, *max_array_size * 2 * sizeof(Lanternfish));
	  	*max_array_size = *max_array_size * 2;
	  }

	  Lanternfish lf = {8};
	  fish[*fish_size] = lf;
	  *fish_size = *fish_size + 1;
	}
  }

  printf("FINAL FISH size: %lld;\n", *fish_size);
  print_fish(fish, *fish_size);
}


int main() {
  char *pt;
  char input_string[1000];

  long long max_array_size = 1000;


  Lanternfish *input;
  input = malloc(max_array_size * sizeof(Lanternfish));

  long long input_size = 0;

  scanf("%s", input_string);

  pt = strtok(input_string, ",");

  while (pt != NULL) {
	int num = atoi(pt);
	Lanternfish l = { num };
	input[input_size++] = l;

	pt = strtok(NULL, ",");
  }

  print_fish(input, input_size);

  printf("Fish size: %lld\n", input_size);

  simulate_time(80, input, &input_size, &max_array_size);

  printf("Fish size: %lld\n", input_size);

  print_fish(input, input_size);

  free(input);

  return 0;
}
