#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int f;
	void filecopy(int from, int to);
	if (argc == 1) 
		filecopy(0, 1);
	else
		while(--argc > 0)
			if ((f = open(*++argv, O_RDONLY)) == -1) {
				printf("cat: can’t open %s\n", *argv);						
				return 1;
			} else {
				filecopy(f, 1);
				close(f);
			}
	return 0;
}

void filecopy(int from, int to)
{
	int b;
	char temp[1000];	/* We set th */
	while ((b = read(from, temp, 1000)) > 0)
		write(to, temp, b);
}
