#pragma once
class Player
{
private:
	bool y_or_n;
	int money;
	int bet;
public:
	Player();
	Player(bool, int);
	bool getY_or_n() const;
	int getMoney() const;
	void setMoney(int,int*);
	void setY_or_n(char,int*);
	void playerMoney(int);
	int getBet() const;
};

