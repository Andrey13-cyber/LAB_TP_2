#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include "NOTE.h"
#include "Keeper.h"
#include "errorProc.h"



using namespace std;
void menu();
void addObject(Keeper<NOTE*>& keeper);
void changeObject(Keeper<NOTE*>& keeper);
void deleteObject(Keeper<NOTE*>& keeper);
NOTE* createObj(string inf);
void printToConsole(Keeper<NOTE*>& keeper);
void printToMonthConsole(Keeper<NOTE*>& keeper);
void addNewPosition(Keeper<NOTE*>& keeper);



void menu() {
    cout << endl << "----------------------------" << endl;
    cout << endl << "      ������� ����   " << endl;
    cout << endl << "----------------------------" << endl;

    cout << "1. �������� ������" << endl;
    cout << "2. �������� ������ �� ����� �������" << endl;
    cout << "3. �������� ������" << endl;
    cout << "4. ������� ������" << endl;
    cout << "5. ������� ������ �� �����" << endl;
    cout << "6. ������� ������ �� ������ �� �����" << endl;
    cout << "0. �����" << endl;
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
        selection = errorProc(0, 6);
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
            addNewPosition(keeper);
            break;

        case 3:
            changeObject(keeper);
            break;

        case 4:
            deleteObject(keeper);
            break;

        case 5:
            printToConsole(keeper);
            break;

        case 6:
            printToMonthConsole(keeper);
            break;


        }
    }
}

void addObject(Keeper<NOTE*>& keeper)
{
    NOTE* object = new NOTE();
    object->inputFromConsole();
    keeper.pushback(object);
    keeper.sortAlphabet();
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
        keeper.sortAlphabet();
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
        return new NOTE();
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



void printToMonthConsole(Keeper<NOTE*>& keeper) {
    if (keeper.getLenght() == 0)
        cout << "��������� ����" << endl;
    else
    {

        int month;
        bool vivod = false;
        cout << "������� ����� ��������: " << endl;
        cout << "-> ";
        cin >> month;
        for (int i = 0; i < keeper.getLenght(); i++)
        {

            if (month == keeper[i]->getDate()[1]) {
                keeper[i]->printToConsole();
                vivod = true;
            }

        }
        if (!vivod)
            cout << "������ � ����� ������� �������� �����������." << endl;

    }
}


void addNewPosition(Keeper<NOTE*>& keeper) {
    
    cout << "������� ������, �� ������� ������ �������� ������(0-" << keeper.getLenght() << "): ";
    int index = errorProc(0, keeper.getLenght() );
    NOTE* object = new NOTE();
    object->inputFromConsole();
    keeper.push(object, index);
    keeper.sortAlphabet();
}
