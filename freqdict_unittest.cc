#include "freqdict.h"
#include "gtest/gtest.h"

TEST(SimpleTest, PrintsMessage) {
  printf("First test...\n");
}

// there is no need for main().
// main resides in gtest_main.a see Makefile
// main contains only RUN_ALL_TESTS()
