#include <stdio.h>
#include <stdarg.h>

int minprintf(char *fmt, ...);

int main()
{
	int k = minprintf("Here is the %dst %s\n", 1, "test.");
	minprintf("It printed %d characters.\n", k); 
}

int minprintf(char *fmt, ...)	/* Implemented the character count functionality. */
{
	va_list ap; 
	char *p, *sval;
	int ival;
	int count = 0;
	double dval;
	va_start(ap, fmt);
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			count++;
			continue;
		}
		switch (*++p) {
		case 'd':
			ival = va_arg(ap, int);
			count += printf("%d", ival);
			break;
		case 'f':
			dval = va_arg(ap, double);
			count += printf("%f", dval);
			break;
		case 's':
			for (sval = va_arg(ap, char *); *sval; sval++) {
				putchar(*sval);
				count++;
			}
			break;
		default:
			putchar(*p);
			count++;
			break;
		}
	}
	va_end(ap); 
	return count;
}
