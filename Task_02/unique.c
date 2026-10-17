#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void uniq(FILE *fp);

int main(int argc, char *argv[]) {
	if (argc > 2) {
		printf("Too many arguments given!\n");
		return 0;
	}

	FILE *fp = stdin;
	if (argc == 2) {
		fp = fopen(argv[1], "r");
		if (fp == NULL) {
			printf("Could not open file for reading!\n");
			return 0;
		}
	}

	uniq(fp);

	if (fp != stdin) {
		fclose(fp);
	}
	
	return 0;
}

void uniq(FILE *fp) {
	char *curr = NULL;
	size_t currSize = 0;
	char *prev = NULL;
	size_t prevSize = 0;

	ssize_t st = getline(&curr, &currSize, fp);
	while (st != -1) {
		if (prev == NULL || strcmp(curr, prev)) {
			printf("%s", curr);
		}

		char *temp = curr;
		curr = prev;
		prev = temp;
		
		size_t tempSize = currSize;
		currSize = prevSize;
		prevSize = tempSize;

		st = getline(&curr, &currSize, fp);
	}
	free(curr);
	free(prev);
}
