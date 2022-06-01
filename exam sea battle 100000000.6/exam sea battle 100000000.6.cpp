#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Player.h"
using namespace std;



int main()
{
	SetConsoleOutputCP(1251);

	Pole pole;
	Player player;
	//pole.printPole(player);

	//const int ax = 0, ay = 0;

	int ship = 10;
	int x = 4; int y = 4, i = 0;
	int x1{}; int y1{};
	const int N = 10;
	char ch = 'X';
	char comp_map[N][N] = { 0 };
	bool detect = false;

	while (1) {
		char key = _getch();

		if (key == 'w') x--;
		if (key == 's') x++;
		if (key == 'a') y--;
		if (key == 'd') y++;
		if (x == 0 or x == 10 - 1 or y == 0 or y == 10 - 1) {//умова,за якої при виході за межі поля, змія повертається 
			x = 4;
			y = 4;
		}


		if (key == 'c' && i == 0) {
			ch = 'X';
			player.setX(x);
			player.setY(y);
			player.setCh(ch);
			system("cls");

			pole.printPole(player);
			i = 1;
			ship--;
		}
		else if (key == 'c' && i == 1) {
			ch = 'X';
			player.setX(x);
			player.setY(y);
			player.setCh(ch);
			system("cls");
			pole.printPole(player);
			i = 0;
			ship--;

		}

		else {
			system("cls");
			pole.printPole(x, y, '*');
		}

		cout << "Ship = " << ship << endl;
		cout << "Please do not put more than 10 " << endl;
		cout << "If you have exhibited all 10 (11) ships press Q" << endl;

		char vod = _getch();
		char klir = _getch();

		if (vod == 'q') {
			while (true)
			{
				cout << "Введіть координати корабля ворожого по осі X" << endl;
				cin >> x;
				cout << "Введіть координати корабля ворожого по осі Y" << endl;
				cin >> y;

				if (comp_map[x][y] == 98)
				{
					cout << "Влучив" << endl;
					comp_map[x][y] = 0;

					bool detect = false;


					for (int i = 0; i < N; i++)
					{
						for (int j = 0; j < N; j++)
						{
							if (comp_map[i][j] == 98)
							{
								detect = true;
							}
						}
					}


					if (detect == false)
					{
						cout << "ви виграли!!" << endl;
						break;
					}

				}
				else
				{
					cout << "Промах" << endl;
				}

			}

		}

	}
}