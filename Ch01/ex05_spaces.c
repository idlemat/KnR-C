#include <stdio.h>

main()
{
  int c, s;

  s = 0; 
  while ((c = getchar()) != EOF)
	  if (c != ' ') {
		  putchar(c);
		  s = 0;
	  } else if (s == 0) {
		  putchar(c);
		  s = 1;
	  }
}
