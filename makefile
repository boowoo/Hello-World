CFLAGS=-c -Wall -W -g

all : freqdict

freqdict: freqdict.o main.o
	gcc -Wall -W -g -o freqdict.o main.o -o freqdict
freqdict_test: freqdict.o freqdict_unittest.o
	gcc -Wall -W -g -o freqdict.o freqdict_unittest.o -o freqdict_test
freqdict.o: freqdict.cc freqdict.h
	gcc $(CFLAGS) freqdict.cc -o freqdict.o
main.o: main.cc freqdict.h
	gcc $(CFLAGS) main.cc -o main.o
test.o: freqdict_unittest.cc freqdict.h
	gcc $(CFLAGS) freqdict_unittest.cc -o freqdict_unittest.o
clean:
	rm -rf *.o freqdict
