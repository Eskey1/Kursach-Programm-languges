#pragma once
#include <conio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;
extern int len;
extern char fname[20]; // переменная под наш файл
struct INFO
{
	char surname[20];
	char name[20];
	char patronymic[20];
	char dolgnost[20];
	int godpostyp;
	int experience;
	char metka[2];
};
ostream& FinishL(ostream& stream);
ostream& FinishL2(ostream& stream);
ostream& shapka(ostream& stream);
ostream& shapka2(ostream& stream);
void write(fstream& p, INFO zap, int num = 0);
void print(INFO zap);
void print2(INFO zap);
INFO vvod();
void writeNzap(fstream& p, int n);
fstream& read(fstream& p, INFO& zap, int num = 0);
void readAll(fstream& p);
void izmenenie(fstream& p);
void readN(fstream& p, int N);
int metkaDel(fstream& p, char* shifr);
void UNmetkaDel(fstream& p);
void spiski(fstream& p);
int Delete(fstream& p);