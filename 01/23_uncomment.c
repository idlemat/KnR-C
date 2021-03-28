#include <stdio.h>

#define MAX_LENGTH 1000

int check_and_scan(char str[], int p);	/* Confirms if we are entering a comment and calls skip_comment if so. */
int skip_comment(char str[], int p);	/* Finds the end of the comment and skips to that position. */

int main() {
	int r_pos = 0;
	int w_pos = 0;

	char input[MAX_LENGTH] = "main() { \\* here is a comment *\\\n\tfunc1(); \\* and another *\\ \n}"; /* Test. */
	char output[MAX_LENGTH];
	while (input[r_pos] != '\0')	{
		if (input[r_pos] == '\\') {
			r_pos = check_and_scan(input, r_pos);
		} 
		output[w_pos] = input[r_pos];
		++r_pos;
		++w_pos;
	}
	printf("%s\n%s\n", input, output); 
	return 0;
}

int check_and_scan(char str[], int p) {
	if (str[p+1] == '*') {
		return skip_comment(str, p+2);
	} 
	return p;
}

int skip_comment(char str[], int p) {
	while (1) {
		if (str[p] == '*') {
			if (str[p+1] == '\\') {
				return p+2;
			}
		} 
		++p;
	}
}
