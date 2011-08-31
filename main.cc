#include <stdio.h>
#include <stdlib.h>

#include "freqdict.h"

int main(int argc, char *argv[]) {
	FILE *fp;
	char *next_word;
//	struct dict dic; 

	if (argc < 2){
		printf("Укажите имя файла");
		exit (1);
	}
    // fp будет хранить в себе указатель на файл.
	fp = openFile(argv[1]);
	next_word = getNextWord(fp);   
	addWord(next_word);            
	PrintDictionary();
	printf("%p%p\n", fp, next_word);
	return 0;
}
