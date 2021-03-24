#include <stdio.h>

#define swap(t, x, y) {t z = x; x = y; y = z;}

int main()
{
	int a = 0;
	int b = 1;
	printf("a:%d, b:%d\n", a, b);
	swap(int, a, b);
	printf("a:%d, b:%d\n", a, b);
}
