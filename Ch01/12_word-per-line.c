#include <stdio.h>

#define IN_SPACE 0
#define IN_WORD 1

int main()
{
  int c, s;

  where = IN_WORD; 
  while ((c = getchar()) != EOF)
	  if (c != ' ' && c != '\n' && c != '\t') {
		  putchar(c);
		  where = IN_WORD;
	  } else if (where == IN_WORD) {
		  putchar('\n');
		  where = IN_SPACE;
	  }
}
