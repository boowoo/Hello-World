#ifndef FREQDICT_H
#define FREQDICT_H
#define MAX_WORD 50
#define MAX_COUNT_OF_WORDS 100
#include <stdio.h>

//Функция получает имя файла из командной строки.
//Открывает этот файл при помощи FILE *fopen(char *name, char *mode)
//Обрабатывает ошибки и возвращает указатель на файл
FILE *openFile(char file_name[]);

//Функция получает в качестве аргумента указатель на файл, который нужно считать
//Файл считывается посимвольно при помощи int getc(FILE *fileName).В файле ищутся слова.
//Функция возвращает указатель на найденное слово.
char *getNextWord(FILE *file);

//Получает указатель на слово, проверяет есть ли такое в текущем словаре.
//Если есть, то инкрементируем число вхождений этого слова.
//Если нет, то добавляем слово в словарь.
void addWord(char *word);

//Печать словаря
//TODO (boowoo):передавать не саму структуру а указатель на нее
//сравнить производительность
void PrintDictionary( struct dict dic);

//структура word содержит указатель на слово
////и число повторений этого слова в тексте
struct dic_entry {
	char * word;
	int num;
};
		
//структура dict содержит указатель на массив структур word
//и общее число слов в словаре
struct dict {
	struct dic_entry words[MAX_COUNT_OF_WORDS];
	int	total_num;
};


//Массив next_word[] будет хранить слово
extern char next_word[];

//Переменная ch будет содержать текущий символ
//при считывании из файла
extern int ch;

extern struct dict dic;
#endif
