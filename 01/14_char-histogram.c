#include <stdio.h>

#define IN 1
#define OUT 0
#define LEN 26 

int main()
{
	int i, j, c, max;
	int letters[LEN]; /* Stores counter for i-th letter in (i-1)-th position. */
	for (i = 0; i < LEN; ++i)
		letters[i] = 0;

	while ((c = getchar()) != EOF) 
		if ( c >= 'A' && c <= 'Z') { /* Ignoring case. */
			++letters[c - 'A'];
		} else if ( c >= 'a' && c <= 'z' ) {
			++letters[c - 'a'];
		} 
	
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

	max = 0; /* Vertical histogram. */
	for (i = 0; i < LEN; ++i)
		if (max < letters[i]) 
			max = letters[i];

	for (j = max; j > 0; --j) {
		for (i = 0; i < LEN; ++i)
			if (letters[i] >= j) {
				printf("%c ", '#');
			} else {
				printf("  ");
			}
		printf("\n");
	}

	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	
	for (i = 0; i < LEN; ++i)
			printf("%c ", 'a' + i);

	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}
