#include "NOTE.h"

NOTE::NOTE(string rec) : rec(rec)
{
    cout << "������ ����������� NOTE" << endl;
}
NOTE::NOTE(const NOTE& note) : rec(note.rec)
{
    cout << "������ ����������� ����������� NOTE" << endl;
}


void NOTE::printToConsole()
{
    cout << rec << endl;
}

void NOTE::changeObject() {
    cout << "������� ����� ������: ";
    cin >> rec;
}

void NOTE::inputFromConsole()
{
    cout << "������� ���: ";
    cin >> rec;
}
