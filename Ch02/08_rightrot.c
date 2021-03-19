#include <stdio.h>

int rightrot(int x, int n);
int bitlength(int x);	

int main() 
{
	int y = 0b1011011;
	printf("%d\n", rightrot(y, 3));	/* We expect 0b111011 = 59. */
}

int rightrot(int x, int n)
{
	int mask = ~(~0 << n);
	x = ((x & mask) << (bitlength(x) - n)) + (x >> n); 
	return x;
}

int bitlength(int x)	/* Assume x != 0. */
{
	int i = 0;
	while ((1<<i) < x)
		i += 1;
	return i;
}
