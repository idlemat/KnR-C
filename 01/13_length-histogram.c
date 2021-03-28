#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_LEN 15

int main()
{
	int c, i, j, state, counter;
	int counts[MAX_LEN]; /* Counts words of length i in position i-1 */
	for (i = 0; i < MAX_LEN; ++i)
	   counts[i] = 0;

	state = IN; /* Assume that we do not start with a blank */
	counter = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN) {
				++counts[counter - 1];
				counter = 0;
				state = OUT;
			}
		} else {
			++counter;
			state = IN;
		}
	}
	
	printf("\n\n");
	for (i = 0; i < MAX_LEN; ++i) { /* Plotting horizontal histogram. */
	    printf("%3d: ", i+1);
		for (j = 0; j < counts[i]; j++) {
			printf("#");
		} 
		printf("\n");
	}
	printf("\n");

}
