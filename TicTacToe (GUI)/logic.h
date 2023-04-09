/*
òîò êòî áóäåò ïûòàòüñÿ ðàçîáðàòüñÿ â ìî¸ì êîäå áóäåò ñòðàäàòü, èáî ÿ ïîëîæèë áîëò íà íîðìàëüíóþ ñòðóêòóðèçàöèþ êîäà, à òåì áîëåå íà àäåêâàòíîå íàçûâàíèå ïåðåìåííûõ, òàêàÿ âîò ó ìåíÿ áîëüíàÿ áîøêà)
àâòîð:Depozit 1
*/

#pragma once
#include <iostream>

int chekWin(int map[]) {  //return 0 - íåò ïîáåäû, 1 - õ ïîáåäèë, 2 - î ïîáåäèë 

	if (
		//ãîðèçîíòàëü
		((map[0] == 1) && (map[0] == map[1]) && (map[1] == map[2])) ||
		((map[3] == 1) && (map[3] == map[4]) && (map[4] == map[5])) ||
		((map[6] == 1) && (map[6] == map[7]) && (map[6] == map[8])) ||
		//âåðòèêàëü
		((map[0] == 1) && (map[0] == map[3]) && (map[6] == map[3])) ||
		((map[1] == 1) && (map[1] == map[4]) && (map[1] == map[7])) ||
		((map[2] == 1) && (map[2] == map[5]) && (map[2] == map[8])) ||
		//äèàãîíàëü
		((map[0] == 1) && (map[0] == map[4]) && (map[0] == map[8])) ||
		((map[2] == 1) && (map[2] == map[4]) && (map[2] == map[6])))
		return 1;
	else if (
		//ãîðèçîíòàëü
		((map[0] == 0) && (map[0] == map[1]) && (map[1] == map[2])) ||
		((map[3] == 0) && (map[3] == map[4]) && (map[4] == map[5])) ||
		((map[6] == 0) && (map[6] == map[7]) && (map[6] == map[8])) ||
		//âåðòèêàëü
		((map[0] == 0) && (map[0] == map[3]) && (map[6] == map[3])) ||
		((map[1] == 0) && (map[1] == map[4]) && (map[1] == map[7])) ||
		((map[2] == 0) && (map[2] == map[5]) && (map[2] == map[8])) ||
		//äèàãîíàëü
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

		if (x < 216) {//1 ñòðîêà

			if (y < 266) {//1 ñòîëáåö
				pos = 0;
			}
			else if (y > 434) {//3 ñòîëáåö
				pos = 6;
			}
			else {//2 ñòîëáåö
				pos = 3;
			}

		}
		else if (x > 382) { // 3 ñòðîêà

			if (y < 266) {//1 ñòîëáåö
				pos = 2;
			}
			else if (y > 434) {//3 ñòîëáåö
				pos = 8;
			}
			else {//2 ñòîëáåö
				pos = 5;
			}

		}
		else {//2 ñòðîêà

			if (y < 266) {//1 ñòîëáåö
				pos = 1;
			}
			else if (y > 434) {//3 ñòîëáåö
				pos = 7;
			}
			else {//2 ñòðîêà
				pos = 4;
			}

		}

	}
	
	return pos;
}
