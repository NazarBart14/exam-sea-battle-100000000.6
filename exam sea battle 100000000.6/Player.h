#pragma once
#include <iostream>
#include <conio.h>
#include <cstring>
using std::cout;
using std::endl;
using std::ostream;
using std::istream;


class Player
{
private:
	int x;
	int y;
	char ch{};
public:

	Player() { x = 1; y = 1; }
	int printX() { return this->x; }
	int printY() { return this->y; }
	int getX() { return this->x; }
	int getY() { return this->y; }
	char getCh() { return this->ch; }

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setCh(char ch) { this->ch = ch; }

};

class Pole {
private:

	int n;
	int m;
	char** matrix;
	int step;



public:
	Pole(void);
	void printPole(Player& player);
	void printPole(int, int, char);
	bool getWinner();

};


class PcPole {
private:




	PcPole(int ox, int oy, bool detect, char** comp_map);

};
