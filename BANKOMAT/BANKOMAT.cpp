// BANKOMAT.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "ATM.h"
using namespace std;

int main()
{
    ATM a(101, 1000, 40, 20, "3");
    a.withdrawATM();
    string t = a.toString();
    cout << t;
}

