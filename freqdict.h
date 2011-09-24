#ifndef FREQDICT_H
#define FREQDICT_H
#include <stdio.h>

FILE *openFile(char file_name[]);

char *getNextWord(FILE *file, int *ch);

void addWord(char *word);

void printDictionary(struct dict dic);

char *str_copy(char *word);

struct dic_entry {
  char * word;
  int num;
};

struct dict {
  struct dic_entry *words;
  int total_num;
};

extern struct dict dic;
#endif
