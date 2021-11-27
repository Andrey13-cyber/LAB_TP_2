#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class NOTE
{
private:
	string name;
	string surname;
	string number;
	string birthDate;

public:
    NOTE();
    NOTE(const NOTE&);
    virtual ~NOTE();
    NOTE(string name, string birthDate, string surname, string number);
    void setNote(string name, string birthDate, string surname, string number);
    string getDate();
    string getName();
    string getSurname();
    string getNumber();
    virtual void print();
    virtual void printToFile(ofstream&);
};

