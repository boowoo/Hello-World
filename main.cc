#include <stdio.h>
#include <stdlib.h>
#include "freqdict.h"
extern int ch;

int main(int argc, char *argv[]) {
	FILE *fp;
	char *next_word_pointer;
		if (argc == 1) {
		printf("usage: %s some_arg1 some_arg2 \n",  argv[0]);
		printf("example: %s /usr/tmp/test.txt\n",  argv[0]);
		exit (1);
	}

  // стартуем со 2го аргумента, потому что первый == имя программы
  for (int cur_arg = 1; cur_arg < argc; ++cur_arg) {
    fp = openFile (argv[cur_arg]);
    printf("current arg = %d, value = %s\n", cur_arg, argv[cur_arg]);
    // get next words here ...
		// while (ch != EOF) {
    //  тут у нас обоих ошибка. Вопрос - почему? =)
    //  в том дело, что 2, 3 и тд аргументы открываются, но не 
    //  пишут слова, которые читают из файла, а сразу - end reading
		//	next_word_pointer = getNextWord(fp);
		//	addWord(next_word_pointer);
		//}
		 while (1) {
		  	next_word_pointer = getNextWord(fp);
        if (ch == EOF)
          break;
		  	addWord(next_word_pointer);
		}
		printf("end reading %d argument\n", cur_arg);
		fclose(fp);
	}
	printDictionary( dic);
	printf("%p%p\n", fp, next_word_pointer);
	return 0;
}
