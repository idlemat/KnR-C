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
	char input[MAXLINE] = {'A','B','C','D','\t','A','\n','B','C','\t','A','B','\t','e','n','d','.'};
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
	int i, j;
	i = j = 0;

	while ( i<TAB_WIDTH ) {
		if ( str[r_pos+i] == '\t' ) {
			break;
		} else if ( str[r_pos+i] == '\n' ) {
			chunk[i] = str[r_pos+i];
			return r_pos + i + 1;
		} else {
			chunk[i] = str[r_pos+i];
			++i;
		}
	}
	while ( i+j<TAB_WIDTH ) {
		chunk[i+j] = ' ';
		++j;
	}
	if (str[r_pos + i] == '\0')
		finished = 1;

	return r_pos + i + 1;
}

int write_chunk_to_out(char str[])
{
	int i = 0;
	while (i <= TAB_WIDTH) {
		str[w_pos + i] = chunk[i];
		if (str[w_pos + i] == '\n') {
			++i;
			str[w_pos + i] == '\0';
			return w_pos + i;
		}
		++i;
	}
	return w_pos + TAB_WIDTH; 
}
