#include <stdio.h>

#define SPACY 0
#define WORDY 1

main()
{
  int c, s;

  s = WORDY; 
  while ((c = getchar()) != EOF)
	  if (c != ' ' && c != '\n' && c != '\t') {
		  putchar(c);
		  s = WORDY;
	  } else if (s == WORDY) {
		  putchar('\n');
		  s = SPACY;
	  }
}
