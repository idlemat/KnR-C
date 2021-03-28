#include <stdio.h>

int strindex(char *s, char *t);

int main() 
{
	char str[] = "She's nobody's baby now.";
	char search[] = "no";
	printf("%d\n", strindex(str, search));
}

int strindex(char *s, char *t)
{
	int i = 0;
	int j = 0;
	int k = -1;

	while (*(s + i)) {				/* While not at the end of s. */
		if (*(s + i++) == *t) {		/* Check for matches. */
			t++; j++;				/* Move along for match. */
			if (!*t) {
				k = i-j;			/* Reset and store complete match. */
				t -= j;
				j = 0;
			}
		} else {
			t -= j;					/* Reset for no match. */
			j = 0;
		}
	}
	return k;
}
