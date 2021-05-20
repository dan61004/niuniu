#include "card.h"
#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;
Card::Card()
{
	for (int i = 0; i < 52; i++)
	{
		card[i] = i;
	}
}
void Card::printallCard(int people, int player[][5],Point a[10],int*p,Player b[9])
{
	for (int i = 0; i <= people; i++)
	{
		if (i == people)
		{
			cout << "莊家的牌: ";
		}
		else
		{
			cout << "玩家" << i+1 << "的牌:";
		}
		for (int j = 0; j < 5; j++)
		{
			if (player[i][j] / 13==0)
			{
				cout << " 梅花";
			}
			else if (player[i][j] / 13 == 1)
			{
				cout << " 菱形";
			}
			else if (player[i][j] / 13 == 2)
			{
				cout << " 愛心";
			}
			else
			{
				cout<< " 黑桃";
			}
			switch (player[i][j] % 13)
			{
			case 0:cout << " A";
				break;
			case 10:cout << " J";
				break;
			case 11:cout << " Q";
				break;
			case 12:cout << " K";
				break;
			default:cout << setw(2) << player[i][j] % 13 + 1;
				break;
			}
		}
		cout << "  ";
		a[i].printPoint();
		cout << "  ";
		if (i!=people)
		{
			a[i].comparePoint(a[people],i,b,p);
			if (b[i].getMoney() > 0)
			{
				cout<<" " << "剩餘金額:" << b[i].getMoney();
			}
			else
			{
				cout << " " << "剩餘金額:0";
			}
		}
		cout << endl << endl;
	}
}
void Card::Shuffle()
{
	int a, pos;
	srand(time(NULL));
	for (int i = 0; i != 52; ++i)
	{
		pos = rand()%52;
		a = card[i];
		card[i] = card[pos];
		card[pos] = a;
	}
}
void Card::Licensing(int people,int player[][5])
{
	for (int y = 0,a=0; y <= people; y++)
	{
		for (int i = 0; i < 5;i++,a++)
		{
			player[y][i] = card[a];
		}
	}
}
void Card::printCard(int position, int people, int player[][5], Point a[10], int* p, Player b[9])
{
	
		if (position == people)
		{
			cout << "莊家的牌: ";
		}
		else
		{
			cout << "玩家" << position + 1 << "的牌:";
		}
		for (int j = 0; j < 5; j++)
		{
			if (player[position][j] / 13 == 0)
			{
				cout << " 梅花";
			}
			else if (player[position][j] / 13 == 1)
			{
				cout << " 菱形";
			}
			else if (player[position][j] / 13 == 2)
			{
				cout << " 愛心";
			}
			else
			{
				cout << " 黑桃";
			}
			switch (player[position][j] % 13)
			{
			case 0:cout << " A";
				break;
			case 10:cout << " J";
				break;
			case 11:cout << " Q";
				break;
			case 12:cout << " K";
				break;
			default:cout << setw(2) << player[position][j] % 13 + 1;
				break;
			}
		}
		cout << "  ";
		a[position].printPoint();
		cout << "  ";
		if (position != people)
		{
			a[position].comparePoint(a[people], position, b, p);
			if (b[position].getMoney() >0)
			{
				cout << " " << "剩餘金額:" << b[position].getMoney();
			}
			else
			{
				cout << " " << "剩餘金額:0";
			}
		}
		cout << endl << endl;
}