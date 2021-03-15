#include <stdio.h> 

#define MAX_WIDTH 10  /* Sets column width. */
#define MAX_LENGTH 1000

int split_line(char str[], int p);							/* Splits line by replacing an appropriate space with /n. Calls split_word if this is not possible. */
int split_word(char str[], int p);							/* Splits long words across lines with hyphens. */
int is_blank(char l);
void copy(char from[], char to[], int f_pos, int t_pos );	/* Copies 'from' to 'to' from the respective start positions. */

int main() {
	int r_pos = 0;
	char input[MAX_LENGTH] = "The very cool frog had a supervolume to examine."; /* Test. */
	while (r_pos != -1) {
		r_pos = split_line(input, r_pos);
	}
	printf("%s\n", input);
	return 0;
}

int split_line(char str[], int p) {
	int i = 0;
	int last_blank = -1; /* Tracks last available space at which to split. */
	while (i < MAX_WIDTH) {
		if (is_blank(str[p+i])) {
			last_blank = p+i;	
		} else if (str[p+i]=='\0') {
			return -1;
		}
		++i;
	} 
	if (last_blank == -1) {
		return split_word(str, p + MAX_WIDTH - 1);
	}
	str[last_blank] = '\n';
	return last_blank + 1;
}

void copy(char from[], char to[], int f_pos, int t_pos )
{
	char c;
	int i = 0;
	while ((c = from[f_pos+i]) != '\0') {
		to[t_pos+i] = from[f_pos+i];
		++i;
	}
}

int split_word(char str[], int p)
{
	char store[MAX_LENGTH];
	char c;
	copy(str, store, p, 0);

	str[p] = '-';
	str[p+1] = '\n';
	str[p+2] = '-';
	
	copy(store, str, 0, p+3);
	return p+2;
}

int is_blank(char l) 
{
	return ((l == ' ') || (l == '\t') || (l == '\n'));
}
