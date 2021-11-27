#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include "NOTE.h"


using namespace std;



void menu() {
    cout << "1. Ввести информацию о человеке." << endl;
    cout << "2. Вывести информацию о человеке. " << endl;
    cout << "3. Запись данных в файл. " << endl;
    cout << "4. Вывод данных из файла. " << endl;
    cout << "0.Выход" << endl;
}

int main() {
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Здравствуй,пользователь. Начинаем работу." << endl;
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
        cout << "Введите пункт меню-> ";

        cin >> selection;
        switch (selection)
        {
        case 0:
            exit(0);
            cout << "Выход из программы. До свидания,пользователь :)";
            break;


        case 1:
            cout << "Введите Имя: ";
            getline(cin, name);
            getline(cin, name);
            cout << "Введите Фамилию: ";
            cin >> surname;
            cout << "Введите дату рождения: ";
            cin >> birthDate;
            cout << "Введите номер телефона: ";
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
            cout << "Данные записаны в файл)" << endl;
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