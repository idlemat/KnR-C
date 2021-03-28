#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int get_chunk(char str[]);
int write_chunk_to_out(char str[]);

int r_pos = 0;	
int w_pos = 0;
int t_width = 5;	/* Default. */
int t_start = 0;	/* Default. */
int finished = 0;
char chunk[50];		/* The maximum tab width is 50. */
	
int main(int argc, char *argv[])	/* Broadly similar to first version. */
{
	char c;
	while (--argc > 0) {
		switch (c = (*++argv)[0]) {
		case '-':
			t_width = -atoi(*argv);
			break;
		case '+':
			t_start = atoi(*argv);
			break;
		default:
			printf("Invalid options; need entab -m +n only");
			return 0;
		}
	}

	char input[MAXLINE] = "Now       you're\n       lost\nand       you're\n       lethal.";
	char output[MAXLINE];

	while (t_start-- > 0)
		output[w_pos++] = ' ';

	chunk[t_width + 1] = '\0';
	while (!finished) {
		r_pos = get_chunk(input);
		w_pos = write_chunk_to_out(output);
	}
	printf("%s\n", output);
}

int get_chunk(char str[])
{
	int i, in_space, space_start;
	i = in_space = space_start = 0; 

	while ( i<t_width ) {
		if (str[r_pos+i] == '\n') {
			chunk[i] = '\n';
			chunk[i+1] = '\0';
			return r_pos + i + 1;
		}
		if ((in_space == 0) && (str[r_pos+i] == ' ')) {
			in_space = 1;
			space_start = i; 
		} else if ((in_space == 1) && (str[r_pos+i] != ' ')) {
			in_space = 0;
		}
		chunk[i] = str[r_pos+i];
		++i;
	}

	if (in_space == 1) {
		chunk[space_start] = '\t';
		chunk[space_start + 1] = '\0';
	}

	if (str[r_pos + i] == '\0')
		finished = 1;

	return r_pos + i;
}

int write_chunk_to_out(char str[])
{
	int i = 0;
	while ( i<t_width ) {
		if (chunk[i] == '\0')
			break;
		str[w_pos+i] = chunk[i];
		++i;
	}
	str[w_pos+i] = '\0'; 
	return w_pos + i;
}
