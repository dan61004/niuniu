#include<iostream>
#include<iomanip>
#include "card.h"
#include "Player.h"
#include "Point.h"
using namespace std;
int main()
{
	int people;
	cout << "請輸入玩家人數:";
	cin >> people;
	cout << endl;
	while (people == 0 || people > 9)
	{
		cout << "請重新輸入玩家人數:";
		cin >> people;
		cout << endl;
	}
	int Continue = people;
	int* pContinue = &Continue;
	Player a1[9] = {};
	for (int i = 0,a; i < people; i++)
	{
		cout << "請輸入玩家" << i +1<< "的金額:";
		cin >> a;
		a1[i].playerMoney(a);
		cout << endl;
	}
	int player[10][5] = {};
	char a2;
	Card a;
	Point a3[10];
	a.Shuffle();
	a.Licensing(people, player);
	for (int i = 0; i <= people; i++)
	{
		a3[i].determineNiuniu(i,player);
		a3[i].countPonit(i, people, player);
	}
	a.printallCard(people, player,a3, pContinue,a1);
	while (Continue!=0)
	{
		a.Shuffle();
		a.Licensing(people, player);
		for (int i = 0; i <= people; i++)
		{
			a3[i].determineNiuniu(i, player);
			a3[i].countPonit(i, people, player);
		}
		for (int i = 0; i < people; i++)
		{
			if(a1[i].getMoney() > 0 && a1[i].getY_or_n())
			{
				cout << "請問玩家" << i + 1 << "要繼續嗎?(Y/N)";
				cin >> a2;
				cout << endl;
				a1[i].setY_or_n(a2,pContinue);
			}
		}
		for (int i = 0; i <= people; i++)
		{

			if (Continue != 0)
			{
				if (i == people)
				{
					a.printCard(people, people, player, a3, pContinue, a1);
				}
				else if (a1[i].getMoney() > 0 && a1[i].getY_or_n())
				{
					a.printCard(i, people, player, a3, pContinue, a1);
				}
				else
				{
					cout << "玩家" << i + 1 << "Gameover!!" << endl << endl;
				}
			}
		}

	}
}


