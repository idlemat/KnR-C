#include <stdio.h>

int main()
{
  int c, in_space;

  in_space = 0;
  while ((c = getchar()) != EOF) {
	  if (c != ' ') {
		  putchar(c);
		  in_space = 0;
	  } else if (!in_space) {
		  putchar(c);
		  in_space = 1;
	  }
  }
}
