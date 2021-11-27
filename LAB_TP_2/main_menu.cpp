#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include "NOTE.h"


using namespace std;



void menu() {
    cout << "1. ������ ���������� � ��������." << endl;
    cout << "2. ������� ���������� � ��������. " << endl;
    cout << "3. ������ ������ � ����. " << endl;
    cout << "4. ����� ������ �� �����. " << endl;
    cout << "0.�����" << endl;
}

int main() {
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "����������,������������. �������� ������." << endl;
    cout << endl;

    menu();
    int step = 0;
    int selection;
    ofstream fout("NOTE.txt");
    string line;
    ifstream fin("NOTE.txt");
    string birthDate;
    string name;
    string surname;
    string number;
    NOTE a(name, birthDate, surname, number);
    
    while (!step) {
        cout << endl;
        cout << "������� ����� ����-> ";

        cin >> selection;
        switch (selection)
        {
        case 0:
            exit(0);
            cout << "����� �� ���������. �� ��������,������������ :)";
            break;


        case 1:
            cout << "������� ���: ";
            getline(cin, name);
            getline(cin, name);
            cout << "������� �������: ";
            cin >> surname;
            cout << "������� ���� ��������: ";
            cin >> birthDate;
            cout << "������� ����� ��������: ";
            cin >> number;
            cout << endl;
            a.setNote(name, birthDate, surname, number);
            break;

        case 2:
            a.print();
            cout << endl;
            break;

        case 3:

            a.printToFile(fout);
            fout.close();
            cout << "������ �������� � ����)" << endl;
            break;

        case 4:

            if (fin.is_open())
            {
                while (getline(fin, line))
                {
                    cout << line << endl;
                }
            }

            fin.close();
            break;
        }
    }

}