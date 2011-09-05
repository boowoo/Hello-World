#include <stdio.h>
#include "freqdict.h"
#include <stdlib.h>

FILE *openFile(char file_name[]){
	FILE *file = 0;

	printf("MOCK: calling openFile\n");

	if ((file = fopen(file_name, "r")) == NULL) {
		fprintf(stderr, "can't open file %s", file_name);
		exit(1);
	}
	return file;
}


char *getNextWord(FILE *file) {
	extern char next_word[];
	extern int ch;
	int i = 0;

	printf("MOCK: calling getNextWord\n");

	while (true) {
		ch = getc(file);
		if ((ch != '\n') && (ch != '\t') && (ch != ' ') && (ch != '\r'))
			next_word[i++] = ch;
		else {
			next_word[i] = '\0';
			return next_word;
		}
	}
}

void addWord(char *word) {
	printf("MOCK: calling addWord\n");
	printf("argumnt of addWord:%p\n", word);
}

void PrintDictionary() {
	printf("MOCK: calling PrintDictionary\n");
}
