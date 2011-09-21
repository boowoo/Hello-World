GTEST_DIR=thirdparty/gtest
GTEST_INCL= -Ithirdparty/gtest/include
CFLAGS=-Wall -W -g -lpthread

all : freqdict

# download and install google test library
# and skip this if we already did this
googletest:
	./install_gtest.sh

#	cpplint - code style checker
check:
	cpplint.py freqdict.cc freqdict.h main.cc freqdict_unittest.cc

# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.

gtest-all.o :
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(GTEST_INCL) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o :
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(GTEST_INCL) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

# create and run unittest file:
test: googletest freqdict_unittest.o gtest_main.a freqdict.o
	g++ $(CFLAGS) $(GTEST_INCL) gtest_main.a freqdict.o freqdict_unittest.o -o freqdict_test
	./freqdict_test

# main executable:
freqdict: freqdict.o main.o
	gcc $(CFLAGS) freqdict.o main.o -o freqdict


freqdict.o: freqdict.cc freqdict.h
	gcc $(CFLAGS) -c freqdict.cc
main.o: main.cc freqdict.h
	gcc $(CFLAGS) -c  main.cc
freqdict_unittest.o: freqdict_unittest.cc freqdict.h
	gcc $(CFLAGS) $(GTEST_INCL) -c freqdict_unittest.cc



clean:
	rm -rfv *.o *.a freqdict_test freqdict
clean_tests: clean
	rm -rfv thirdparty/
