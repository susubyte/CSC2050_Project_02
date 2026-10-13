#include<stdio.h>

int main(int argc, char *argv[]) {

	if (argc < 3) {
		printf("Too many or too little arguments given.\n");
		return 0;
	}
	char *filename = argv[1];

	FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("Could not open file for reading");
		return 0;
	}

	int ch = fgetc(fp);
	int charCount = 0;
	int wordCount = 0;
	int wsCheck = 0;
	int lineCount = 0;

	while (ch != EOF) {
		charCount++;

		if ((ch == ' ' || ch == '\t' || ch == '\n') && wsCheck == 0) {
			wsCheck = 1;
		} else if (ch != ' ' && ch != '\t' && ch != '\n' && wsCheck == 1) {
			wsCheck = 0;
			wordCount++;
		}

		if (ch == '\n') {
			lineCount++;
		}

		ch = fgetc(fp);
	}

	fclose(fp);

	printf("%d\t%d\t\%d\t%s\n", charCount, wordCount, lineCount, filename);

	return 0;
}
