#include <stdio.h>

float convertCtoF(float);

main() 
{
    float cels, fahr;
	float start, stop, step;

	printf("====CELSIUS-FAHERENHEIT-CONVERSION====\n");

	start = -20;
	stop = 160;
	step = 10;

	cels = start;
	while (cels < stop) {
		fahr = convertCtoF(cels);
		printf("%6.0f\t%6.1f\n", cels, fahr);
		cels = cels + step;
	}
}

float convertCtoF(float cel)
{
	return (cel*(9.0/5.0))+32.0; 
}
