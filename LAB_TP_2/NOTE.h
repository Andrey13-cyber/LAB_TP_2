#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include "errorProc.h"

using namespace std;

class NOTE
{
private:
    string name = "";
    long long number;
    int arrDate[3];
public:
    NOTE();
    NOTE(string name, int arrDate[3], long long number);
    NOTE(const NOTE& note);
    ~NOTE() {
            cout << "Вызван деструктор NOTE" << endl;
    }
    void changeObject();
    void printToConsole();
    void inputFromConsole();
    void setName(string name);
    void setDate(const int* arrDate);
    void setNumber(long long number);
    int* getDate();
    string getName();
    long long getNumber();
    NOTE& operator = (const NOTE& note);
    bool operator > (const NOTE& note);
};

