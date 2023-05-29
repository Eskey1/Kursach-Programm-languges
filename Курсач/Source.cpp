#include "Header.h"

ostream& shapka(ostream& stream)
{
	setlocale(LC_ALL, "rus");
	stream << endl << FinishL << endl;
	stream << setw(12) << "Фамилия"<< setw(10) << "Имя" << setw(15) << "Отчество" ;
	stream << setw(15) << "Должность";
	//stream << "Год" <<" " << "поступления" << setw(3) << "на" << " " << "работу";
	stream << setw(32) << "Год поступления на работу";
	stream << setw(15) << "Стаж работы" ;
	stream << setw(16) << "Метка" << endl;
	stream << endl << FinishL;
	return stream;
}


ostream& FinishL(ostream& stream)
{
	stream << setfill('-') << setw(120) << '|' << setfill(' ');
	return stream;
}
ostream& FinishL2(ostream& stream)
{
	stream << setfill('-') << setw(30) << '|' << setfill(' ');
	return stream;
}
ostream& shapka2(ostream& stream)
{
	setlocale(LC_ALL, "rus");
	stream << endl << FinishL2 << endl;
	stream << setw(12) << "Фамилия и инициалы" << setw(9) << "Метка" << endl;
	stream << endl << FinishL2;
	return stream;
}
