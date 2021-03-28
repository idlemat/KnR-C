#include <stdio.h>
#include <string.h>

void squeeze(char s1[], char s2[]);			/* Removes any characters present in s2 from s1. */
void get_uniques(char in[], char uniq[]);	/* Creates list of unique characters (uniq) from in. */
int contains(char list[], char c);			/* Checks for presence of c in list. */

int main() 
{
	char squeezer[] = "None of these...";
	char squeezed[] = "Nobody walked to the lighthouse.";
	squeeze(squeezed, squeezer);
	printf("%s\n", squeezed);
}

void squeeze(char s1[], char s2[])
{
	int i, j;
	char uniques[strlen(s2)];
	get_uniques(s2, uniques);
	for (i = j = 0; s1[i] != '\0'; i++)
		if (!contains(uniques, s1[i]))
			s1[j++] = s1[i];
	s1[j] = '\0';
}

void get_uniques(char in[], char uniq[])	/* Potentially better not to use; depends on s2. */
{
	uniq[0] = in[0];
	int k = 1;
	int m;
	while (in[k] != '\0') {
		m = 0;		
		while (in[k] != uniq[m]) {
			if (uniq[m] == '\0') {
				uniq[m] = in[k];
				break;
			}
			m++;
		}
		k++;
	}
}

int contains(char list[], char c) 
{
	int i = 0;
	while (list[i] != '\0') {
		if (list[i] == c)
			return 1;
		i++;
	}
	return 0;
}
