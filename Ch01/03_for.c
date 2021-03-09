#include <stdio.h>

#define START 0
#define STOP 300
#define STEP 20

main() {
  int fahr;

  for (fahr = START; fahr <= STOP; fahr = fahr + STEP) {
	  printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32.0));
  }
}
