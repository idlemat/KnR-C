#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getdouble(double *pf);

int main()
{
	double f;
	int r = getdouble(&f);
	printf("%f, %d\n", f, r);
}

int getdouble(double *pn)
{
	int c, sign;
	while (isspace(c = getch()))	/* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*pn = 0; isdigit(c); c = getch()) {
		*pn = 10.0 * *pn + (c - '0');
	}
	
	int frac = 1;
	if (c == '.')
		while(isdigit(c = getch())) {
			frac *= 10.0;
			*pn += ((double) (c-'0'))/frac;
		}
		
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
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
