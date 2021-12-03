//     _       _                 _            __    ____          _
//    / \   __| |_   _____ _ __ | |_    ___  / _|  / ___|___   __| | ___
//   / _ \ / _` \ \ / / _ \ '_ \| __|  / _ \| |_  | |   / _ \ / _` |/ _	\
//  / ___ \ (_| |\ V /  __/ | | | |_  | (_) |  _| | |__| (_) | (_| |  __/
// /_/   \_\__,_| \_/ \___|_| |_|\__|  \___/|_|    \____\___/ \__,_|\___|
//
//  ____   ___ ____  _
// |___ \ / _ \___ \/ |
//   __) | | | |__) | |
//  / __/| |_| / __/| |
// |_____|\___/_____|_|
//
// Day 2

#include <stdio.h>
#include <string.h>

int main() {

  char *str;
  int val;

  int horizontal = 0, depthPart1 = 0, depthPart2 = 0, aim = 0;

  while (scanf("%s %i", str, &val) != EOF) {

	if (strcmp(str, "forward") == 0) {
	  horizontal = horizontal + val;
	  depthPart2 = depthPart2 + (aim * val);
	}

	if (strcmp(str, "up") == 0) {
	  depthPart1 = depthPart1 - val;
	  aim = aim - val;
	}

	if (strcmp(str, "down") == 0) {
	  aim = aim + val;
	  depthPart1 = depthPart1 + val;
	}
  }

  printf("Part 1: %i, Part 2: %i\n\n", horizontal * depthPart1,
		 horizontal * depthPart2);

  return 0;
}
