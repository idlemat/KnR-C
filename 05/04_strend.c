#include <stdio.h>

int strend(char *s, char *t);

int main() 
{
	char head[] = "Hail time.";
	char tail1[] = "time.";
	char tail2[] = "place.";
	printf("%d\n%d\n", strend(head, tail1), strend(head, tail2)); 
}

int strend(char *s, char *t)
{
	int i = 0;
	while (*s) s++;			/* Go to /0 */
	while (*(t + i)) i++;	/* Go to /0 */
	while (--i != -1) {		/* Check backwards from end. */
		if (*(--s) != *(t + i)) 
			return 0;
	}
	return 1;
}
