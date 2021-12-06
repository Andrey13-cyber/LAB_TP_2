#include "NOTE.h"

NOTE::NOTE() : name(), number(0) {
	this->arrDate[0] = 1;
	this->arrDate[1] = 1;
	this->arrDate[2] = 1;
	cout << "������ ����������� ������� NOTE" << endl;
}

NOTE::NOTE(const NOTE& note) : name(note.name), number(note.number) {
	setDate(note.arrDate);
	cout << "������ ����������� ����������� NOTE" << endl;
}

NOTE::NOTE(string name, int arrDate[3], long long number) : name(name), number(number) {
	setDate(arrDate);
	cout << "������ ����������� ������� NOTE" << endl;
}

void NOTE::changeObject() {
	cout << "������� ����� �������, ���: ";
	getline(cin, name);
	
	cout << "������� ����� ���� ��������: ";
	arrDate[0] = errorProc(1, 31);
	cout << "������� ����� ����� ��������: ";
	arrDate[1] = errorProc(1, 12);
	cout << "������� ����� ��� ��������: ";
	arrDate[2] = errorProc(0, 3000);
	

	cout << "������� ����� ���������� �����: ";
	number = errorProc(9999999999, 99999999999);
	

}

void NOTE::printToConsole() {
	cout << "�������, ���: " << name << endl;
	cout << "���� ��������: " << arrDate[0] << "." << arrDate[1] << "." << arrDate[2] << endl;
	cout << "����� ��������: " << number << endl;

}

void NOTE::inputFromConsole()
{
	cout << "������� �������, ���: ";
	getline(cin, name);
	cout << "������� ���� ��������: ";
	arrDate[0] = errorProc(1, 31);
	cout << "������� ����� ��������: ";
	arrDate[1] = errorProc(1, 12);
	cout << "������� ��� ��������: ";
	arrDate[2] = errorProc(0, 3000);
	cout << "������� ���������� �����: ";
	number = errorProc(9999999999, 99999999999);
}

void NOTE::setName(string name) {
	this->name = name;

}

string NOTE::getName() {
	return name;
}


void NOTE::setDate(const int* arrDate) {
	this->arrDate[0] = arrDate[0];
	this->arrDate[1] = arrDate[1];
	this->arrDate[2] = arrDate[2];

}

int* NOTE::getDate() {
	return arrDate;
}

void NOTE::setNumber(long long number) {
	this->number = number;

}

long long NOTE::getNumber() {
	return number;
}

NOTE& NOTE::operator = (const NOTE& note) {
	if (&note == this)
		return *this;
	name = note.name;
	number = note.number;
	setDate(note.arrDate);
	return *this;
}

bool NOTE::operator > (const NOTE& note) {
	return name > note.name;
}
