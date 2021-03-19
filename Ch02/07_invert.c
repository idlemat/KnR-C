#include <stdio.h>

int invert(int x, int p, int n);

int main() 
{
	int y = 0b1011011;
	printf("%d\n", invert(y, 4,3));	/* We expect 0b1000111 = 71. */
}

int invert(int x, int p, int n)
{
	int mask = ~(~0 << n) << (p + 1 - n);
	x = (mask ^ x);	/* XOR negates at masked positions. */
	return x;
}
