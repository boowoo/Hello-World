#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "./freqdict.h"

struct dict dic;
int ch;
char next_word[MAX_WORD];

FILE *openFile(char file_name[]) {
  FILE *file = 0;

//  printf("MOCK: calling openFile\n");

  if ((file = fopen(file_name, "r")) == NULL) {
    fprintf(stderr, "can't open file %s", file_name);
    exit(1);
  }
  return file;
}


char *getNextWord(FILE *file) {
  int i = 0;
  char is_word_begin = 0;
  // printf("MOCK: calling getNextWord\n");

  while (true) {
    ch = getc(file);
    if (ch == EOF) {
      // printf("getNW: i=%d EOF\n", i);
      next_word[i] = '\0';
      return str_copy(next_word);
    }
    // printf("getNW: i=%d, get=%c\n", i, ch);
    // check if symbol is space or punctuation character
    if (isspace(ch) || ispunct(ch)) {
      if (is_word_begin) {
        // printf("getNW: endword i=%d, get=%c\n", i, ch);
        next_word[i] = '\0';
        return str_copy(next_word);
      } else {
        continue;
        }
    } else {
      is_word_begin = 1;
      next_word[i++] = tolower(ch);
      }
  }
}

char *str_copy(char *s) {
  char *t;
  t = (char *) malloc(strlen(s) + 1);
  if (t != NULL)
//    strcpy(t,  s);
  snprintf(t, strlen(s)+1, "%s", s);
  return t;
}

void addWord(char *word) {
  //  printf("MOCK: calling addWord\n");
  //  printf("argumnt of addWord:%s\n", word);
  //  долго думал как лучше назвать переменную,
  //  но так и не предумал
  //  flag = 1, если текущее слово уже было в словаре.
  int flag = 0;
  //  curent_number содержит текущее число всех слов в словаре
  int curent_number = dic.total_num;

  for (int i = 0; (i < curent_number) && (flag != 1); i++) {
    //  тело if'а выполняется, если строки равны.
    if ( strcmp(word, dic.words[i].word) == 0 ) {
      flag = 1;
      dic.words[i].num++;
    }
  }
  if (flag == 0) {
    dic.words[curent_number].word = word;
    dic.words[curent_number].num++;
    dic.total_num++;
  }
}

void printDictionary(struct dict dic) {
  //  printf("MOCK: calling PrintDictionary\n");

  for (int i = 0; i < dic.total_num; i++) {
    printf("%d %d %s\n", dic.words[i].num, i+1, dic.words[i].word);
  }
}
