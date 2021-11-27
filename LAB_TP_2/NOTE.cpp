#include "NOTE.h"



NOTE::NOTE()
{
    birthDate = "";
    name = "";
    surname = "";
    number = "";

}
NOTE::NOTE(const NOTE& a)
{
    name = a.name;
    birthDate = a.birthDate;
    surname = a.surname;
    number = a.number;
}

NOTE::~NOTE()
{
    birthDate = "";
    name = "";
    surname = "";
    number = "";
}
NOTE::NOTE(string name, string birthDate, string surname, string number)
{
    
    this->name = name;
    this->birthDate = birthDate;
    this->surname = surname;
    this->number = number;


}

void NOTE::setNote(string name, string birthDate, string surname, string number)
{
    this->name = name;
    this->birthDate = birthDate;
    this->surname = surname;
    this->number = number;
}

string NOTE::getDate()
{
    return birthDate;
}

string NOTE::getName()
{
    return name;
}

string NOTE::getSurname()
{
    return surname;
}

string NOTE::getNumber()
{
    return number;
}

void NOTE::print()
{
    string namePerson = name;
    cout << "���: " << namePerson << endl;
    cout << "�������: " << surname << endl;
    cout << "���� ��������: " << birthDate << endl;
    cout << "����� ��������: " << number << endl;

}

void NOTE::printToFile(ofstream& output)
{
    string namePerson = name;
    if (namePerson != "")
        output << "��� ��������: " << namePerson << endl;
    if (surname != "")
        output << "�������: " << surname << endl;
    if (birthDate != "")
        output << "���� ��������: " << birthDate << endl;
    if (number != "")
        output << "����� ��������: " << number << endl;

}