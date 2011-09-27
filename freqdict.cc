// Copyright 2011 boowoo
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "./freqdict.h"

struct dict dic;

//  @brief: обертка для fopen
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

//  @brief: ищет в файле следующее слово и выделяет под него память
//  @input: file - указатель на файл
// TODO(dmitryhd): what kind of symbol?
//          сh - указатель на символ. Нужен для того,
//          чтобы известить функцию main о конце файла.
//  @output: указатель на следующее слово
char *getNextWord(FILE *file, int *ch) {
  // printf("MOCK: calling getNextWord\n");

  int i = 0;
  char is_word_begin = 0;
  int size_of_word = 0;
  char *next_word = (char*) malloc(sizeof(char)); 

  while (true) {
    *ch = getc(file);
    // TODO(dmitryhd): can you merge these two if's? (EOF and isspace)
    //  its behaviour is nearly the same;
    //  Я что-то не могу понять как объеденить эти строки.
    //  Во втором if'е же есть еще условие if (is_word_begin) а оно
    //  принесет кучу ошибок, если использовать его вместе с условием
    //  if (*ch == EOF).
    if (*ch == EOF) {
      // printf("getNW: i=%d EOF\n", i);
      next_word[i] = '\0';
      return strCopy(next_word);
    }
    // printf("getNW: i=%d, get=%c\n", i, ch);
    // check if symbol is space or punctuation character
    if (isspace(*ch) || ispunct(*ch)) {
      if (is_word_begin) {
        // printf("getNW: endword i=%d, get=%c\n", i, ch);
        next_word[i] = '\0';
        // TODO(dmitryhd): is there real need for strCopy function?
        //  if you merge this two if's you'll got only one call of strCopy
        //  and you could just pastle it's code there;
        return strCopy(next_word);
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
char *strCopy(char *word) {
  char *new_str;
  new_str = (char *) malloc(strlen(word) + 1);
  if (new_str != NULL)
  strncpy(new_str, word, strlen(word)+1);
  return new_str;
}

//  @brief: добавление слова в словарь
//  @input: указатель на слово, которое нужно добавить
//  @output: нет
void addWord(char *word) {
  //  printf("MOCK: calling addWord\n");
  //  printf("argumnt of addWord:%s\n", word);
  //  isWordAlredyInDictionary = 1, если текущее слово уже было в словаре.
  int isWordAlredyInDictionary = 0;
  //  curent_number содержит текущее число всех слов в словаре
  int curent_number = dic.total_num;
  for (int i = 0; (i < curent_number) && (isWordAlredyInDictionary != 1); i++) {
    if ( strcmp(word, dic.words[i].word) == 0 ) {
      isWordAlredyInDictionary = 1;
      dic.words[i].num++;
    }
  }
  if (isWordAlredyInDictionary == 0) {
    dic.total_num++;
    dic.words = (dic_entry*)realloc(dic.words,
                                    sizeof(dic_entry) * dic.total_num);
    dic.words[curent_number].word = word;
    dic.words[curent_number].num = 1;
  }
  //  printf("====================================================\n");
  //  for (int j = 0; j < dic.total_num; j++)
  //  printf("word=%s, dic.words.num=%d, dic.total_num=%d\n", dic.words[j].word,
  //                                                          dic.words[j].num,
  //                                                          dic.total_num);
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
