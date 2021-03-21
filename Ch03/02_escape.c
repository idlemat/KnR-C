#include <stdio.h>

void escape(char s[], char t[]);

int main()
{
	char visible[] = "howling, as of a hen-yard in a printing-house,\\n\\tthe clatter of presses,"; 
	char output[80];
	escape(output, visible);
	printf("%s\n", output);
}

void escape(char s[], char t[])
{
	char c;
	int i, j;
	i = j = 0;
	while ((c = t[i++]) != '\0') {
		switch (c) {
		case '\n':
			s[j++] = '\\';
			s[j++] = 'n';
			continue;
		case '\t':
			s[j++] = '\\';
			s[j++] = 't';
			continue;
		default:
			s[j++] = c;
			continue;
		}
	}
	s[j] = '\0'; 
}
