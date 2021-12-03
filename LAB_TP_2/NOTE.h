#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Keeper.h"

using namespace std;

class NOTE
{
private:
	string rec;
	

public:
    NOTE(string rec);
    NOTE(const NOTE& note);
    ~NOTE() {
            cout << "Вызван деструктор NOTE" << endl;
    }
    virtual void changeObject() = 0;
    virtual void printToConsole();
    virtual void inputFromConsole();
};

