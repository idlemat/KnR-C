#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main()
{
	int c = setbits(0b111011, 3, 3, 0b101000);
	/* We consider the right-most bit to be position 0. */
	/* We expect 0b110001 = 49. */
	printf("%d\n", c);
}

int setbits(int x, int p, int n, int y)
{
	int mask = ~(~0 << n);
	y &= mask;				/* Isolate substituting bits. */
	y <<= (p + 1 - n);
	mask <<= (p + 1 - n);
	x -= (x & mask);			/* Clear relevant digits. */
	x += y;					/* Fill in new digits. */
	return x;
}

