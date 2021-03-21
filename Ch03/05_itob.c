#include <stdio.h> 
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);
char digit_symbol(int n);	/* Returns appropriate digit/letter for given value. */

int main() {
	char out1[10];
	char out2[10];
	itob(253, out1, 2);
	itob(253, out2, 16);
	printf("%s\n", out1);	/* We expect 11111101. */
	printf("%s\n", out2);	/* We expect FD. */
}

void itob(int n, char s[], int b)
{
	int i, sign; 
	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {		
		s[i++] = digit_symbol(n % b); 
	} while ((n /= b) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

char digit_symbol(int n)
{
	if (n < 10) {
		return (n + '0');
	} else {
		return (n - 10 + 'A');
	}
}

void reverse(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
