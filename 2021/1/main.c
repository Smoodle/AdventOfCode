#include <stdio.h>

int main () {

	//Part 1
	int next = 0;
	int prev = -1;
	int counter = 0;

	//Part 2
	int arraySize = 0;
	int input[9999];
	int counter2 = 0;

	while(scanf("%i", &next) != EOF) {
		//Part 2
		input[arraySize] = next;
		arraySize ++;

		//Part 1
		if(prev == -1) {
			prev = next;
			continue;
		}

		if (next > prev) counter++;
		prev = next;

	}

	int prevSum = -1;
	int nextSum = 0;
	int checkCounter = 0;

	//Part 2
	for(int i = 0; i < arraySize; i++) {
		if(checkCounter == 1 && i+1 < arraySize) {
			nextSum = input[i-1] + input[i] + input[i+1];

			if(prevSum != -1 && nextSum > prevSum) counter2++;

			prevSum = nextSum;
			checkCounter = 0;
		}

		checkCounter++;
	}

	printf("Part 1 is: %d\nPart 2 is: %d\n", counter, counter2);

	return 0;
}
