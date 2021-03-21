#include <stdio.h> 
#include <string.h>

void itoa(int n, char s[], int pad);
void reverse(char s[]);

int main() {
	char out1[20], out2[20], out3[20]; 
	itoa(12, out1, 6);
	itoa(289, out2, 6);
	itoa(-299, out3, 6);
	printf("%s\n", out1);
	printf("%s\n", out2);
	printf("%s\n", out3);
}

void itoa(int n, char s[], int pad)
{
	int i, sign; 
	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {		
		s[i++] = n % 10 + '0'; 
		pad--;
	} while ((n /= 10) > 0);
	if (sign < 0) {
		s[i++] = '-';
		pad--;
	}
	while (pad > 0) {
		s[i++] = ' ';
		pad--;
	}
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
