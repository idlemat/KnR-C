#include <stdio.h> 
#include <string.h>
#include <limits.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main() {
	char out[15];
	itoa(-2147483648, out);
	printf("%s\n", out);
}

void itoa(int n, char s[])
{
	int i, sign; 
	int is_min = 0;

	if (n == INT_MIN) {
		is_min = 1;
		n++;
	}

	if ((sign = n) < 0)
		n = -n;
	
	i = 0;
	if (is_min) {
		s[i++] = n % 10 + '0' + 1;	/* We use the fact that INT_MIN is always even. */
		n /= 10;
	}
	do {		
		s[i++] = n % 10 + '0'; 
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
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
