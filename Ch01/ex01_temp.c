#include <stdio.h>

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
		fahr = (cels*(9.0/5.0))+32.0;
		printf("%3.0f\t%6.1f\n", cels, fahr);
		cels = cels + step;
	}
}
