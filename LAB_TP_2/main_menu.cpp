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
    cout << endl << "      Главное меню   " << endl;
    cout << endl << "----------------------------" << endl;

    cout << "1. Добавить объект" << endl;
    cout << "2. Изменить объект" << endl;
    cout << "3. Удалить объект" << endl;
    cout << "4. Вывести записи на экран" << endl;
    cout << "5. Вывести запись по месяцу на экран" << endl;
    cout << "0. Выход" << endl;
}

int errorProc(int minValue, int maxValue) {
    int place;
    while (1) {
        cin >> place;
        if (cin.fail() || place < minValue || place > maxValue) {
            cout << "Некорректный ввод, введите еще раз -> ";
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

    cout << "Здравствуй,пользователь. Начинаем работу." << endl;
    cout << endl;

    int step = 0;
    int selection;

    while (!step) {
        menu();
        cout << endl;
        cout << "Введите пункт меню-> ";
        selection = errorProc(0, 4);
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
        cout << "Добавление объекта: " << endl;
        cout << "1.Запись" << endl;
        cout << "-> ";
        int typeObj = errorProc(0, 1);
        string typeNote;
        if (typeObj == 1)
            typeNote = "Запись";
        NOTE* object = createObj(typeNote);
        object->inputFromConsole();
        keeper.pushback(object);
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
            return new Person();
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

   