#include "Person.h"


Person::Person() : NOTE("Запись"), name(), arrDate(), number() {
	cout << "Вызван конструктор Person" << endl;
}

Person::Person(const Person& person) : NOTE(person), name(person.name), arrDate(), number(person.number) {
	cout << "Вызван конструктор копирования Person";
}

Person::Person(string name, int arrDate, string number) : NOTE("Запись"), name(name), arrDate(), number(number) {
	cout << "Вызван конструктор объекта Person";
}

void Person::changeObject() {
	cout << "Введите новые фамилию, имя: ";
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


	cout << "Введите новую дату рождения: ";
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

	cout << "Введите новый телефонный номер: ";
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
	cout << "Фамилия, имя: " << name << endl;
	cout << "Дата Рождения: " << arrDate[0]<< "." << arrDate[1] << "." << arrDate[2] << endl;
	cout << "Номер телефона: " << number << endl;
	
}

void Person::inputFromConsole()
{
	cout << "Введите фамилию, имя: ";
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

	cout << "Введите дату рождения: ";
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

	cout << "Введите телефонный номер: ";
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
