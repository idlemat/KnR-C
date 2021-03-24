#include <ctype.h>
#include <math.h>
#include <stdio.h>

double atof(char s[]);

int main()
{
	char input1[] = "23.99e3";	
	char input2[] = "6120111239E-11";	
	printf("%f\n", atof(input1));
	printf("%f\n", atof(input2));
}

double atof(char s[])
{
	double val, power;
	int i, sign;
	for (i = 0; isspace(s[i]); i++)  /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	if ((s[i] == 'e') | (s[i] == 'E')) {	/* Check for optional exponent. */
		int e_sign = 1;
		int e_val = 0;
		if (s[++i] == '-') {
			e_sign = -1;
			i++;
		}
		while (s[i] != '\0') {
			e_val = 10 * e_val + (s[i] - '0'); 
			i++;
		}	
		return ((sign * val / power) * pow(10, e_sign*e_val));
	}
	
	return sign * val / power;
}
