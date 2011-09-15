#include <stdio.h>
#include <stdlib.h>
#include "freqdict.h"
extern int ch;

int main(int argc, char *argv[]) {
	FILE *fp;
	char *next_word_pointer;
	struct dict dic;
	if (argc == 1) {
		printf("Укажите имена файлов\n");
		exit (1);
	}
	while (--argc > 0){
    	// fp будет хранить в себе указатель на файл.
		fp = openFile(*++argv);
		printf("______________________OMG! argc = %d\n", argc);
		while (ch != EOF) {
			next_word_pointer = getNextWord(fp);
			addWord(next_word_pointer);
		}
		printf("______________________OMG!\n");
		fclose(fp);
	}
	PrintDictionary( dic);
	printf("%p%p\n", fp, next_word_pointer);
	return 0;
}

