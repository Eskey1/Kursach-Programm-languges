#include "Header.h"

ostream& shapka(ostream& stream)
{
	setlocale(LC_ALL, "rus");
	stream << endl << FinishL << endl;
	stream << setw(12) << "�������"<< setw(10) << "���" << setw(15) << "��������" ;
	stream << setw(15) << "���������";
	//stream << "���" <<" " << "�����������" << setw(3) << "��" << " " << "������";
	stream << setw(32) << "��� ����������� �� ������";
	stream << setw(15) << "���� ������" ;
	stream << setw(16) << "�����" << endl;
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
	stream << setw(12) << "������� � ��������" << setw(9) << "�����" << endl;
	stream << endl << FinishL2;
	return stream;
}
