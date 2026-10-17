#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void uniq(FILE *fp);

int main(int argc, char *argv[]) {
	if (argc > 2) { // checks if there is more than 2 arguments given
		printf("Too many arguments given!\n");
		return 0;
	}

	FILE *fp = stdin;
	if (argc == 2) { // checks if a filename was given so uses it instead of stdin
		fp = fopen(argv[1], "r");
		if (fp == NULL) { // makes sure the file is able to be read
			printf("Could not open file for reading!\n");
			return 0;
		}
	}

	uniq(fp);

	if (fp != stdin) { // closes fp incase the file wasn't stdin
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
	while (st != -1) { // runs until the end of the file
		// prints curr if first line or if curr and prev are different
		if (prev == NULL || strcmp(curr, prev)) {
			printf("%s", curr);
		}

		// swaps the buffer pointers without having them share the same address
		// also ensures no memory gets leaked by creating only 2 buffers
		char *temp = curr;
		curr = prev;
		prev = temp;
		
		// swaps the buffer sizes
		size_t tempSize = currSize;
		currSize = prevSize;
		prevSize = tempSize;

		st = getline(&curr, &currSize, fp);
	}
	// frees both buffers
	free(curr);
	free(prev);
}
