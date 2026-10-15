#include<stdio.h>

void wc(FILE *fp);

int main(int argc, char *argv[]) {

	if (argc > 2) {
		printf("Too many arguments given!\n");
		return 0;
	}

	FILE *fp = stdin;
	if (argc == 2) {
		fp = fopen(argv[1], "r");
		if (fp == NULL) {
			printf("Could not open file for reading\n");
			return 0;
		}
	}
	
	wc(fp);
	
	if (fp != stdin) {
		fclose(fp);
	}
	
	return 0;
}

void wc(FILE *fp) {
	int ch = fgetc(fp);
	int charCount = 0;
	int wordCount = 0;
	int wsCheck = 1;
	int lineCount = 0;

	while (ch != EOF) {
		charCount++;

		int isSpace = (ch == ' ' || ch == '\t' || ch == '\n');
		if (isSpace && wsCheck == 0) {
			wsCheck = 1;
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
