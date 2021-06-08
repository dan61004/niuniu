#pragma once
#include "Player.h"
class Point
{
private:
	bool niuniu;
	int point[2];
public:
	Point();
	int getPoint();
	bool getNiuniu();
	int getSpecialCard();
	void countPonit(int,int,int[][5]);
	void comparePoint(Point,int, Player [9], int* p);
	void printPoint();
	void determineNiuniu(int,int[][5]);
};

