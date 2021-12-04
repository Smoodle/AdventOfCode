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
* Day 4
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 5
#define INPUT_SIZE 9999

typedef struct Element {
  int x[BOARD_SIZE];
  int y[BOARD_SIZE];
  int marked_number[INPUT_SIZE];
  size_t marked_number_lenght;
} Element;

bool num_in_array(int num, int *arr, size_t arr_size) {
  for (size_t i = 0; i < arr_size; i++) {
	if (arr[i] == num)
	  return true;
  }

  return false;
}

int main() {
  size_t random_numbers_string_size = 0;
  char *random_numbers_string = NULL;

  int random_numbers[INPUT_SIZE] = {0};
  size_t random_numbers_size = 0;
  int boards[INPUT_SIZE][BOARD_SIZE][BOARD_SIZE];

  FILE *file;

  file = fopen("input", "r");

  free(random_numbers_string);

  // Parse random numbers
  getline(&random_numbers_string, &random_numbers_string_size, file);

  char *pt;
  pt = strtok(random_numbers_string, ",");

  while (pt != NULL) {
	random_numbers[random_numbers_size++] = atoi(pt);
	pt = strtok(NULL, ",");
  }

  // Parse boards
  size_t boards_size = 0;
  int y_counter = 0;

  while (fscanf(file, "%i %i %i %i %i", &boards[boards_size][0][y_counter],
				&boards[boards_size][1][y_counter],
				&boards[boards_size][2][y_counter],
				&boards[boards_size][3][y_counter],
				&boards[boards_size][4][y_counter]) != EOF) {

	if (++y_counter == BOARD_SIZE) {
	  y_counter = 0;
	  boards_size++;
	}
  }

  fclose(file);

  Element *marked = malloc(sizeof(Element) * boards_size + 1);

  for (size_t i = 0; i < boards_size; i++) {
	marked[i].marked_number_lenght = 0;

	for(int a = 0; a < BOARD_SIZE; a++) {
	  marked[i].x[a] = 0;
	  marked[i].y[a] = 0;
	}
  }

  bool bingo = false;
  int number_to_check;

  int boards_finished[boards_size * 2];
  size_t boards_finished_lenght = 0;

  int last_sum, last_num;

  for (size_t i = 0; i < random_numbers_size; i++) {
	number_to_check = random_numbers[i];

	for (size_t j = 0; j < boards_size; j++) {

	  if (num_in_array(j, boards_finished, boards_finished_lenght))
		continue;

	  for (size_t y = 0; y < BOARD_SIZE; y++) {
		for (size_t x = 0; x < BOARD_SIZE; x++) {
		  if (boards[j][x][y] == number_to_check) {
			marked[j].x[x]++;
			marked[j].y[y]++;
			marked[j].marked_number[marked[j].marked_number_lenght++] =
				number_to_check;
		  }
		}
	  }

	  for (size_t e = 0; e < BOARD_SIZE; e++) {
		if (marked[j].x[e] == BOARD_SIZE || marked[j].y[e] == BOARD_SIZE) {
		  int sum = 0;

		  for (size_t y = 0; y < BOARD_SIZE; y++) {
			for (size_t x = 0; x < BOARD_SIZE; x++) {
			  if (!num_in_array(boards[j][x][y], marked[j].marked_number,
								marked[j].marked_number_lenght))
				sum += boards[j][x][y];
			}
		  }

		  if (!bingo) {
			printf("First Board: \n");
			printf("Sum is: %i \n", sum);
			printf("last number: %i \n", number_to_check);
            printf("Part 1: %i \n\n", sum * number_to_check);

            bingo = true;
          }

		  last_sum = sum;
		  last_num = number_to_check;
          boards_finished[boards_finished_lenght++] = j;
        }
      }
    }
  }

  printf("Last Board: \n");
  printf("Sum is: %i \n", last_sum);
  printf("last number: %i \n", last_num);
  printf("Part 2: %i \n\n", last_sum * last_num);

  free(marked);

  return 0;
}
