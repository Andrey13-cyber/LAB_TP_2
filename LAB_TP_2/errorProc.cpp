#include "errorProc.h"

long long errorProc(long long minValue, long long maxValue) {
    long long place;
    while (1) {
        cin >> place;
        if (cin.fail() || place < minValue || place > maxValue) {
            cout << "Некорректный ввод, введите еще раз -> ";
            cin.clear();
            cin.ignore(65767, '\n');
        }
        else {
            cin.clear();
            cin.ignore(65767, '\n');
            return place;
        }

    }

}