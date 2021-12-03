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
* Day 3
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_SIZE 12
#define INPUT_SIZE 9999

long binary_string_to_decimal(char *in) {
  char *pEnd;
  return strtol(in, &pEnd, 2);
}

void most_common_p(char str[INPUT_SIZE][NUMBER_SIZE + 1], size_t str_size,
				   int *dest) {

  for (int i = 0; i < NUMBER_SIZE; i++)
	dest[i] = 0;

  for (size_t i = 0; i < str_size; i++) {
	for (int j = 0; j < NUMBER_SIZE; j++) {
	  if (str[i][j] == '0')
		dest[j]--;
	  else
		dest[j]++;
	}
  }
}

void filter_byte(char byte, int n, char str[INPUT_SIZE][NUMBER_SIZE + 1],
				 int *str_size) {
  int new_size = 0;

  for (int i = 0; i < *str_size; i++) {
	if (str[i][n] == byte) {
	  if (new_size == i)
			new_size++;
	  else
			strncpy(str[new_size++], str[i], NUMBER_SIZE + 1);
	}
  }

  *str_size = new_size;
}

void dup_string(char input[INPUT_SIZE][NUMBER_SIZE + 1],char dest[INPUT_SIZE][NUMBER_SIZE + 1], int size) {
  for(int i = 0; i < size; i++) {
	strcpy(dest[i], input[i]);
  }
}

int main() {
  char in[NUMBER_SIZE];
  int input_size = 0;
  static char input[INPUT_SIZE][NUMBER_SIZE + 1];

  while (scanf("%s", in) != EOF) {
	strncpy(input[input_size++], in, NUMBER_SIZE);
	input[input_size][NUMBER_SIZE] = '\0';
  }

  // Part 1:

  int counter[NUMBER_SIZE] = {0};
  most_common_p(input, input_size, counter);

  char most_common[NUMBER_SIZE + 1];
  char least_common[NUMBER_SIZE + 1];

  most_common[NUMBER_SIZE] = '\0';
  least_common[NUMBER_SIZE] = '\0';

  for (int i = 0; i < NUMBER_SIZE; i++) {
	if (counter[i] > 0) {
	  most_common[i] = '1';
	  least_common[i] = '0';
	} else {
	  most_common[i] = '0';
	  least_common[i] = '1';
	}
  }

  printf("Most common: %s , least common: %s \n", most_common, least_common);
  printf("Part 1: %ld \n", binary_string_to_decimal(most_common) *
							   binary_string_to_decimal(least_common));

  // Part 2

  static char oxygen[INPUT_SIZE][NUMBER_SIZE + 1];
  static char scrubber[INPUT_SIZE][NUMBER_SIZE + 1];
  int oxygen_size = input_size;
  int scrubber_size = input_size;
  int right = 0;

  dup_string(input, oxygen, input_size);
  dup_string(input, scrubber, input_size);

  while (oxygen_size != 1 && right < NUMBER_SIZE) {
	most_common_p(oxygen, oxygen_size, counter);

	if (counter[right] >= 0) {
	  filter_byte('1', right, oxygen, &oxygen_size);
	} else if (counter[right] < 0) {
	  filter_byte('0', right, oxygen, &oxygen_size);
    }

    right++;
  }

  right = 0;

  while (scrubber_size != 1 && right < NUMBER_SIZE) {
  	most_common_p(scrubber, scrubber_size, counter);

  	if (counter[right] >= 0) {
  	  filter_byte('0', right, scrubber, &scrubber_size);
  	} else if (counter[right] < 0) {
  	  filter_byte('1', right, scrubber, &scrubber_size);
    }

    right++;
  }

  printf("Oxygen: %s, Scrubber: %s\n", oxygen[0], scrubber[0]);
  printf("Part 2: %ld \n", binary_string_to_decimal(oxygen[0]) * binary_string_to_decimal(scrubber[0]));

  return 0;
}
