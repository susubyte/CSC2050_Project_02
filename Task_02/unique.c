#include<stdio.h>

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
}
