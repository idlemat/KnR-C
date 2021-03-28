#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qksort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);
int stcmp(char *s, char *t);

int fold = 0;	/* 1 for folded. */

int main(int argc, char *argv[])
{
	int nlines;
	int numeric = 0;
	if (argc > 1 && stcmp(argv[1], "-n") == 0)
		numeric = 1;
	if (argc > 1 && stcmp(argv[1], "-f") == 0)	/* Can't be both numeric and folded. */
		fold = 1;
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qksort((void**) lineptr, 0, nlines-1,
		 (int (*)(void*,void*))(numeric ? numcmp : stcmp));
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("input too big to sort\n");
		return 1;
	}
}

void qksort(void *v[], int left, int right, int(*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int, int);

	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for(i = left + 1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qksort(v, left, last - 1, comp);
	qksort(v, last + 1, right, comp);
}

#include <stdlib.h>

int numcmp(char *s1, char *s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

void swap(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

#define MAXLEN 1000	 
int getline(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0'; 
			strcpy(p, line);
			lineptr[nlines++] = p;\
		}
	return nlines;
}

int getline(char *s, int lim)
{
	int c, i;
	for (i = 0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

#define ALLOCSIZE 50000					 

static char allocbuf[ALLOCSIZE];	
static char *allocp = allocbuf;	 

char *alloc(int n)
{
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n;
	} else
		return 0;
}

void writelines(char *lineptr[], int nlines)
{
	int i;
	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

#include <ctype.h>

int stcmp(char *s, char *t)
{
	int eq(char *c1, char *c2);
	for ( ; eq(s, t); s++, t++) {
		if (*s == '\0')
			return 0;
	}
	if (!fold) return *s - *t;
	return tolower(*s) - tolower(*t);
}

int eq(char *c1, char *c2)
{
	if (!fold) return *c1 == *c2; 
	return tolower(*c1) == tolower(*c2);
}
