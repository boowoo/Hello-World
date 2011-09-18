#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
  char is_word_begin = 0;
	//next_word = (char*) malloc(50);
	while (true) {
		ch = getc(file);
    // printf("getNW: i=%d, get=%c\n", i, ch);
    if (isspace(ch)) {
      if (is_word_begin) {
        // printf("getNW: endword i=%d, get=%c\n", i, ch);
        next_word[i] = '\0';
        return next_word;
      }
      else
        continue;
    }
    else {
      is_word_begin = 1;
			next_word[i++] = ch;
    }
		if (ch == EOF) {
			// exit(1);
      // printf("getNW: i=%d EOF\n", i);
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
