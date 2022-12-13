#include <iostream>
#include <string>
#include <map> //словари
#include <array>

using std::cin;
using std::map;
using std::string;
using std::array;
using std::stoi;
using std::array;



void draw(int figure,int pos) {
	//рисует что либо считывая id фигуры по кордам gameMap[i][x(y)]
}

string CL_list(int idColor) { //CL_list <=> Color list. receive the color id, returns the hex color code // а почему я использую HEX, да потому что я блять хочу, и в рот ебал чужое мнение, а ещё выглядит не плохо

	/*vector<int>RGB_channel;
	map<int, vector<int>>colorScheme;
	вектор из ргб в словаре (инициализация)*/

	map<int, string>targetColor; // int - id color; string - HEX code of color

	targetColor[1] = "#FF0000"; //red (250,0,0) 
	targetColor[2] = "#000000"; //black (0,0,0)
	targetColor[3] = "#FFFFFF"; //white (255,255,255)
	targetColor[4] = "#C0C0C0"; //silver (192,192,192)
	targetColor[5] = "#808080"; //gray (128,128,128)
	targetColor[6] = "#800000"; //maroon(бордовый) (128,0,0)
	targetColor[7] = "#B8860B"; //DarkGoldenRod (184,134,11)
	targetColor[8] = "#DAA520"; //GoldenRod (218,165,32)
	targetColor[9] = "#D2691E"; //chocolate (210,105,30)
	//сука забыл обычные цвета, но нахуй нам всё делать по божески.правда?
	targetColor[10] = "#00FF00"; //green (0,250,0)
	targetColor[11] = "#0000FF"; //blue (0,0,250)
	targetColor[12] = "#FF8C00"; //darkOrange (255,140,0)
	targetColor[13] = "#4B0082"; //indigo (75,0,130)
	targetColor[14] = "#6A5ACD"; //stateBlue (106,90,205)
	targetColor[15] = "#808000"; //olive (128,128,0)
	targetColor[16] = "#FA8072"; //salmon (250,128,114)
	targetColor[17] = "#00FA9A"; //MediumSpringGreen (0,250,154)
	targetColor[18] = "#66CDAA"; //MediumAquamarine (102,205,170)
	targetColor[19] = "#FFDAB9"; //PeachPuff (255,218,185)
	targetColor[20] = "#00FFFF"; //cyan (0,255,255)

	//может парсер на питоне для импорта +- 100 цветов? или я уже больной?
	
	return targetColor[idColor];
}

array<int,3> HEXtoRGB(string HEXCode) { //принимает 7-символьную строку (полный HEX код); Преобразует в int от 0 до 255 и в массив. нужна для конвертации в ргб
	// array блять ARRAY и бляский switch case
	int k;
	map<string, int>convert;
	convert["0"] = 0;
	convert["1"] = 1;
	convert["2"] = 2;
	convert["3"] = 3;
	convert["4"] = 4;
	convert["5"] = 5;
	convert["6"] = 6;
	convert["7"] = 7;
	convert["8"] = 8;
	convert["9"] = 9;
	convert["A"] = 10;
	convert["B"] = 11;
	convert["C"] = 12;
	convert["D"] = 13;
	convert["E"] = 14;
	convert["F"] = 15;
	
	switch (1){
	case '0':k = 0; break;
	case '1':k = 1; break;
	case '2':k = 2; break;
	case '3':k = 3; break;
	case '4':k = 4; break;
	case '5':k = 5; break;
	case '6':k = 6; break;
	case '7':k = 7; break;
	case '8':k = 8; break;
	case '9':k = 9; break;
	case 'A':k = 10; break;
	case 'B':k = 11; break;
	case 'C':k = 12; break;
	case 'D':k = 13; break;
	case 'E':k = 14; break;
	case 'F':k = 15; break;
	}
	
	if (channel == 1) {
		//автор нихуя не понимает в плюсах так что, что бы вытащить из строки определённые символы и сделать их интами такая кривая система
		// приписка S1 или S2 обозначает шаг 1 или 2, а1 в свою очередь искомое нами интовое значение
		char a1_s1 = HEXCode[1];
		string a1_s2;
		a1_s2.push_back(a1_s1);
		int a1 = convert(a1_s2);
		
		char a2_s1 = HEXCode[2];
		string a2_s2;
		a2_s2.push_back(a2_s1);
		int a2 = stoi(a2_s2);
		
		return a1 + a2;

	}
	else if (channel == 2) {

		char a1_s1 = HEXCode[3];
		string a1_s2;
		a1_s2.push_back(a1_s1);
		int a1 = stoi(a1_s2) * 16;

		char a2_s1 = HEXCode[4];
		string a2_s2;
		a2_s2.push_back(a2_s1);
		int a2 = stoi(a2_s2);

		return a1 + a2;

	}
	else if (channel == 3) {

		char a1_s1 = HEXCode[5];
		string a1_s2;
		a1_s2.push_back(a1_s1);
		int a1 = stoi(a1_s2) * 16;

		char a2_s1 = HEXCode[6];
		string a2_s2;
		a2_s2.push_back(a2_s1);
		int a2 = stoi(a2_s2);

		return a1 + a2;
	}
	else {
		std::cout << "Error блять, автор кажется проебался";
		return 0;
	}
}


int main() {

	int gameMap[9][2];
	//9 - позиций для хода
	//2 - x и y по кордам для расположения в граф интрефесе
	//внести вручную или относительно окна x и y на каждое значение

	int gameStatus[9];
	for (int i = 0; i < 9; i++) {
		gameStatus[i] = 10;
	}
	//каждое из 9 значений отражает значение конкретной клетки 1- x, 2 - O, 10 - пусто

	//каждое обновление экрана
	for (int i = 0;i < 9;i++) {
		draw(gameStatus[i], i);
	}

	int color_back, color_game_field, color_x, color_o, color_win_combo;
	// помимо всего кастома сделать готовые цветовые схемы
	
	/*map<string, int[3]>color_scheme;
	int a[3];
	a[0] = 100;
	a[1] = 100;
	a[2] = 100;
	color_scheme["color_back"] = a;*/

}