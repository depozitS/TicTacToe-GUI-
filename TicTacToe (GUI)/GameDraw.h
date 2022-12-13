/*
тот кто будет пытаться разобраться в моём коде будет страдать, ибо я положил болт на нормальную структуризацию кода, а тем более наадекватное называние переменных, такая вот у меня больная бошка)
автор:Depozit
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
P.s. моя боль от 12.12.2022; 0:38 - я в душе не ебу как могу создавать каждый раз новые объекты от нажатия клавишы, вроде статьи на эту тему есть, но разобраться в них пока возможности нет
сделаем проще, создадим максимальное кол-во фигур и под каждую сделаем if, да, через жопу, ну а с другой стороны, я даже не джун, а кусок говна))
обещаю себе в морском бою такой хуйнёй не заниматься, а разбираться нормально в теме, если забью - дайте мне кто нить по башке
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include <string>
#include "logic.h"
#include <string>

//void final(int Status[9],int winner);

int GameStatus[9] = { 10,10,10,10,10,10,10,10,10 };// це хуета, которая запоминает прогресс игры // не забыть перед каждой игрой обновлять на это значение // 10 ничего нет, 0 - крестик, 1 - нолик

//цвета которые я сука хочу сделать меняемыми 
//цвет фона
int rgb[3] = { 229, 210, 180 };

//цвет фигуры
int rgb1[3] = { 237, 106, 64 };

//цвет линий
int rgb2[3] = { 82, 38, 65 };

//цвет фигур
int rgb3[3] = { 0,0,0 };

//цвет выйгранной комбинации
int rgb4[3] = { 250,223,173 };

//цвет текста
int rgb5[3] = { 82, 38, 65 };

//при смене след переменных, сетка пойдёт по пизде, я предупредил
float help = 80.f;//диаметр вспомогательных фигур
float line_w = 10; // ширина разметки
float line_l = 480.f; // длина разметки 

//циферки для отрисовки крестика
float coordinate_set = 10; //шаг сдвига
int helpWTFx[12] = { 0,3,0,1,4,7,8,5,8,7,4,1 }; // множитель для сдвига по Х
int helpWTFy[12] = { 1,4,7,8,5,8,7,4,1,0,3,0 }; // множитель для сдвига по Y

//циферки для отрисовки нолика
float diamO = 37;
float outlineO = 14;

// позиции для нолика
//88 255 412    - X
//138 303 465   - Y

//позиции для крестика
//100 265 420   - X
//150 315 475   - Y


int main();

void Play(int GameStatus[9],int Step) {
    int winner = 10;
    int play = 2;
   
    float Pos[9][2] = {
        {100,150},
        {265,150},
        {420,150},
        {100,315},
        {265,315},
        {420,315},
        {100,475},
        {265,475},
        {420,475}
    };

    
        

    //настройка детализации
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    //рендер окна
    sf::RenderWindow game(sf::VideoMode(600, 800), "Tic Tac Toe", sf::Style::Default, settings);

    //игровое поле    
    sf::RectangleShape rect(sf::Vector2f(500.f, 500.f));
    rect.setPosition(50.f, 100.f);
    rect.setFillColor(sf::Color(rgb1[0], rgb1[1], rgb1[2]));

    //квардраты
    sf::RectangleShape hr1(sf::Vector2f(help, help));
    sf::RectangleShape hr2(sf::Vector2f(help, help));
    sf::RectangleShape hr3(sf::Vector2f(help, help));
    sf::RectangleShape hr4(sf::Vector2f(help, help));

    hr1.setFillColor(sf::Color(rgb[0], rgb[1], rgb[2]));
    hr2.setFillColor(sf::Color(rgb[0], rgb[1], rgb[2]));
    hr3.setFillColor(sf::Color(rgb[0], rgb[1], rgb[2]));
    hr4.setFillColor(sf::Color(rgb[0], rgb[1], rgb[2]));

    hr1.setPosition(50.f, 100.f);
    hr2.setPosition(470.f, 100.f);
    hr3.setPosition(50.f, 520.f);
    hr4.setPosition(470.f, 520.f);

    //круги
    sf::CircleShape hc1(help);
    sf::CircleShape hc2(help);
    sf::CircleShape hc3(help);
    sf::CircleShape hc4(help);

    hc1.setFillColor(sf::Color(rgb1[0], rgb1[1], rgb1[2]));
    hc2.setFillColor(sf::Color(rgb1[0], rgb1[1], rgb1[2]));
    hc3.setFillColor(sf::Color(rgb1[0], rgb1[1], rgb1[2]));
    hc4.setFillColor(sf::Color(rgb1[0], rgb1[1], rgb1[2]));

    hc1.setPosition(50.f, 100.f);
    hc2.setPosition(390.f, 100.f);
    hc3.setPosition(50.f, 440.f);
    hc4.setPosition(390.f, 440.f);

    //линии разметки
    //горизонтальные
    sf::RectangleShape hl1(sf::Vector2f(line_l, line_w));
    sf::RectangleShape hl2(sf::Vector2f(line_l, line_w));

    hl1.setFillColor(sf::Color(rgb2[0], rgb2[1], rgb2[2]));
    hl2.setFillColor(sf::Color(rgb2[0], rgb2[1], rgb2[2]));

    hl1.setPosition(60.f, 266.f);
    hl2.setPosition(60.f, 432.f);
    //вертикальные
    sf::RectangleShape hl3(sf::Vector2f(line_w, line_l));
    sf::RectangleShape hl4(sf::Vector2f(line_w, line_l));

    hl3.setFillColor(sf::Color(rgb2[0], rgb2[1], rgb2[2]));
    hl4.setFillColor(sf::Color(rgb2[0], rgb2[1], rgb2[2]));

    hl3.setPosition(216.f, 110.f);
    hl4.setPosition(382.f, 110.f);

    //отрисовка крестика и нолик
    //теперь бл рисуем 5 крестиков
    sf::ConvexShape xFig1, xFig2, xFig3, xFig4, xFig5;

    xFig1.setPointCount(12);
    for (int i = 0; i < 12; i++) {
        xFig1.setPoint(i, sf::Vector2f(coordinate_set * helpWTFx[i], coordinate_set * helpWTFy[i]));
    }
    xFig1.setFillColor(sf::Color(rgb3[0], rgb3[1], rgb3[2]));
    xFig1.setPosition(sf::Vector2f(-100.f, -100.f));

    xFig2.setPointCount(12);
    for (int i = 0; i < 12; i++) {
        xFig2.setPoint(i, sf::Vector2f(coordinate_set * helpWTFx[i], coordinate_set * helpWTFy[i]));
    }
    xFig2.setFillColor(sf::Color(rgb3[0], rgb3[1], rgb3[2]));
    xFig2.setPosition(sf::Vector2f(-100.f, -100.f));

    xFig3.setPointCount(12);
    for (int i = 0; i < 12; i++) {
        xFig3.setPoint(i, sf::Vector2f(coordinate_set * helpWTFx[i], coordinate_set * helpWTFy[i]));
    }
    xFig3.setFillColor(sf::Color(rgb3[0], rgb3[1], rgb3[2]));
    xFig3.setPosition(sf::Vector2f(-100.f, -100.f));

    xFig4.setPointCount(12);
    for (int i = 0; i < 12; i++) {
        xFig4.setPoint(i, sf::Vector2f(coordinate_set * helpWTFx[i], coordinate_set * helpWTFy[i]));
    }
    xFig4.setFillColor(sf::Color(rgb3[0], rgb3[1], rgb3[2]));
    xFig4.setPosition(sf::Vector2f(-100.f, -100.f));

    xFig5.setPointCount(12);
    for (int i = 0; i < 12; i++) {
        xFig5.setPoint(i, sf::Vector2f(coordinate_set * helpWTFx[i], coordinate_set * helpWTFy[i]));
    }
    xFig5.setFillColor(sf::Color(rgb3[0], rgb3[1], rgb3[2]));
    xFig5.setPosition(sf::Vector2f(-100.f, -100.f));

    // и 4 нолика...
    sf::CircleShape oFig1(diamO), oFig2(diamO), oFig3(diamO), oFig4(diamO); //назвал diam а на деле радиус

    oFig1.setFillColor(sf::Color(rgb1[0],rgb1[1],rgb1[2]));
    oFig1.setOutlineThickness(outlineO);
    oFig1.setOutlineColor(sf::Color(rgb3[0], rgb3[1], rgb3[2]));
    oFig1.setPosition(sf::Vector2f(-100.f, -100.f));

    oFig2.setFillColor(sf::Color(rgb1[0], rgb1[1], rgb1[2]));
    oFig2.setOutlineThickness(outlineO);
    oFig2.setOutlineColor(sf::Color(rgb3[0], rgb3[1], rgb3[2]));
    oFig2.setPosition(sf::Vector2f(-100.f, -100.f));

    oFig3.setFillColor(sf::Color(rgb1[0], rgb1[1], rgb1[2]));
    oFig3.setOutlineThickness(outlineO);
    oFig3.setOutlineColor(sf::Color(rgb3[0], rgb3[1], rgb3[2]));
    oFig3.setPosition(sf::Vector2f(-100.f, -100.f));

    oFig4.setFillColor(sf::Color(rgb1[0], rgb1[1], rgb1[2]));
    oFig4.setOutlineThickness(outlineO);
    oFig4.setOutlineColor(sf::Color(rgb3[0], rgb3[1], rgb3[2]));
    oFig4.setPosition(sf::Vector2f(-100.f, -100.f));

    sf::RectangleShape returnMenu(sf::Vector2f(300.f, 80.f));
    returnMenu.setFillColor(sf::Color(rgb1[0], rgb1[1], rgb1[2]));
    returnMenu.setPosition(sf::Vector2f(-200.f, -200.f));

    sf::CircleShape ret1(40.f),ret2(40.f);
    ret1.setFillColor(sf::Color(rgb1[0], rgb1[1], rgb1[2]));
    ret1.setPosition(sf::Vector2f(-200.f, -200.f));
    ret2.setFillColor(sf::Color(rgb1[0], rgb1[1], rgb1[2]));
    ret2.setPosition(sf::Vector2f(-200.f, -200.f));
    

    sf::Font font;
    if (!font.loadFromFile("forTTT.ttf")) {
        std::cout << "pizdez" << std::endl;
    }

    sf::Text finale;
    finale.setFont(font);
    finale.setFillColor(sf::Color(rgb5[0], rgb5[1], rgb5[2]));
    finale.setCharacterSize(25);
    finale.setPosition(-200.f, -200.f);

    sf::Text Menu;
    Menu.setFont(font);
    Menu.setFillColor(sf::Color(rgb5[0], rgb5[1], rgb5[2]));
    Menu.setCharacterSize(35);
    Menu.setPosition(-100.f, -100.f);
    Menu.setString(L"Меню");

    int wins = 0;
    while (game.isOpen()) {

        sf::Event event;
        while (game.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                game.close();
            }
            sf::Vector2i localPos = sf::Mouse::getPosition(game);
            if (event.type == sf::Event::MouseButtonPressed) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                   
                    int pos = ChekPos(localPos);

                    if (pos != 10 && Step < 10 && GameStatus[pos]==10) {

                        Step++;
                        
                        int win = logic(&GameStatus[pos], GameStatus, Step);
                        if ((win == 1 || win == 2)) {
                            winner = win;
                        }
                        else {
                            winner = 0;
                        }
                        if (play > 1) {
                            //огромное гавнище выбора позиций для фигур
                            if (Step == 1) {
                                xFig1.setPosition(Pos[pos][0], Pos[pos][1]);
                            }
                            else if (Step == 2) {
                                oFig1.setPosition(Pos[pos][0], Pos[pos][1]);
                            }
                            else if (Step == 3) {
                                xFig2.setPosition(Pos[pos][0], Pos[pos][1]);
                            }
                            else if (Step == 4) {
                                oFig2.setPosition(Pos[pos][0], Pos[pos][1]);
                            }
                            else if (Step == 5) {
                                xFig3.setPosition(Pos[pos][0], Pos[pos][1]);
                            }
                            else if (Step == 6) {
                                oFig3.setPosition(Pos[pos][0], Pos[pos][1]);
                            }
                            else if (Step == 7) {
                                xFig4.setPosition(Pos[pos][0], Pos[pos][1]);
                            }
                            else if (Step == 8) {
                                oFig4.setPosition(Pos[pos][0], Pos[pos][1]);
                            }
                            else if (Step == 9) {
                                xFig5.setPosition(Pos[pos][0], Pos[pos][1]);
                            }

                            if (winner == 1 || winner == 2) {
                                play = 0;
                            }
                        }
                        
                    }
                    
                }
            }
            if (winner == 1 || winner == 2 || (winner == 0 && Step > 8) && event.type == sf::Event::MouseButtonPressed) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (localPos.x > 110 && localPos.x < 490) && (localPos.y > 680 && localPos.y < 760)) {
                    game.close();
                    main();
                    return;
                    
                }
            }
            
        }
        
        if (winner == 1) {
            xFig1.setFillColor(sf::Color(rgb[0], rgb4[1], rgb4[2]));
            xFig2.setFillColor(sf::Color(rgb[0], rgb4[1], rgb4[2]));
            xFig3.setFillColor(sf::Color(rgb[0], rgb4[1], rgb4[2]));
            xFig4.setFillColor(sf::Color(rgb[0], rgb4[1], rgb4[2]));
            xFig5.setFillColor(sf::Color(rgb[0], rgb4[1], rgb4[2]));
            finale.setString(L"Победил Крестик");
            finale.setPosition(160.f, 625.f);
        }
        else if (winner == 2) {
            oFig1.setOutlineColor(sf::Color(rgb[0], rgb4[1], rgb4[2]));
            oFig2.setOutlineColor(sf::Color(rgb[0], rgb4[1], rgb4[2]));
            oFig3.setOutlineColor(sf::Color(rgb[0], rgb4[1], rgb4[2]));
            oFig4.setOutlineColor(sf::Color(rgb[0], rgb4[1], rgb4[2]));
            finale.setString(L"Победил Нолик");
            finale.setPosition(180.f, 625.f);
        }
        else if (winner == 0 &&Step>8) {
            finale.setString(L"ничья");
            finale.setPosition(255.f, 625.f);
        }
        if (winner == 1 || winner == 2 || (winner == 0 && Step>8)) {
            returnMenu.setPosition(sf::Vector2f(150.f, 680.f));
            ret1.setPosition(sf::Vector2f(110.f, 680.f));
            ret2.setPosition(sf::Vector2f(410.f, 680.f));
            Menu.setPosition(245.f, 700.f);
            
        }

        game.clear(sf::Color(rgb[0], rgb[1], rgb[2]));

        game.draw(rect);

        game.draw(hr1);
        game.draw(hr2);
        game.draw(hr3);
        game.draw(hr4);

        game.draw(hc1);
        game.draw(hc2);
        game.draw(hc3);
        game.draw(hc4);

        game.draw(hl1);
        game.draw(hl2);
        game.draw(hl3);
        game.draw(hl4);
        
        game.draw(xFig1);
        game.draw(xFig2);
        game.draw(xFig3);
        game.draw(xFig4);
        game.draw(xFig5);

        game.draw(oFig1);
        game.draw(oFig2);
        game.draw(oFig3);
        game.draw(oFig4);
       
        game.draw(finale);
        game.draw(returnMenu);
        game.draw(ret1);
        game.draw(ret2);
        game.draw(Menu);

        game.display();

        


        Sleep(10);

    }
}