#include <stdio.h>

int bitcount(int x);	

int main() 
{
	int y = 0b1011011;
	printf("%d\n", bitcount(y));	/* We expect 5. */
}

int bitcount(int x)	/* Assume x != 0. */
{
	int i = 0;
	while (x != 0) {
		x &= (x-1);	/* Removes rightmost 1-bit. */
		i += 1;
	}
	return i;
}
