#include <stdio.h>
#include <string.h>
#include <ctype.h>

int htoi(char hex[]);		/* Converts a hex string to an integer. */
int hex_end(char[], int);	/* Checks if we have read all relevant parts of the string. */

int main()
{
	printf("%x\n", htoi("0xF8b5a5"));	/* Test input. */
}

int htoi(char hex[])
{
	int digit;
	int k = strlen(hex)-1;
	int out = 0x0;
	int order = 0x1;
	while (!hex_end(hex, k)) {
		if (isdigit(hex[k])) {
			digit = hex[k] - '0'; 
		} else {
			digit = 10 + toupper(hex[k]) - 'A';
		}			
		out += digit * order;
		order *= 0x10;
		k--;
	}
	return out;
}

int hex_end(char str[], int i)
{
	return ((i==-1) || (str[i] == 'x') || (str[i] == 'X'));
}
