#include <stdio.h>
#include "freqdict.h"

FILE *openFile(){
	FILE *file = 0;
	printf("MOCK: calling openFile\n");
	return file;
}

char *getNextWord() {
	char *a = 0;
	printf("MOCK: calling getNextWord\n");
	return a;
}

void addWord(){
	printf("MOCK: calling addWord\n");
}

void PrintDictionary() {
	printf("MOCK: calling PrintDictionary\n");
}
