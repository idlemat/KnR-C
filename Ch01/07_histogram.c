#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_LEN 15

main()
{
	int c, i, j, state, counter;
	int counts[MAX_LEN];
	for (i = 0; i < MAX_LEN; ++i)
	   counts[i] = 0;

	state = IN;
	counter = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN) {
				++counts[counter];
				counter = 0;
				state = OUT;
			}
		} else {
			++counter;
			state = IN;
		}
	}

	for (i = 0; i < MAX_LEN; ++i) {
	    printf("%3d: ", i+1);
		for (j = 0; j < counts[i]; j++) {
			printf("#");
		} 
		printf("\n");
	}
}
