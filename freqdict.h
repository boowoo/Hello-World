#include <stdio.h>
//Функция получает имя файл из командной строки.
//Открывает файл при помощи FILE *fopen(char *name, char *mode)
//ОБрабатывает ошибки и возвращает уназатель на файл
//FILE *openFile(char *fileName); 
FILE *openFile(); 
	

//Функция получает в качестве аргумента указатель на файл, который нужно считать
//при помощи int getc(FILE *fileName) обрабатывается посимвольно файл, и в нем находятся слова.
//Функция возвращает указатель на найденное слово.
//char *getNextWord(FILE *fileName);   
char *getNextWord();   

//Получает слово, проверяет есть ли такое в текущем словаре.
//Если есть, то инкрементируем число вхождений этого слова.
//Если нет, то добавляем слово в словарь.
//void addWord(char *word); 
void addWord(); 

//Печать словаря
//void PrintDictionary(struct dict * dic); 
void PrintDictionary();

