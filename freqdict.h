// Copyright 2011 boowoo
#ifndef FREQDICT_H_
#define FREQDICT_H_

#include <stdio.h>

FILE *openFile(char file_name[]);

char *getNextWord(FILE *file, int *ch);

void addWord(char *word);

void printDictionary(struct dict dic);

char *strCopy(char *word);

struct dic_entry {
  char * word;
  int num;
};

struct dict {
  struct dic_entry *words;
  int total_num;
};

extern struct dict dic;
#endif  // FREQDICT_H_
