#include <stdio.h>

int main() 
{
	int nc = 0;
	char c;

	while ((c = getchar()) != EOF) {
		if ((c == ' ') | ( c == '\n' ) | (c == '\t')) {
			++nc;
		}
	}
	printf("%d\n", nc);
}

