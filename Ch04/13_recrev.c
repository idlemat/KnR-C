#include <stdio.h>
#include <string.h>

void reverse(char s[], int i, int j);	/* Reverse the substring from index i to j. */

int main()
{
	char test[] = "totallyactually";
	int len = strlen(test);
	reverse(test, 0, len-1);
	printf("%s\n", test);	
}

void reverse(char s[], int i, int j)
{
	char store = s[i];
	s[i] = s[j];
	s[j] = store;
	if (j - i > 2)
		reverse(s, i+1, j-1);
}
