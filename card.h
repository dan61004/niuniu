#pragma once
#include "Point.h"
#include "Player.h"
class Card
{
private:
	int card[52] = {  };
public:
	Card();
	void Shuffle();
	void printallCard(int,int [][5],Point[10],int*, Player [9]);
	void Licensing(int,int[][5]);
	void printCard(int,int, int [][5], Point [10], int* , Player [9]);
	
};

