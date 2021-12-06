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
    cout << endl << "      Главное меню   " << endl;
    cout << endl << "----------------------------" << endl;

    cout << "1. Добавить объект" << endl;
    cout << "2. Добавить объект на любую позицию" << endl;
    cout << "3. Изменить объект" << endl;
    cout << "4. Удалить объект" << endl;
    cout << "5. Вывести записи на экран" << endl;
    cout << "6. Вывести записи по месяцу на экран" << endl;
    cout << "0. Выход" << endl;
}



int main() {
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Keeper<NOTE*> keeper;

    cout << "Здравствуй,пользователь. Начинаем работу." << endl;
    cout << endl;

    int step = 0;
    int selection;

    while (!step) {
        menu();
        cout << endl;
        cout << "Введите пункт меню-> ";
        selection = errorProc(0, 6);
        cout << endl;
        switch (selection)
        {
        case 0:
            exit(0);
            cout << "Выход из программы. До свидания,пользователь :)";
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
        cout << "Контейнер пуст. Нечего изменять" << endl;
    else
    {
        printToConsole(keeper);
        cout << endl;
        cout << "Выберете номер объекта для изменения: ";
        int number = errorProc(1, keeper.getLenght());
        keeper[number - 1]->changeObject();
        keeper.sortAlphabet();
    }
}

void deleteObject(Keeper<NOTE*>& keeper)
{
    if (keeper.getLenght() == 0)
        cout << "Контейнер пуст. Нечего удалять" << endl;
    else
    {
        printToConsole(keeper);
        cout << "Выберете номер объекта для удаления: ";
        int number = errorProc(1, keeper.getLenght());
        keeper.popindex(number - 1);
    }
}

NOTE* createObj(string inf)
{
    if (inf == "Запись")
        return new NOTE();
    string err = "Тип объекта не распознан";
    throw err;
}


void printToConsole(Keeper<NOTE*>& keeper) {
    if (keeper.getLenght() == 0)
        cout << "Контейнер пуст" << endl;
    else
    {
        cout << "Содержимое контейнера: " << endl;
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
        cout << "Контейнер пуст" << endl;
    else
    {

        int month;
        bool vivod = false;
        cout << "Введите месяц рождения: " << endl;
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
            cout << "Записи с таким месяцем рождения отсутствуют." << endl;

    }
}


void addNewPosition(Keeper<NOTE*>& keeper) {
    
    cout << "Введите индекс, на который хотите добавить объект(0-" << keeper.getLenght() << "): ";
    int index = errorProc(0, keeper.getLenght() );
    NOTE* object = new NOTE();
    object->inputFromConsole();
    keeper.push(object, index);
    keeper.sortAlphabet();
}
