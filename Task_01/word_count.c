#include<stdio.h>

void wc(FILE *fp);

int main(int argc, char *argv[]) {
	if (argc > 2) { // makes sure there isn't extra arguments given
		printf("Too many arguments given!\n");
		return 0;
	}

	FILE *fp = stdin;
	if (argc == 2) { // checks if a file name was given so uses it instead of stdin
		fp = fopen(argv[1], "r");
		if (fp == NULL) { // makes sure the file is able to be read
			printf("Could not open file for reading\n");
			return 0;
		}
	}
	
	wc(fp);
	
	if (fp != stdin) { // closes fp incase the file wasn't stdin
		fclose(fp);
	}
	
	return 0;
}

void wc(FILE *fp) {
	int ch = fgetc(fp);
	int charCount = 0;
	int wordCount = 0;
	int wsCheck = 1; // used to recollect if the previous character was a whitespace
	int lineCount = 0;

	while (ch != EOF) { // runs until the end of the file
		charCount++;

		// checks if on a whitespace
		int isSpace = (ch == ' ' || ch == '\t' || ch == '\n');
		// runs if currently on a first whitespace
		if (isSpace && wsCheck == 0) {
			wsCheck = 1;
			// else if runs if on the first non-whitespace
		} else if (!isSpace && wsCheck == 1) {
			wsCheck = 0;
			wordCount++;
		}

		if (ch == '\n') {
			lineCount++;
		}

		ch = fgetc(fp);
	}

	printf("%d %d %d\n", lineCount, wordCount, charCount);
}
