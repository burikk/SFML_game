//#pragma once
//#include <SFML/Graphics.hpp>
//#include <iostream>
//using namespace sf;
//
//class Player
//{
//private:
//	float x, y, w, h, dx, dy, speed, CurrentFrame; //координаты игрока х и у, высота ширина, ускорение (по х и по у), сама скорость
//	int dir, playerScore, health;
//	bool life;//направление (direction) движения игрока
//	Image image;//сфмл изображение
//	Texture texture;//сфмл текстура
//	Sprite sprite;//сфмл спрайт
//	float time;
//	Clock clock;
//public:
//	Player();
//	void Update(float time);
//	void Movement(float time);
//	Sprite getSprite();
//};

#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "Game.h"
#include <vector>

class Player
{
public:
	Player(GameDataRef data);

	void Draw();
	void Animate(float dt);
	void Update(float dt);
	
	void Input(float dt);

	sf::Sprite &GetSprite();
	
private:
	GameDataRef _data;
	sf::Sprite _deadSprite;
	sf::Sprite _heroSprite;
	std::vector<sf::Texture> _animationFrames;

	unsigned int _animationIterator;
	sf::Clock _clock;
	int _herostate = 0;
	float speed;
	float PosX, PosY;
	int dx, dy;
	
	int press;
};
