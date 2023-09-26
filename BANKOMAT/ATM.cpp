#include "ATM.h"
#include <iostream>
#include <string>
using namespace std;

ATM::ATM(int id, int bal, int max, int min,string denoms)
{
	atmid = id;
	balance = bal;
	maxwdraw = max;
	minwdraw = min;
	codes = denoms;
}
void ATM::PrintATM()
{
	cout << "ATM ID: " << atmid << endl;
	cout << "BALANCE: " << balance << endl;
	cout << "MAX WITHDRAW: " << maxwdraw << endl;
	cout << "MIN WITHDRAW: " << minwdraw << endl;
	cout << "AVAILABLE DENOMINATIONS: ";
	size_t found;
	if (codes.find("1") != string::npos)
		cout << "10 ";
	if (codes.find("2") != string::npos)
		cout << "20 ";
	if (codes.find("3") != string::npos)
		cout << "50 ";
	if (codes.find("4") != string::npos)
		cout << "100 ";
	if (codes.find("5") != string::npos)
		cout << "200 ";
	if (codes.find("6") != string::npos)
		cout << "500 ";
	if (codes.find("7") != string::npos)
		cout << "1000 " << endl;
}
void ATM::initATM(int id, int bal, int max, int min, string denoms)
{
	atmid = id;
	balance = bal;
	maxwdraw = max;
	minwdraw = min;
	codes = denoms;
}
void ATM::fillATM(int cash, string denoms)
{
	balance += cash;
	if (denoms.find("1") != string::npos && codes.find("1") == string::npos)
		codes += '1';
	if (denoms.find("2") != string::npos && codes.find("2") == string::npos)
		codes += '2';
	if (denoms.find("3") != string::npos && codes.find("3") == string::npos)
		codes += '3';
	if (denoms.find("4") != string::npos && codes.find("4") == string::npos)
		codes += '4';
	if (denoms.find("5") != string::npos && codes.find("5") == string::npos)
		codes += '5';
	if (denoms.find('6') != string::npos && codes.find("6") == string::npos)
		codes += "6";
	if (denoms.find('7') != string::npos && codes.find("7") == string::npos)
		codes += "7";
}
bool ATM::isSummAble(int a)
{
	if (a > balance || a >maxwdraw|| a<minwdraw || a%10!=0)
		return 0;
	if (a % 10 == 0 && codes.find('1') != string::npos)
		return 1;
	if (a % 20 == 0 && codes.find('2') != string::npos)
		return 1;
	if (a % 50 == 0 && codes.find('3') != string::npos)
		return 1;
	if (a % 100 == 0 && codes.find('4') != string::npos)
		return 1;
	if (a % 200 == 0 && codes.find('5') != string::npos)
		return 1;
	if (a % 500 == 0 && codes.find('6') != string::npos)
		return 1;
	if (a % 1000 == 0 && codes.find('7') != string::npos)
		return 1;
	return 0;
}
void ATM::withdrawATM()
{
	cout << "Max Withdraw: " << maxwdraw << endl;
	cout << "Min Withdraw: " << minwdraw << endl;
	cout << "ATM Balance: " << balance << endl;
	cout << "Denominations: ";
	if (codes.find("1") != string::npos)
		cout << "10 ";
	if (codes.find("2") != string::npos)
		cout << "20 ";
	if (codes.find("3") != string::npos)
		cout << "50 ";
	if (codes.find("4") != string::npos)
		cout << "100 ";
	if (codes.find("5") != string::npos)
		cout << "200 ";
	if (codes.find("6") != string::npos)
		cout << "500 ";
	if (codes.find("7") != string::npos)
		cout << "1000 " << endl;
	int a;
	cout << "Enter the amountf to withdraw: ";
	cin >> a;
	while (!(isSummAble(a)))
	{
		cout << "Wrong amount" << endl;
		cout << "Enter the amountf to withdraw: ";
		cin >> a;
	}
	balance -= a;
	maxwdraw -= a;
	cout << "Success!" << endl;
}
string ATM::toString()
{
	string t;
	int a = balance;
	for (size_t i = 0; a > 0; i++)
	{
		if (a % 10 == 1)
		{
			t += '1';
		}
		if (a % 10 == 2)
		{
			t += '2';
		}
		if (a % 10 == 3)
		{
			t += '3';
		}
		if (a % 10 == 4)
		{
			t += '4';
		}
		if (a % 10 == 5)
		{
			t += '5';
		}
		if (a % 10 == 6)
		{
			t += '6';
		}
		if (a % 10 == 7)
		{
			t += '7';
		}
		if (a % 10 == 8)
		{
			t += '8';
		}
		if (a % 10 == 9)
		{
			t += '9';
		}
		if (a % 10 == 0)
		{
			t += '0';
		}
		a /= 10;
	}
	reverse(t.begin(),t.end());
	return t;
}