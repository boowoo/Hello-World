#include <stdio.h>
#include <stdlib.h>
#include "freqdict.h"
int ch;
char next_word[MAX_WORD];

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
	int i = 0;

	printf("MOCK: calling getNextWord\n");

	//next_word = (char*) malloc(50);
	while (true) {
		ch = getc(file);
		if (ch == EOF)
			exit(1);
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
	printf("argumnt of addWord:%s\n", word);
}

void PrintDictionary( struct dict dic) {
	printf("MOCK: calling PrintDictionary\n");
}
