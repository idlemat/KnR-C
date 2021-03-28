#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK 50
#define NUMBER '0'

float stack[MAX_STACK];
float *sp = stack;

float pop();
void push(float x);
char getop(char op[]);

int main(int argc, char *argv[])
{
	char c;
	int i, op2 = 0;
	while (++i < argc) {			/* Loop through arguments. */
		char t = getop(argv[i]);	/* Analogous to previous versions. */
		switch(t) {
		case NUMBER:
			push(atof(argv[i]));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '*':
			push(pop() * pop());
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			break;
		default:
			printf("error: unknown command %d%s\n", i, argv[i]);
			break;
		}
	}

	if (--sp == stack) {
		printf("RESULT: %f\n", *sp);
	} else {
		printf("Computation did not end with a single result.\n");
	}
}

void push(float x)	/* Pointer versions. */
{
	*sp++ = x;
}

float pop()
{
	return *(--sp);
}

char getop(char op[])
{
	if (isdigit(op[0]))
		return NUMBER;
	return op[0];	/* Only accept single-character operators. */
}
