/*
тот кто будет пытаться разобраться в моём коде будет страдать, ибо я положил болт на нормальную структуризацию кода, а тем более на адекватное называние переменных, такая вот у меня больная бошка)
автор:Depozit
*/

#pragma once
#include <iostream>

int chekWin(int map[]) {  //return 0 - нет победы, 1 - х победил, 2 - о победил 

	if (
		//горизонталь
		((map[0] == 1) && (map[0] == map[1]) && (map[1] == map[2])) ||
		((map[3] == 1) && (map[3] == map[4]) && (map[4] == map[5])) ||
		((map[6] == 1) && (map[6] == map[7]) && (map[6] == map[8])) ||
		//вертикаль
		((map[0] == 1) && (map[0] == map[3]) && (map[6] == map[3])) ||
		((map[1] == 1) && (map[1] == map[4]) && (map[1] == map[7])) ||
		((map[2] == 1) && (map[2] == map[5]) && (map[2] == map[8])) ||
		//диагональ
		((map[0] == 1) && (map[0] == map[4]) && (map[0] == map[8])) ||
		((map[2] == 1) && (map[2] == map[4]) && (map[2] == map[6])))
		return 1;
	else if (
		//горизонталь
		((map[0] == 0) && (map[0] == map[1]) && (map[1] == map[2])) ||
		((map[3] == 0) && (map[3] == map[4]) && (map[4] == map[5])) ||
		((map[6] == 0) && (map[6] == map[7]) && (map[6] == map[8])) ||
		//вертикаль
		((map[0] == 0) && (map[0] == map[3]) && (map[6] == map[3])) ||
		((map[1] == 0) && (map[1] == map[4]) && (map[1] == map[7])) ||
		((map[2] == 0) && (map[2] == map[5]) && (map[2] == map[8])) ||
		//диагональ
		((map[0] == 0) && (map[0] == map[4]) && (map[0] == map[8])) ||
		((map[2] == 0) && (map[2] == map[4]) && (map[2] == map[6])))
		return 2;
	else {
		return 0;
	}
}


int logic(int* map,int Smap[9], int move) {
	
	*map = move % 2;

	int win = chekWin(Smap);
	
	return win;
}


int ChekPos(sf::Vector2i mouse) {

	int pos = 10;
	int x = mouse.x;
	int y = mouse.y;

	if ((x < 550 && x>50) && (y < 600 && y>100)) {

		if (x < 216) {//1 строка

			if (y < 266) {//1 столбец
				pos = 0;
			}
			else if (y > 434) {//3 столбец
				pos = 6;
			}
			else {//2 столбец
				pos = 3;
			}

		}
		else if (x > 382) { // 3 строка

			if (y < 266) {//1 столбец
				pos = 2;
			}
			else if (y > 434) {//3 столбец
				pos = 8;
			}
			else {//2 столбец
				pos = 5;
			}

		}
		else {//2 строка

			if (y < 266) {//1 столбец
				pos = 1;
			}
			else if (y > 434) {//3 столбец
				pos = 7;
			}
			else {//2 строка
				pos = 4;
			}

		}

	}
	
	return pos;
}