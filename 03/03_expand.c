#include <stdio.h>
#include <ctype.h>

void expand(char s1[], char s2[]);	/* Expands alphanumeric substrings of the form a-z to ab...yz. */
int is_shorthand(char s[], int i);	/* Checks for a valid expandable substring. */

int main() 
{
	char test[] = "-a-z0-9-2-3";
	char output[40];
	expand(test, output);
	printf("%s\n", output);
}

void expand(char s1[], char s2[])
{
	int i, j = 0;	
	char c, d;
	while ((c = s1[i]) != '\0') {
		if ((c == '-') && is_shorthand(s1, i)) {
			d = s1[i-1] + 1;		/* Note that we have already written s1[i-1]. */
			while (d != s1[i+1])	/* We leave s1[i+1] for the next loop iteration. */
				s2[j++] = d++;
		} else {
			s2[j++] = c;
		}
		i++;
	}
	s2[j] = '\0';
}

int is_shorthand(char s[], int i)
{
	if ((i==0) || (s[i+1]=='\0') || (s[i-1] > s[i+1]))
		return 0;
	if (isdigit(s[i-1]) && isdigit(s[i+1]))
		return 1;
	if (islower(s[i-1]) && islower(s[i+1]))
		return 1;
	if (isupper(s[i-1]) && isupper(s[i+1]))
		return 1;
	return 0;
}
