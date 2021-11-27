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
    cout << "Имя: " << namePerson << endl;
    cout << "Фамилия: " << surname << endl;
    cout << "Дата рождения: " << birthDate << endl;
    cout << "Номер телефона: " << number << endl;

}

void NOTE::printToFile(ofstream& output)
{
    string namePerson = name;
    if (namePerson != "")
        output << "ФИО Родителя: " << namePerson << endl;
    if (surname != "")
        output << "Фамилия: " << surname << endl;
    if (birthDate != "")
        output << "Дата рождения: " << birthDate << endl;
    if (number != "")
        output << "Номер телефона: " << number << endl;

}