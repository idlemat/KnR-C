#include <stdio.h>

int main(int argc, char *argv[])
{
	float x, y, z;
	char t;
	scanf("%f %f %c", &x, &y, &t);
	switch(t) {
		case '+':
			z = x + y;
			break;
		case '-':
			z = x - y;
			break;
		case '*':
			z = x * y;
			break;
		case '/':
			z = x / y;
			break;
		default:
			printf("error: unknown command %c\n", t);
			break;
	}
	printf("RESULT: %f\n", z);
}
