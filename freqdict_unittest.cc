#include "freqdict.h"
#include "gtest/gtest.h"
// openFile():
TEST(openFileTest, validFile) {
  // TODO(dmitryhd): add here error handling
  FILE * new_f = fopen("/tmp/openfiletest_simple\n", "w+");
  fprintf(new_f, "omg\n");
  FILE * open_file = openFile();
  FILE * wrong_file = 0;
  ASSERT_NE(open_file, wrong_file);
  char buf[1024];
  fscanf(open_file, "%s", buf);
  EXPECT_STREQ("omg", buf);
  fclose(new_f);
  fclose(open_file);
}

// getNextWord():
TEST(GetWordTest, SimpleSpaces) {
  // TODO(dmitryhd): add here error handling
  FILE * new_f = fopen("/tmp/getwordtest_simple\n", "w+");
  fprintf(new_f, "omg test\n");
  EXPECT_STREQ("omg", getNextWord());
  EXPECT_STREQ("test", getNextWord());
  fclose(new_f);
}

TEST(GetWordTest, ComplicatedSpaces) {
  // TODO(dmitryhd): add here error handling
  FILE * new_f = fopen("/tmp/getwordtest_complicated\n", "w+");
  fprintf(new_f, " \t\n    omg  \n\t t   \t\n est\n");
  EXPECT_STREQ("omg", getNextWord());
  EXPECT_STREQ("t", getNextWord());
  EXPECT_STREQ("ets", getNextWord());
  fclose(new_f);
}
// there is no need for main().
// main resides in gtest_main.a see Makefile
// main contains only RUN_ALL_TESTS()
