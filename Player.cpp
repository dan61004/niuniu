#include "Player.h"
#include<iostream>
using namespace std;
Player::Player()
{
	y_or_n=true;
	money=0;
	bet = 0;
}
Player::Player(bool a, int b)
{
	y_or_n = a;
	money = b;
	bet = b;
}
bool Player::getY_or_n() const
{
	return y_or_n;
}
int Player::getMoney() const
{
	return money;
}
void Player::playerMoney(int a)
{
	if (a > 0)
	{
		money = a;
		bet = money;
	}
	else
	{
		int b;
		cout << "�Э��s��J���a���B:";
		cin >> b;
		playerMoney(b);
	}
}
void Player::setY_or_n(char a,int *p)
{
	if (a == 'N' || a == 'Y' || a=='n' || a=='y')
	{
		if (a == 'N' || a=='n')
		{
			y_or_n = false;
			*p -= 1;
			cout << "�w��A��>_<" << endl<<endl;
		}
	}
	else
	{
		char b;
		cout << "�аݧA���n�~���?(Y/N)";;
		cin >> b;
		cout << endl;
		setY_or_n(b,p);
	}
}
int Player::getBet() const
{
	return bet;
}

void Player::setMoney(int a, int* p)
{
	money += a;
	if (money <= 0)
	{
		*p -= 1;
	}
}
