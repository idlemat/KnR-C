#include <stdio.h>

int strindex(char s[], char t[]);

int main() 
{
	char str[] = "She's nobody's baby now.";
	char search[] = "no";
	printf("%d\n", strindex(str, search));
}

int strindex(char s[], char t[])
{
	int i, j, k;
	int out = -1;
	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			out = i;		/* We repeat until end of string. */
	}
	return out;
}
