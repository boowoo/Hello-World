CFLAGS=-c -Wall

all : freqdict

freqdict: freqdict.o freqdict_unittest.o main.o
	gcc $(CFLAGS) freqdict.o freqdict_unittest.o main.o -o freqdict
freqdict.o: freqdict.cc freqdict.h
	gcc $(CFLAGS) freqdict.cc -o freqdict.o
main.o: main.c freqdict.h
	gcc $(CFLAGS) main.c -o main.o
test.o: freqdict_unittest.cc freqdict.h
	gcc $(CFLAGS) freqdict_unittest.cc -o freqdict_unittest.o
clean:
	rm -rf *.o freqdict
