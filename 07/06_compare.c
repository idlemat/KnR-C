#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LEN 100

int main()
{
	FILE *fp1, *fp2;
	fp1 = fopen("06_lyre1", "r");
	fp2 = fopen("06_lyre2", "r");
	
	char line1[MAX_LEN], line2[MAX_LEN];
	int pos = 0;
	while (line1 != NULL) {
		if (NULL == fgets(line1, MAX_LEN, fp1))
			break;
		fgets(line2, MAX_LEN, fp2);
		if (strcmp(line1, line2)!=0) {
			printf("At line number %d we have:\n", pos);
			printf("FILE 1: %s\n", line1);
			printf("FILE 2: %s\n", line2);
			fclose(fp1);
			fclose(fp2);
			return 0;
		}
		pos++;
	}
	printf("Files are identical.\n");
	fclose(fp1);
	fclose(fp2);
}
