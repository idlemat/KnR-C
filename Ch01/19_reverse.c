#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
int len(char str[]);
void reverse(char line[], char rev[]);

main() 
{
	char line[MAXLINE];
	char enil[MAXLINE];
	int len;
	while ((len = getline(line, MAXLINE)) > 0) {
		reverse(line, enil);
		printf("%s\n", enil);
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

int len(char s[])
{
	int i;
	i = 0;
	while (s[i] != '\0')
		i++;
	return i - 1;
}

void reverse(char s[], char rvs[])
{
	int max;
	int i;
	max = len(s);
	i = 0;
	while (i <= max) {
		rvs[i] = s[max - i];
		++i;
	}
	rvs[i] = '\0';
	return;
}
