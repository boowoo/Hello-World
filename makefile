CFLAGS=-c -Wall -W -g

all : freqdict

freqdict: freqdict.o main.o
	gcc -Wall -W -g freqdict.o main.o -o freqdict
freqdict_test: freqdict.o freqdict_unittest.o
	gcc -Wall -W -g freqdict.o freqdict_unittest.o -o freqdict_test
freqdict.o: freqdict.cc freqdict.h
	gcc $(CFLAGS) freqdict.cc 
main.o: main.cc freqdict.h
	gcc $(CFLAGS) main.cc 
test.o: freqdict_unittest.cc freqdict.h
	gcc $(CFLAGS) freqdict_unittest.cc 
clean:
	rm -rf *.o freqdict
