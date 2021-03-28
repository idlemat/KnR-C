#include <stdio.h>
#include <limits.h>
#include <float.h>

void find_short_range(short[]);

int main() {
	/* Printing from standard headers. */
	printf("CHAR in range [%d, %d]\n", CHAR_MIN, CHAR_MAX);
	printf("UCHAR in range [%d, %d]\n", 0, UCHAR_MAX);
	printf("SHORT in range [%d, %d]\n", SHRT_MIN, SHRT_MAX);
	printf("USHORT in range [%d, %d]\n", 0, USHRT_MAX);
	printf("INT in range [%d, %d]\n", INT_MIN, INT_MAX);
	printf("UINT in range [%u, %u]\n", 0, UINT_MAX);
	printf("LONG in range [%ld, %ld]\n", LONG_MIN, LONG_MAX);
	printf("ULONG in range [%lu, %lu]\n", 0, ULONG_MAX);
	printf("\n");
	/* Print from computation. */
	short short_range[2];
	find_short_range(short_range);
	printf("SHORT calculated range [%d, %d]\n", short_range[0] , short_range[1]);
}

void find_short_range(short bounds[2])
{
	short k = 0;
	while (k <= 0) {
		k--;
	}
	bounds[0] = k+1;
	bounds[1] = k;
}
