#include "Header.h"
#include <string.h>
void writeNzap(fstream& p, int n) // записать n-ое кол-во записей
{
	p.clear();
	p.seekg(0, ios::end); //запись в конец
	for (int i = 0; i < n; i++)
	{
		INFO zap;
		zap = vvod();
		write(p, zap);
	}
}
void write(fstream& p, INFO zap, int num)
{
	p.clear(); //очистка потока
	if (num)
		p.seekg((num - 1) * len, ios::beg);
	p.write((char*)&zap, len);
	/*if (!p)
	{
	cout<<"Error write";
	_getch();
	exit (0);
	}*/
}
INFO vvod()
{
	INFO zap;
	setlocale(LC_ALL, "rus");
	cout << endl << "Введите фамилию работника:";
	cin >> zap.surname;
	cout << endl << "Введите имя работника:";
	cin >> zap.name;
	cout << endl << "Введите отчество работника:";
	cin >> zap.patronymic;
	cout << endl << "Введите должность работника:";
	cin >> zap.dolgnost;
	cout << endl << "Введите год поступления на работу:";
	cin >> zap.godpostyp;
	cout << endl << "Введите стаж работы:";
	cin >> zap.experience;
	strcpy_s(zap.metka, "+");
	return zap;
}
fstream& read(fstream& p, INFO& zap, int num)
{
	p.clear(); //очистка потока
	if (num) //позиционирование
		p.seekg((num - 1) * len, ios::beg);
	p.read((char*)&zap, len);
	//if (!p/*&&!p.eof()*/)
	//{
	
	//cout << "\n\tError read";
	
	//_getch();
	
	//exit(0);
	//}
	return p;
}
void print(INFO zap)
{
	cout << endl << setw(12) << zap.surname << setw(10) << zap.name << setw(15) << zap.patronymic ;
	cout << setw(15) << zap.dolgnost;
	cout << setw(21) << zap.godpostyp <<  ' ';
	cout << setw(21) << zap.experience;
	cout << setw(19) << zap.metka;
}
void readAll(fstream& p)
{
	p.clear();
	p.seekg(0, ios::beg);
	INFO zap; // куда читать
	cout << shapka;
	while (read(p, zap))
		print(zap);
	cout << endl << FinishL;
}
void readN(fstream& p, int N)
{
	p.clear();
	p.seekg(0, ios::beg);
	INFO zap; // куда читать
	if (read(p, zap, N))
	{
		cout << shapka;
		print(zap);
		cout << endl << FinishL;
	}
	else
		cout << endl << "Такой записи нет";
	_getch();
}
void UNmetkaDel(fstream& p/*, char* metka*/)
{
	p.clear();
	INFO zap;
	p.seekp(0, ios::beg);
	for (int i = 1; read(p, zap, i); i++)
	{
		if (strcmp(zap.metka, "-") == 0)
		{
			strcpy_s(zap.metka, "+");
			write(p, zap, i);
		}
	}
	_getch();
}
int metkaDel(fstream& p, char* surname/*, char* metka*/)
{
	p.clear();
	INFO zap;
	p.seekp(0, ios::beg);
	int kol = 0;
	for (int i = 1; read(p, zap, i); i++)
	{
		if (strcmp(zap.surname, surname) == 0)
		{
			strcpy_s(zap.metka, "-");
			write(p, zap, i);
			kol++;
		}
	}
	return kol;
}
int Delete(fstream& p)
{
	fstream p1("temp.txt", ios::app);
	p.clear();
	INFO zap;
	p.seekp(0, ios::beg);
	int kol = 0;
	for (int i = 1; read(p, zap, i); i++)
	{
		if (strcmp(zap.metka, "+") == 0)
		{
			write(p1, zap);
			kol++;
		}
	}
	p.close();
	p1.close();
	remove(fname);
	rename("temp.txt", fname);
	p.open(fname, ios::in | ios::out | ios::ate);
	return kol;
}
void spiski(fstream& p)
{
	INFO zap;
	int f, g, k = 1;
	char gr[10][15];
	//int y[2];
	p.clear();
	p.seekg(0, ios::beg);
	cout << "Введите число, выше которого должен быть стаж работы работника" << endl << "Число = ";
	cin >> g;
// мое
// for (int i=0; read(p, zap, i); i++)
// {
// if(zap.experience>g) y[i]=zap.experience;
// }
// 
// 
// 
// 
// 
//
// 
// 
// 
// 
// 
 for (int i = 1/*, n=0*/; read(p, zap, i);/*n++, */i++)
	{	
		if(zap.experience>g) 
		{
			//y[n]=zap.experience;
			f = 0;
			if (i == 1) strcpy_s(gr[i - 1], zap.surname);
			else {
					p.seekg(0, ios::beg);
					for (int j = 0; j < k; j++)
						if (strcmp(gr[j], zap.surname) == 0)f = 1;
							if (f == 0) 
								{
									strcpy_s(gr[k], zap.surname); k++;
								}
					}
		}
		else continue;
 }
 
for(int i=0;i<k;i++)
{
	for (int j = i; j < k; j++)
	{
		if (strcmp(gr[i], gr[j]) == 1)
		{
			char t[100];
			strcpy_s(t, gr[i]);
			strcpy_s(gr[i], gr[j]);
			strcpy_s(gr[j], t);
		}
	}
}
// 
// мое;
//	for (int i = 1; read(p, zap, i); i++)
//	{
//		f = 0;
//		if (i == 1) strcpy_s(gr[i - 1], zap.group);
//		else {
//			p.seekg(0, ios::beg);
//			for (int j = 0; j < k; j++)
//				if (strcmp// если gr[j]==zap.group (gr[j], zap.group) == 0)f = 1;
//			if (f == 0) {
//				strcpy_s//копирует в гр к то что в группе(gr[k], zpa.group); k++;
//			}
//		}
//	}
	cout << shapka2;
	for (int j = 0; j < k; j++)
	{
		//cout << endl << "Группа" << gr[j];
		
		p.seekg(0, ios::beg);
		for (int i = 1; read(p, zap, i); i++)
		{
			if (strcmp(gr[j], zap.surname) == 0)
				print2(zap);
		}
		
	}
	cout << endl << FinishL2;
}
void print2(INFO zap)
{
	cout << endl << setw(12) << zap.surname<<" "<<*zap.name << "."<< *zap.patronymic << setw(2) << ' ';
	cout << setw(7) << zap.metka;
}