CFLAGS=-c -Wall -W -g

all : freqdict

freqdict: freqdict.o main.o
	gcc -Wall -W -g freqdict.o main.o -o freqdict
freqdict_test: freqdict.o freqdict_unittest.o
	gcc -Wall -W -g freqdict.o freqdict_unittest.o -o freqdict_test
freqdict.o: freqdict.cc freqdict.h
	gcc $(CFLAGS) freqdict.cc -c freqdict.o
main.o: main.cc freqdict.h
	gcc $(CFLAGS) main.cc -c main.o
test.o: freqdict_unittest.cc freqdict.h
	gcc $(CFLAGS) freqdict_unittest.cc -c freqdict_unittest.o
clean:
	rm -rf *.o freqdict
