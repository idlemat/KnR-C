#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
int remove_trailing_spaces(char line[], int len);

main() 
{
	char line[MAXLINE];
	int len;
	while ((len = getline(line, MAXLINE)) > 0)
	    if (remove_trailing_spaces(line, len) == 1) {
			printf("%s\n", line);
	    }
	return 0;
}

int getline(char s[],int lim)
{
	int c, i;
	for ( i = 0; (c=getchar())!=EOF && c!='\n'; ++i)
		if (i < lim-1)
			s[i] = c;
	if (c == '\n') {
	    s[i] = c;
	    ++i;
	}
	s[i] = '\0';
	return i;
}

int remove_trailing_spaces(char s[], int k)
{
	--k;
	while (k > -1)
		if (s[k]==' ' || s[k]=='\t' || s[k]=='\n') {
			s[k]='\0';
			--k;
		} else { 
			return 1; // indicates that line isn't blank
		}
	return 0; // indicates that line is blank
}
