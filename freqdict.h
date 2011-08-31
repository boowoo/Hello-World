#ifndef FREQDICT_H
#define FREQDICT_H

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
//void PrintDictionary(struct dict * dic); 
void PrintDictionary();

struct dict
{
	int temp;
};
#endif
