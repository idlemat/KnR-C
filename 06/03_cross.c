#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define MAXLINES 100

struct tnode							 
{
	char *word;							
	int count;							 
	int lines[MAXLINES];
	struct tnode *left;			
	struct tnode *right;		 
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

int current_line = 0;

int main(void)
{
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (word[0] == '\n') {
			current_line++;
		} else if (isalpha(word[0])) {
			root = addtree(root, word);
		} 
	treeprint(root);
	return 0;
}

struct tnode *talloc(void);
char *strdup(char *);

struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	if (p == NULL) {
		p = talloc();						
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
		(p->lines)[0] = current_line;
	} else if ((cond = strcmp(w, p->word)) == 0) {
		(p->lines)[p->count] = current_line;
		p->count++;							 
	} else if (cond < 0) {
		p->left = addtree(p->left, w);
	} else
		p->right = addtree(p->right, w);
	return p;
}

void treeprint(struct tnode *p)
{
	int i;
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\t\t", p->count, p->word);
		printf("LINES: %d", (p->lines)[0]);
		for ( i=1 ; i<(p->count) ; i++ )
			printf(", %d", (p->lines)[i]);
		printf("\n");
		treeprint(p->right);
	}
}

#include <stdlib.h>

struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup(char *s)		
{
	char *p;

	p = (char *) malloc(strlen(s)+1);	 
	if (p != NULL)
		strcpy(p, s);
	return p;
}


int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while ( (c = getch()) == ' ' || c == '\t' ) ;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
			*w = '\0';
			return c;
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}

#define BUFFSIZE 100

char buf[BUFFSIZE];	
int bufp = 0;				

int getch(void)			
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)	
{
	if (bufp >= BUFFSIZE)
		printf("ungetch: too many characters\n");
	else buf[bufp++] = c;
}
