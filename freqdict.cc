// Copyright 2011 boowoo
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "./freqdict.h"

struct dict dic;

//  @brief: обертка для fprintf
//  @input: имя файла, указанного как аргумент командной строки
//  @output: указатель на файл
FILE *openFile(char file_name[]) {
  FILE *file = 0;

//  printf("MOCK: calling openFile\n");

  if ((file = fopen(file_name, "r")) == NULL) {
    fprintf(stderr, "can't open file %s", file_name);
    exit(1);
  }
  return file;
}

//  @brief: ищет в файле следующее слово
//  @input: file - указатель на файл
//          сh - указатель на символ
//  @output: указатель на следующее слово
char *getNextWord(FILE *file, int *ch) {
  int i = 0;
  char is_word_begin = 0;
  int size_of_word = 1;
  // printf("MOCK: calling getNextWord\n");
  char *next_word = (char*) malloc(sizeof(char) * size_of_word);

  while (true) {
    *ch = getc(file);
    if (*ch == EOF) {
      // printf("getNW: i=%d EOF\n", i);
      next_word[i] = '\0';
      return str_copy(next_word);
    }
    // printf("getNW: i=%d, get=%c\n", i, ch);
    // check if symbol is space or punctuation character
    if (isspace(*ch) || ispunct(*ch)) {
      if (is_word_begin) {
        // printf("getNW: endword i=%d, get=%c\n", i, ch);
        next_word[i] = '\0';
        return str_copy(next_word);
      } else {
        continue;
        }
    } else {
      is_word_begin = 1;
      size_of_word++;
      //  выделяем память под следующий символ слова
      next_word = (char*) realloc(next_word, sizeof(char) * size_of_word);
      next_word[i++] = tolower(*ch);
      }
  }
}

//  @brief: выделение памяти под строку.
//  @input: указатель на строку.
//  @output: указатель на блок памяти, в котором хранится
//           строка, на которую был получен указатель.
char *str_copy(char *s) {
  char *t;
  t = (char *) malloc(strlen(s) + 1);
  if (t != NULL)
//    strcpy(t,  s);
  snprintf(t, strlen(s)+1, "%s", s);
  return t;
}

//  @brief: добавление слова в словарь
//  @input: указатель на слово, которую нужно добавить
//  @output: нет
void addWord(char *word) {
  //  printf("MOCK: calling addWord\n");
  //  printf("argumnt of addWord:%s\n", word);
  //  flag = 1, если текущее слово уже было в словаре.
  int flag = 0;
  //  curent_number содержит текущее число всех слов в словаре
  int curent_number = dic.total_num;
//  if (curent_number == 0)
//    dic.words = (dic_entry*)malloc(sizeof(dic_entry));
  for (int i = 0; (i < curent_number) && (flag != 1); i++) {
    //  тело if'а выполняется, если строки равны.
    if ( strcmp(word, dic.words[i].word) == 0 ) {
      flag = 1;
      dic.words[i].num++;
    }
  }
  if (flag == 0) {
    dic.total_num++;
    dic.words = (dic_entry*)realloc(dic.words, sizeof(dic_entry) * dic.total_num);
    dic.words[curent_number].word = word;
    dic.words[curent_number].num++;
  }
    printf("====================================================\n");
    for (int j = 0; j < dic.total_num; j++)
    printf("word=%s, dic.words.num=%d, dic.total_num=%d\n", dic.words[j].word,
                                                            dic.words[j].num,
                                                            dic.total_num);
}
//  @brief: распечатать словарь
//  @input: структура, в которой содержится словарь
//  @output: нет
void printDictionary(struct dict dic) {
  //  printf("MOCK: calling PrintDictionary\n");

  for (int i = 0; i < dic.total_num; i++) {
    printf("%d %d %s\n", dic.words[i].num, i+1, dic.words[i].word);
  }
}
