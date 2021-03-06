// Copyright 2011 boowoo
#include "./freqdict.h"
#include "gtest/gtest.h"

extern struct dict dic;

// openFile():
TEST(openFileTest, validFile) {
  // TODO(dmitryhd): add here error handling
  char filename_const[]= "/tmp/validFile";
  char * filename = &filename_const[0];

  FILE * new_f = fopen(filename_const, "w+");
  fprintf(new_f, "omg\n");
  FILE * open_file = openFile(filename);
  FILE * wrong_file = 0;
  ASSERT_NE(open_file, wrong_file);
  fclose(new_f);
  fclose(open_file);
}

// getNextWord():
TEST(GetWordTest, SimpleSpaces) {
  // TODO(dmitryhd): add here error handling
  char filename_const[]= "/tmp/SimpleSpaces";
  char * filename = &filename_const[0];
  int a;

  FILE * new_f = fopen(filename_const, "w+");
  fprintf(new_f, "omg test\n");
  fclose(new_f);
  FILE * open_file = openFile(filename);
  char * x = getNextWord(open_file, &a);
  // printf("1: x = %s\n", x);
  EXPECT_STREQ("omg", x);
  x = getNextWord(open_file, &a);
  // printf("2: x = %s\n", x);
  EXPECT_STREQ("test", x);
  fclose(open_file);
}

TEST(GetWordTest, ComplicatedSpaces) {
  // TODO(dmitryhd): add here error handling
  char filename_const[]= "/tmp/ComplicatedSpaces";
  char * filename = &filename_const[0];
  int a;

  FILE * new_f = fopen(filename_const, "w+");
  fprintf(new_f, "omg  \n\t t   \t\n est\n");
  fclose(new_f);
  FILE * open_file = openFile(filename);
  EXPECT_STREQ("omg", getNextWord(open_file, &a));
  EXPECT_STREQ("t", getNextWord(open_file, &a));
  EXPECT_STREQ("est", getNextWord(open_file, &a));
  fclose(new_f);
}

TEST(GetWordTest, Punctuation) {
  // TODO(dmitryhd): add here error handling
  char filename_const[]= "/tmp/Punctuation";
  char * filename = &filename_const[0];
  int a;

  FILE * new_f = fopen(filename_const, "w+");
  fprintf(new_f, "word1; ...word2... word3? word4, word5!");
  fclose(new_f);
  FILE * open_file = openFile(filename);
  EXPECT_STREQ("word1", getNextWord(open_file, &a));
  EXPECT_STREQ("word2", getNextWord(open_file, &a));
  EXPECT_STREQ("word3", getNextWord(open_file, &a));
  EXPECT_STREQ("word4", getNextWord(open_file, &a));
  EXPECT_STREQ("word5", getNextWord(open_file, &a));
  fclose(new_f);
}

TEST(GetWordTest, ToLower) {
  // TODO(dmitryhd): add here error handling
  char filename_const[]= "/tmp/ToLower";
  char * filename = &filename_const[0];
  int a;

  FILE * new_f = fopen(filename_const, "w+");
  fprintf(new_f, "Word1 WORD2 WoRd3");
  fclose(new_f);
  FILE * open_file = openFile(filename);
  EXPECT_STREQ("word1", getNextWord(open_file, &a));
  EXPECT_STREQ("word2", getNextWord(open_file, &a));
  EXPECT_STREQ("word3", getNextWord(open_file, &a));
  fclose(new_f);
}

//  addWord() first test
//  цель теста - проверить правильно вносятся в структуру слова,
//  предварительно записанные в файлi.
TEST(addWord, first_addWord_test) {
  char * next_word_pointer = 0;
  char filename_const[] = "/tmp/first_addWord_test";
  char * filename = &filename_const[0];
  int a;

  FILE * new_f = fopen(filename_const, "w");
  fprintf(new_f, "omg test\n");
  fclose(new_f);
  FILE * open_file = openFile(filename);
  //  в файле 2 слова, по-этому 2 нижнии строки повторяются 2 раза.
  next_word_pointer = getNextWord(open_file, &a);
  addWord(next_word_pointer);
  next_word_pointer = getNextWord(open_file, &a);
  addWord(next_word_pointer);
  fclose(open_file);
  //  дальше идет проверка совпадают ли поля структуры dict
  //  со словами, содержащимися в файле filename_const
  //  выглядит проверка примерно вот так:
    EXPECT_STREQ("omg", dic.words[0].word);
    EXPECT_STREQ("test", dic.words[1].word);
  dic.total_num = 0;
  free(dic.words[0].word);
  free(dic.words[1].word);
  dic.words[0].num = 0;
  dic.words[1].num = 0;
}

//  addWord() second test
//  в этом тесте в файл пишется,  а затем считывается строка,
//  в которой несколько повторяющихся слов.
//  цель теста - проверить верно ли обрабатываются повторяющиеся слов
//  т.е. проверить на правильность поле num структуры word
TEST(addWord,  second_addWord_test) {
  char * next_word_pointer = 0;
  char filename_const[] = "/tmp/second_addWord_test";
  char * filename = &filename_const[0];
  int a;

  FILE * new_f = fopen(filename_const,  "w");
  fprintf(new_f,  "sex sex sex drugs drugs rnr\n");
  fclose(new_f);
  FILE * open_file = openFile(filename);
  dic.words[0].num = 0;
  dic.words[1].num = 0;
  //  Здесь 6 - "магическое" число.Оно выбрано не случано, 6 - это кол-во слов,
  //  которые мы записали в файл.
  for (int i = 0; i < 6; i++) {
    next_word_pointer = getNextWord(open_file, &a);
    addWord(next_word_pointer);
  }
  fclose(open_file);
  //  3 раза в строке встретилось слово omg, 2 раза test, 1 раз wtf
  //  Проверка происходит предположительно вот так:
    EXPECT_STREQ("sex", dic.words[0].word);
    EXPECT_STREQ("drugs", dic.words[1].word);
    EXPECT_STREQ("rnr", dic.words[2].word);
    EXPECT_EQ(3, dic.words[0].num);
    EXPECT_EQ(2, dic.words[1].num);
    EXPECT_EQ(1, dic.words[2].num);
}

// there is no need for main().
// main resides in gtest_main.a see Makefile
// main contains only RUN_ALL_TESTS()
