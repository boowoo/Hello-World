CFLAGS=-Wall -W -g

all : freqdict

freqdict: freqdict.o main.o
	gcc $(CFLAGS) freqdict.o main.o -o freqdict
freqdict_test: freqdict.o freqdict_unittest.o
	gcc $(CFLAGS) freqdict.o freqdict_unittest.o -o freqdict_test
freqdict.o: freqdict.cc freqdict.h
	gcc $(CFLAGS) -c freqdict.cc 
main.o: main.cc freqdict.h
	gcc $(CFLAGS) -c  main.cc 
test.o: freqdict_unittest.cc freqdict.h
	gcc $(CFLAGS) -c freqdict_unittest.cc 
clean:
	rm -rf *.o freqdict
