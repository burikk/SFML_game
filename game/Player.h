//#pragma once
//#include <SFML/Graphics.hpp>
//#include <iostream>
//using namespace sf;
//
//class Player
//{
//private:
//	float x, y, w, h, dx, dy, speed, CurrentFrame; //���������� ������ � � �, ������ ������, ��������� (�� � � �� �), ���� ��������
//	int dir, playerScore, health;
//	bool life;//����������� (direction) �������� ������
//	Image image;//���� �����������
//	Texture texture;//���� ��������
//	Sprite sprite;//���� ������
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
