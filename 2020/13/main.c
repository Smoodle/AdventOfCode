#include <stdio.h>
#include <stdbool.h>

int main() {
	unsigned int id;
	int numberValues[50];
	int numValuesCount = 0;

	char value[500];
	scanf("%d\n", &id); //Get number
	scanf("%s\n", value); //Get value

	// read only integers from the string and put them in a array
	int num, numToPush = 0, strLen = 0, length = 0;
	while( sscanf(&value[strLen], "%d,%n", &num, &length ) != EOF) {
		if(num != numToPush && length > 0) {
			numToPush=num;
			numberValues[numValuesCount++] = num;
			strLen+=length;
		}else {
			strLen+=2; 
			numberValues[numValuesCount++] = -1;
		} 

	}

	int diff = 9999;
	int shortestValue;
	for(int i = 0; i < numValuesCount; i++) {
		if(numberValues[i] != -1 && (numberValues[i] - (id%numberValues[i])) < diff) {
			shortestValue = numberValues[i];
			diff = numberValues[i] - (id%numberValues[i]);
		}
	}

	printf("Parte 1: %d\n", (shortestValue * ((id + diff) - id)));

	unsigned long long r = 0;
	unsigned long long a = 1;

	for(int i = 0; i < numValuesCount; i++) {
		if(numberValues[i] == -1)
			continue;

		while((r + i) % numberValues[i]) 
			r += a;

		a *= numberValues[i];
	}

	printf("Parte 2: %lld\n", r);
}
