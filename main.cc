#include <stdio.h>
#include "freqdict.h"

int main(void) {
	FILE *fp;
	char *a;
	fp = openFile();
	a = getNextWord();
	addWord();
	PrintDictionary();
	printf("%p%p", fp, a);
  return 0;
}
