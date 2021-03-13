#include <stdio.h>

#define TAB_WIDTH 8
#define MAXLINE 1000

int get_chunk(char str[]);
int write_chunk_to_out(char str[]);

int r_pos = 0;	
int w_pos = 0;
int finished = 0;
char chunk[TAB_WIDTH + 1];
	
main()
{
	char input[MAXLINE] = {'A','B','\n','C','D',' ',' ',' ',' ',' ',' ','B','C'};
	char output[MAXLINE];
	chunk[TAB_WIDTH + 1] = '\0';
	
	while (finished != 1) {
		r_pos = get_chunk(input);
		w_pos = write_chunk_to_out(output);
	}
	printf("%s\n%s\n", input, output);
}

int get_chunk(char str[])
{
	int i, in_space, space_start;
	i = in_space = space_start = 0;

	while ( i<TAB_WIDTH ) {
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
	while ( i<TAB_WIDTH ) {
		if (chunk[i] == '\0')
			break;
		str[w_pos+i] = chunk[i];
		++i;
	}
	str[w_pos+i] = '\0'; 
	return w_pos + i;
}
