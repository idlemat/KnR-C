#include <stdio.h>

void strcatp(char *s, char *t);

int main() 
{
	char head[] = "Hail ";
	char tail[] = "time.";
	strcatp(head, tail);
	printf("%s\n", head); 
}

void strcatp(char *s, char *t)
{
	while (*s) s++;					/* Go to end. */
	while (*s++ = *t++) ;			/* Copy including \0 */
}
