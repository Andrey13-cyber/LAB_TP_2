#include "NOTE.h"

NOTE::NOTE() : name(), number(0) {
	this->arrDate[0] = 1;
	this->arrDate[1] = 1;
	this->arrDate[2] = 1;
	cout << "Вызван конструктор объекта NOTE" << endl;
}

NOTE::NOTE(const NOTE& note) : name(note.name), number(note.number) {
	setDate(note.arrDate);
	cout << "Вызван конструктор копирования NOTE" << endl;
}

NOTE::NOTE(string name, int arrDate[3], long long number) : name(name), number(number) {
	setDate(arrDate);
	cout << "Вызван конструктор объекта NOTE" << endl;
}

void NOTE::changeObject() {
	cout << "Введите новые фамилию, имя: ";
	getline(cin, name);
	
	cout << "Введите новый день рождения: ";
	arrDate[0] = errorProc(1, 31);
	cout << "Введите новый месяц рождения: ";
	arrDate[1] = errorProc(1, 12);
	cout << "Введите новый год рождения: ";
	arrDate[2] = errorProc(0, 3000);
	

	cout << "Введите новый телефонный номер: ";
	number = errorProc(9999999999, 99999999999);
	

}

void NOTE::printToConsole() {
	cout << "Фамилия, имя: " << name << endl;
	cout << "Дата Рождения: " << arrDate[0] << "." << arrDate[1] << "." << arrDate[2] << endl;
	cout << "Номер телефона: " << number << endl;

}

void NOTE::inputFromConsole()
{
	cout << "Введите фамилию, имя: ";
	getline(cin, name);
	cout << "Введите день рождения: ";
	arrDate[0] = errorProc(1, 31);
	cout << "Введите месяц рождения: ";
	arrDate[1] = errorProc(1, 12);
	cout << "Введите год рождения: ";
	arrDate[2] = errorProc(0, 3000);
	cout << "Введите телефонный номер: ";
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
