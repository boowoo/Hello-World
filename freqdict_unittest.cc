#include "freqdict.h"
#include "gtest/gtest.h"

// openFile():
TEST(openFileTest, validFile) {
  // TODO(dmitryhd): add here error handling
  char filename_const[]= "/tmp/openfiletest_simple";
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

  FILE * new_f = fopen(filename_const, "w+");
  fprintf(new_f, "omg test\n");
  fclose(new_f);
  FILE * open_file = openFile(filename);
  char * x = getNextWord(open_file);
  // printf("1: x = %s\n", x);
  EXPECT_STREQ("omg", x);
  x = getNextWord(open_file);
  // printf("2: x = %s\n", x);
  EXPECT_STREQ("test", x);
  fclose(open_file);
}

TEST(GetWordTest, ComplicatedSpaces) {
  // TODO(dmitryhd): add here error handling
  char filename_const[]= "/tmp/openfiletest_simple";
  char * filename = &filename_const[0];

  FILE * new_f = fopen(filename_const, "w+");
  fprintf(new_f, "omg  \n\t t   \t\n est\n");
  fclose(new_f);
  FILE * open_file = openFile(filename);
  EXPECT_STREQ("omg", getNextWord(open_file));
  EXPECT_STREQ("t", getNextWord(open_file));
  EXPECT_STREQ("est", getNextWord(open_file));
  fclose(new_f);
}

// there is no need for main().
// main resides in gtest_main.a see Makefile
// main contains only RUN_ALL_TESTS()
