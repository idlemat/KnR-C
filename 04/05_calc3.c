#include <stdio.h>
#include <stdlib.h>	
#include <math.h>		/* To implement math functions. */

#define MAXOP 100		
#define NUMBER '0'	 

int getop(char []);
void push (double);
double pop (void);
void wipe(void);
void ungetch(int c);

int main(void)
{
	int type;
	float store1, store2;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
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
		case '%':
			op2 = pop();
			if (op2 != 0.0)
				push((int) pop() % (int) op2);
			break;
		case '$':
			store1 = pop();
			store2 = pop();
			push(store1);
			push(store2);
			break;
		case '?':
			store1 = pop();
			printf("%f\n", store1);
			push(store1);
			break;
		case '!':
			wipe();
			break;
		case 's':	/* Math functions start here. */
			push(sin(pop()));
			break;
		case 'e':
			push(exp(pop()));
			break;
		case 'p':
			op2 = pop();
			push(pow(pop(), op2));
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}	
	return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, con't push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else
		{
			printf("error: stack empty\n");
			return 0.0;
		}
}

void wipe(void)
{
	while (sp > 0) {
		val[--sp] = 0;
	}
}

#include <ctype.h>

int getch(void);
void ingetch(int);

int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-')	
		return c;									

	i = 0;
	if (c == '-')
		if (!isdigit(s[++i] = c = getch())) {
			ungetch(c);
			return '-';	
		}

	if (isdigit(c) | c == '-')		
		while (isdigit(s[++i] = c = getch()))
			printf("%s\n", s);
	if (c == '.')								
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];	
int bufp = 0;				

int getch(void)			
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)	
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else buf[bufp++] = c;
}
