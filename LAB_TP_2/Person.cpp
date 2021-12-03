#include "Person.h"


Person::Person() : NOTE("������"), name(), arrDate(), number() {
	cout << "������ ����������� Person" << endl;
}

Person::Person(const Person& person) : NOTE(person), name(person.name), arrDate(), number(person.number) {
	cout << "������ ����������� ����������� Person";
}

Person::Person(string name, int arrDate, string number) : NOTE("������"), name(name), arrDate(), number(number) {
	cout << "������ ����������� ������� Person";
}

void Person::changeObject() {
	cout << "������� ����� �������, ���: ";
	getline(cin, name);
	getline(cin, name);
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Noncorrect new lenght, try again ->";
		getline(cin, name);
		getline(cin, name);
	}


	cout << "������� ����� ���� ��������: ";
	for (int i = 0; i < 3; i++)
		cin >> arrDate[i];
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Noncorrect new width, try again ->";
		for (int i = 0; i < 3; i++)
			cin >> arrDate[i];
	}

	cout << "������� ����� ���������� �����: ";
	cin >> number;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Noncorrect new width, try again ->";
		cin >> number;
	}
	
}

void Person::printToConsole() {
	NOTE::printToConsole();
	cout << "�������, ���: " << name << endl;
	cout << "���� ��������: " << arrDate[0]<< "." << arrDate[1] << "." << arrDate[2] << endl;
	cout << "����� ��������: " << number << endl;
	
}

void Person::inputFromConsole()
{
	cout << "������� �������, ���: ";
	getline(cin, name);
	getline(cin, name);
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Noncorrect new lenght, try again ->";
		getline(cin, name);
		getline(cin, name);
	}

	cout << "������� ���� ��������: ";
	for (int i = 0; i < 3; i++)
		cin >> arrDate[i];
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Noncorrect new width, try again ->";
		for (int i = 0; i < 3; i++)
			cin >> arrDate[i];
	}

	cout << "������� ���������� �����: ";
	cin >> number;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "Noncorrect new width, try again ->";
		cin >> number;
	}

	
}

void Person::setName(string name) {
	this->name = name;
	
}

string Person::getName() {
	return name;
}


void Person::setDate(int *arrDate) {
	this->arrDate[0] = arrDate[0];
	this->arrDate[1] = arrDate[1];
	this->arrDate[2] = arrDate[2];

}

int Person::getDate() {
	return arrDate[0];
	return arrDate[1];
	return arrDate[2];
}

void Person::setNumber(string number) {
	this->number = number;

}

string Person::getNumber() {
	return number;
}
