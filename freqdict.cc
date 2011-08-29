#include <stdio.h>
#include "freqdict.h"

FILE *openFile(char file_name[]){
	FILE *file = 0;

	printf("MOCK: calling openFile\n");
	printf("argument of openFile:%s\n", file_name);
	return file;
}

char *getNextWord(char *file) {
	char *next_word = 0;

	printf("MOCK: calling getNextWord\n");
	printf("argument of getNextWord:%p\n", file);
	return next_word; 
}

void addWord(char *word) {
	printf("MOCK: calling addWord\n");
	printf("argumnt of addWord:%p\n", word);
}

void PrintDictionary() {
	printf("MOCK: calling PrintDictionary\n");
}
