#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct nlist {       
	struct nlist *next;   
	char *name;           
	char *defn;           
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];  
struct nlist *install(char *name, char *defn);
struct nlist *lookup(char *s);
int undef(char *s);
char *strdup(char *);

int main() 
{
	char test_n[] = "WHAT";
	char test_d[] = "Snowy and dewish.";
	install(test_n, test_d);
	printf("%p\n", lookup(test_n));
	undef(test_n);
	printf("%p\n", lookup(test_n));
}

unsigned hash(char *s)
{
	unsigned hashval;
	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
	struct nlist *np;
	for (np = hashtab[hash(s)];  np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np;     
	return NULL;           
}

struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;
	if ((np = lookup(name)) == NULL) { 
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = strdup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else		 
		free((void *) np->defn);	
	 if ((np->defn = strdup(defn)) == NULL)
		return NULL;
	return np;
}

int undef(char *s)
{
	struct nlist *np, *prev;
	int first = 1;
	unsigned hs = hash(s);
	for (np = hashtab[hs];  np != NULL; np = np->next) {
		if (strcmp(s, np->name) == 0) {
			if (first) {
				hashtab[hs] = np->next;	
				free(np);
			} else {
				prev->next = np->next;			
				free(np);
			}
			return 1;     
		}
		if (first) first=0;
		prev = np;
	}
	return 0;           
}
