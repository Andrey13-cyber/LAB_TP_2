#include "NOTE.h"

NOTE::NOTE(string rec) : rec(rec)
{
    cout << "Вызван конструктор NOTE" << endl;
}
NOTE::NOTE(const NOTE& note) : rec(note.rec)
{
    cout << "Вызван конструктор копирования NOTE" << endl;
}


void NOTE::printToConsole()
{
    cout << rec << endl;
}

void NOTE::changeObject() {
    cout << "Введите новый объект: ";
    cin >> rec;
}

void NOTE::inputFromConsole()
{
    cout << "Введите тип: ";
    cin >> rec;
}
