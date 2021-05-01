//#pragma once
//#include <SFML/Graphics.hpp>
//#include <iostream>
//using namespace sf;
//
//class Enemy
//{
//private:
//	float x, y, w, h, dx=0.1, dy, speed, CurrentFrame; //координаты игрока х и у, высота ширина, ускорение (по х и по у), сама скорость
//	int dir, health;
//	bool life;//направление (direction) движения игрока
//	Image image;//сфмл изображение
//	Texture texture;//сфмл текстура
//	Sprite sprite;//сфмл спрайт
//	float time;
//	Clock clock;
//public:
//	Enemy();
//	void Update(float time);
//	void Movement(float time);
//	Sprite getSprite();
//};


#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include <vector>
#include "DEFINITIONS.h"


class Enemy
{
public:
	Enemy(GameDataRef data);

	void SpawnEnemy();
	void SpawnInvisbleEnemy();
	void MoveEnemy(float dt);
	void DrawEnemy();
	void RandomiseEnemyOffset();

	void EraseEnemySprite(int i) { Enemysprites.erase(Enemysprites.begin() + i); }
	sf::Sprite getEnemySprite(int i) { return Enemysprites.at(i); }
	int GetSizeEnemySprite() { return Enemysprites.size(); }
private:
	GameDataRef _data;
	std::vector<sf::Sprite> Enemysprites;
	sf::Sprite sprite;

	int _landHeight;
	int _enemySpawnYOffset;
};
