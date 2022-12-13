/*
тот кто будет пытаться разобраться в моём коде будет страдать, ибо я положил болт на нормальную структуризацию кода, а тем более на адекватное называние переменных, такая вот у меня больная бошка)
автор:Depozit
*/ 

#include "GameDraw.h"
#include "logic.h"
#include <iostream>

int StartMenu();

int main() {
	setlocale(LC_ALL, "ru");
	
	int a = StartMenu();
	if (a == 1) {
		int GameStatus[9] = { 10,10,10,10,10,10,10,10,10 };
		Play(GameStatus,0);
	}
	else {
		return 0;
	}
	
	
}


int StartMenu() {

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	
	sf::RenderWindow menu(sf::VideoMode(400, 300), "Tic Tac Toe", sf::Style::None, settings); //для добавление нескольких параметров | И ВСЁ БЛЯ, МЕЖДУ НИМИ СТАВИЬ И ВСЁ РОБИТ

	sf::CircleShape FrameButton(40.f);
	FrameButton.setFillColor(sf::Color(rgb1[0],rgb1[1],rgb1[2]));

	sf::RectangleShape Button(sf::Vector2f(300.f, 80.f));
	Button.setFillColor(sf::Color(rgb1[0], rgb1[1], rgb1[2]));
	


	sf::Font font;
	if (!font.loadFromFile("forTTT.ttf")) {
		std::cout << "pizdez" << std::endl;
	}

	sf::Text TTT;
	TTT.setFont(font);
	TTT.setString("Tic Tac Toe");
	TTT.setFillColor(sf::Color(rgb5[0], rgb5[1], rgb5[2]));
	TTT.setCharacterSize(40);
	TTT.setPosition(sf::Vector2f(45.f, 25.f));

	sf::Text start;
	start.setFont(font);
	start.setString(L"Играть!");
	start.setFillColor(sf::Color(rgb5[0], rgb5[1], rgb5[2]));
	start.setCharacterSize(40);
	start.setPosition(sf::Vector2f(110.f, 125.f));

	sf::Text exit;
	exit.setFont(font);
	exit.setString(L"Выход");
	exit.setFillColor(sf::Color(rgb5[0], rgb5[1], rgb5[2]));
	exit.setCharacterSize(40);
	exit.setPosition(sf::Vector2f(130.f, 225.f));


	while (menu.isOpen()) {

		sf::Event event;
		while (menu.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				menu.close();
			}

			sf::Vector2i localPosition = sf::Mouse::getPosition(menu);
			if  (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				if ((localPosition.y > 100 && localPosition.y < 200) && (localPosition.x>0 && localPosition.x<400)) {
					return 1;
				}
				else if ((localPosition.y > 200 && localPosition.y < 300) && (localPosition.x > 0 && localPosition.x < 400)) {
					return 0;
				}
			}
		}

		menu.clear(sf::Color(rgb[0], rgb[1], rgb[2]));

		/*FrameButton.setPosition(sf::Vector2f(10.f, 10.f));
		menu.draw(FrameButton);
		FrameButton.setPosition(sf::Vector2f(310.f, 10.f));
		menu.draw(FrameButton);
		Button.setPosition(sf::Vector2f(50.f, 10.f));
		menu.draw(Button);*/

		FrameButton.setPosition(sf::Vector2f(10.f, 110.f));
		menu.draw(FrameButton);
		FrameButton.setPosition(sf::Vector2f(310.f, 110.f));
		menu.draw(FrameButton);
		Button.setPosition(sf::Vector2f(50.f, 110.f));
		menu.draw(Button);

		FrameButton.setPosition(sf::Vector2f(10.f, 210.f));
		menu.draw(FrameButton);
		FrameButton.setPosition(sf::Vector2f(310.f, 210.f));
		menu.draw(FrameButton);
		Button.setPosition(sf::Vector2f(50.f, 210.f));
		menu.draw(Button);
		
		menu.draw(TTT);
		menu.draw(start);
		menu.draw(exit);


		menu.display();
	}


	return 0;
}

