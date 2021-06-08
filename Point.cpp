#include "Point.h"
#include<iostream>
using namespace std;
Point::Point()
{
	niuniu = false;
	point[0] =0 ;
	point[1] = 0;
}
int Point::getPoint()
{
	return point[0];
}
bool Point::getNiuniu()
{
	return niuniu;
}
int Point::getSpecialCard()
{
	return point[1];
}
void Point::countPonit(int position, int people, int player[][5])
{
	int a[5] = {0};
	for (int i = 0; i < 5; i++)
	{
		a[i] = player[position][i]%13;
		if (a[i]  > 9)
		{
			a[i] = 9;
		}
	}
	if (niuniu)
	{
		for (int i = 0; i < 5; i++)
		{
			point[0] += a[i]+1;
		}
		point[0] = point[0] %10;
		if (point[0] == 0)
		{
			for (int i = 0, x = 0, y = 0; i < 5; i++)
			{
				if (player[position][i] % 13 >= 10)
				{
					x ++;
					if (x == 5)
					{
						point[1] = 3;
					}
				}
				else if (player[position][i] % 13 <= 9)
				{
					y ++;
					if (y == 5)
					{
						point[1] = 2;
					}
				}
				if (i == 4 && (x != 5 && y != 5))
				{
					point[1] = 1;
				}
			}
		}
	}
	else
	{
		int max = 0;
		for (int i = 0; i < 5; i++)
		{
			if (i == 0)
			{
				max = player[position][i]%13;
			}
			else if (player[position][i]%13 > max)
			{
				max = player[position][i]%13;
			}
		}
		point[0] = max + 1;
	}
}
void Point::comparePoint(Point a,int position,Player b[9], int* p)
{
	if (this->getNiuniu())
	{
		if (this->getNiuniu() && a.getNiuniu())
		{
			if (this->getPoint() == 0 || a.getPoint()==0)
			{
				if (this->getSpecialCard() > a.getSpecialCard())
				{
					cout << "玩家" << position + 1 << "勝";
					switch (this->getSpecialCard())
					{
					case 1:b[position].setMoney(b[position].getBet() * 2 , p);
						break;
					case 2:b[position].setMoney(b[position].getBet() * 5, p);
						break;
					case 3:b[position].setMoney(b[position].getBet() * 8, p);
						break;
					}
				}
				else if (this->getSpecialCard() == a.getSpecialCard())
				{
					cout << "平手";
				}
				else
				{
					cout << "莊家勝";
					switch (a.getSpecialCard())
					{
					case 1:b[position].setMoney(-(b[position].getBet() * 2), p);
						break;
					case 2:b[position].setMoney(-(b[position].getBet() * 5), p);
						break;
					case 3:b[position].setMoney(-(b[position].getBet() * 8), p);
						break;
					}
				}
			}
			else
			{
				if (this->getPoint() > a.getPoint())
				{
					cout << "玩家" << position + 1 << "勝";
					b[position].setMoney((b[position].getBet()), p);
				}
				else if (this->getPoint() == a.getPoint())
				{
					cout << "平手";
				}
				else
				{
					cout << "莊家勝";
					b[position].setMoney(-(b[position].getBet()), p);
				}
			}

		}
		else
		{
			cout << "玩家" << position + 1 << "勝";
			switch (this->getSpecialCard())
			{
			case 1:b[position].setMoney(b[position].getBet() * 2, p);
				break;
			case 2:b[position].setMoney(b[position].getBet() * 5, p);
				break;
			case 3:b[position].setMoney(b[position].getBet() * 8, p);
				break;
			default:b[position].setMoney(b[position].getBet(), p);
			}
		}
	}
	else
	{
		if (this->getNiuniu() == a.getNiuniu())
		{
			if (this->getPoint() > a.getPoint())
			{
				cout << "玩家" << position + 1 << "勝";
				b[position].setMoney(+(b[position].getBet()), p);
			}
			else if(this->getPoint() == a.getPoint())
			{
				cout << "平手";
			}
			else
			{
				cout << "莊家勝";
				b[position].setMoney(-(b[position].getBet()), p);
			}
		}
		else
		{
			cout << "莊家勝";
			switch (a.getSpecialCard())
			{
			case 1:b[position].setMoney(-(b[position].getBet() * 2), p);
				break;
			case 2:b[position].setMoney(-(b[position].getBet() * 5), p);
				break;
			case 3:b[position].setMoney(-(b[position].getBet() * 8), p);
				break;
			default:b[position].setMoney(-(b[position].getBet()), p);
			}
		}
	}
}
void Point::printPoint()
{
	if (niuniu)
	{
		if (point[0] != 0)
		{
			cout << "妞" << point[0];
		}
		else
		{
			switch (point[1])
			{
			case 3:cout << "國王妞妞";
				break;
			case 2:cout << "數字妞妞";
				break;
			case 1:cout << "妞妞";
			}
		}
	}
	else
	{
		switch (point[0])
		{
		case 1:cout << "A大";
			break;
		case 11:cout << "J大";
			break;
		case 12:cout << "Q大";
			break;
		case 13:cout << "K大";
			break;
		default:cout << point[0] << "大";
		}
	}
}

void Point::determineNiuniu(int position, int player[][5])
{
	int a[5] = {}, b = 0;
	for (int i = 0; i < 5; i++)
	{
		a[i] = player[position][i]%13;
		if (a[i]  > 9)
		{
			a[i] = 9;
		}
	}
	for (int i = 0; i <=2;i++)
	{
		for (int j = i+1; j <=3;j++)
		{
			for (int x = j+1; x <=4; x++, b = 0)
			{
				b = a[i] + a[j] + a[x] + 3;
				if (b % 10 == 0)
				{
					niuniu = true;;
				}
			}
		}
	}
}
