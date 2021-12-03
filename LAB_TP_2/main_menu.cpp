#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include "NOTE.h"
#include "Keeper.h"
#include "Person.h"


using namespace std;
void menu();
int errorProc(int minValue, int maxValue);
void addObject(Keeper<NOTE*>& keeper);
void changeObject(Keeper<NOTE*>& keeper);
void deleteObject(Keeper<NOTE*>& keeper);
NOTE* createObj(string inf);
void printToConsole(Keeper<NOTE*>& keeper);
//void printToFile(Keeper<NOTE*>& keeper);
//void inputFromFile(Keeper<NOTE*>& keeper);

int printMonth();


void menu() {
    cout << endl << "----------------------------" << endl;
    cout << endl << "      ������� ����   " << endl;
    cout << endl << "----------------------------" << endl;

    cout << "1. �������� ������" << endl;
    cout << "2. �������� ������" << endl;
    cout << "3. ������� ������" << endl;
    cout << "4. ������� ������ �� �����" << endl;
    cout << "5. ������� ������ �� ������ �� �����" << endl;
    cout << "0. �����" << endl;
}

int errorProc(int minValue, int maxValue) {
    int place;
    while (1) {
        cin >> place;
        if (cin.fail() || place < minValue || place > maxValue) {
            cout << "������������ ����, ������� ��� ��� -> ";
            cin.clear();
            cin.ignore(65767, '\n');
        }
        else
            return place;
    }

}

int main() {
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Keeper<NOTE*> keeper;

    cout << "����������,������������. �������� ������." << endl;
    cout << endl;

    int step = 0;
    int selection;

    while (!step) {
        menu();
        cout << endl;
        cout << "������� ����� ����-> ";
        selection = errorProc(0, 4);
        cout << endl;
        switch (selection)
        {
        case 0:
            exit(0);
            cout << "����� �� ���������. �� ��������,������������ :)";
            break;

        case 1:
            addObject(keeper);
            break;

        case 2:
            changeObject(keeper);
            break;

        case 3:
            deleteObject(keeper);
            break;

        case 4:
            printToConsole(keeper);
            break;

        }
    }
}

    void addObject(Keeper<NOTE*>&keeper)
    {
        cout << "���������� �������: " << endl;
        cout << "1.������" << endl;
        cout << "-> ";
        int typeObj = errorProc(0, 1);
        string typeNote;
        if (typeObj == 1)
            typeNote = "������";
        NOTE* object = createObj(typeNote);
        object->inputFromConsole();
        keeper.pushback(object);
    }



    void changeObject(Keeper<NOTE*>& keeper)
    {
        if (keeper.getLenght() == 0)
            cout << "��������� ����. ������ ��������" << endl;
        else
        {
            printToConsole(keeper);
            cout << endl;
            cout << "�������� ����� ������� ��� ���������: ";
            int number = errorProc(1, keeper.getLenght());
            keeper[number - 1]->changeObject();
        }
    }

    void deleteObject(Keeper<NOTE*>& keeper)
    {
        if (keeper.getLenght() == 0)
            cout << "��������� ����. ������ �������" << endl;
        else
        {
            printToConsole(keeper);
            cout << "�������� ����� ������� ��� ��������: ";
            int number = errorProc(1, keeper.getLenght());
            keeper.popindex(number - 1);
        }
    }

    NOTE* createObj(string inf)
    {
        if (inf == "������")
            return new Person();
        string err = "��� ������� �� ���������";
        throw err;
    }


    void printToConsole(Keeper<NOTE*>& keeper) {
        if (keeper.getLenght() == 0)
            cout << "��������� ����" << endl;
        else
        {
            cout << "���������� ����������: " << endl;
            for (int i = 0; i < keeper.getLenght(); i++)
            {
                cout << endl;
                cout << i + 1 << ". ";
                keeper[i]->printToConsole();
            }
        }
    }

   