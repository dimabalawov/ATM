#include <iostream>
using namespace std;
#pragma once
class ATM
{
	int atmid;
	int balance;
	int maxwdraw;
	int minwdraw;
	string codes; //available denominations
	//1 - 10
	//2 - 20
	//3 - 50
	//4 - 100
	//5 - 200
	//6 - 500
	//7 - 1000
	//f.e. string("1257) containts denominations 10 20 200 1000
public:
	ATM()=default;
	ATM(int id, int bal, int max, int min,string denoms);
	void PrintATM();
	void initATM(int id, int bal, int max, int min, string denoms);
	void fillATM(int cash,string denoms);
	void withdrawATM();
	bool isSummAble(int a);
	string toString();
};

