#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Memories {
	unsigned long mask : 36;
} Memory;

int main() {
	char action[500];
	char value[500];

	while(scanf("%s = %s\n", action, value) != EOF) {
		if(strcmp(action, "mask") == 0) {
			Memory m;
			m.mask = 0;

			for(int i = 0; i < 36; i++ ) {
				if(value[i] == 'X') value[i] = '0';
			}

			m.mask = strtol(value, NULL, 10);
			printf("%ld\n", m.mask);
		}


		printf("%s - %s\n", action, value);

	}
}
