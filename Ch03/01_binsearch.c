#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
	int list[] = {1, 4, 7, 9, 13, 123, 1298, 5474, 123120};
	printf("%d\n", binsearch(123, list, 9));
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while ((low <= high) && (v[mid] != x)) {
	   mid = (low+high)/2;
	   if (x < v[mid])
		   high = mid - 1;
	   else 
		   low = mid + 1;
	}

	if (v[mid] == x)
		return mid;

    return -1;
}
