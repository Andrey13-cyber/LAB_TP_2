#pragma once
#include "NOTE.h"
class Person :
    public NOTE
{
private:
	string name;
	string number;
	//string birthDate;
    int arrDate[3];
    

public:
    Person();
    Person(const Person&);
    ~Person() {
        cout << "Вызван деструктор Person" << endl;
    };
    Person(string name, int arrDate, string number);
    void setName(string name);
    void setDate(int *arrDate);
    void setNumber(string number);
    int getDate();
    string getName();
    string getNumber();
    virtual void changeObject();
    virtual void printToConsole();
    virtual void inputFromConsole();
};

