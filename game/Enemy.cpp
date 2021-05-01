//#include "Enemy.h"
//
//
//
//Enemy::Enemy()
//{
//	texture.loadFromFile("images/matematyka.png");
//	sprite.setTexture(texture);
//	x = 1700.0;
//	y = 500.0;
//	w = 200.0;
//	h = 100.0;
//	sprite.setTextureRect(IntRect(0, 0, w, h));
//	float CurrentFrame = 0.0;
//	float time = clock.getElapsedTime().asMicroseconds();
//}
//
//void Enemy::Update(float time)
//{
//	switch (dir)//реализуем поведение в зависимости от направления. (каждая цифра соответствует направлению)
//	{
//	case 0: dx = speed; dy = 0;   break;//по иксу задаем положительную скорость, по игреку зануляем. получаем, что персонаж идет только вправо
//	case 1: dx = -speed; dy = 0;   break;//по иксу задаем отрицательную скорость, по игреку зануляем. получается, что персонаж идет только влево
//	}
//	x += dx * time;
//	if (x >= 1920) x = -1;
//	if (x <= 0) x = 1;
//	speed = -0.1;
//	sprite.setPosition(x, y);
//}
//
//void Enemy::Movement(float time)
//{
//	
//}
//
//Sprite Enemy::getSprite()
//{
//	return sprite;
//}

#include "Enemy.h"
#include <iostream>

Enemy::Enemy(GameDataRef data) :_data(data)
{
	sf::Sprite sprite(_data->assets.GetTexture("Enemy"));
	_enemySpawnYOffset = 0;
	_landHeight = _data->window.getSize().y-sprite.getGlobalBounds().height;
	
}

void Enemy::SpawnEnemy()
{
	sf::Sprite sprite(_data->assets.GetTexture("Enemy"));
	sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y-sprite.getGlobalBounds().height-_enemySpawnYOffset);
	Enemysprites.push_back(sprite);
}

void Enemy::SpawnInvisbleEnemy()
{

}

void Enemy::MoveEnemy(float dt)
{
		
	for (unsigned short int i = 0; i < Enemysprites.size(); i++)
	{
		if (Enemysprites.at(i).getPosition().x < 0 - Enemysprites.at(i).getGlobalBounds().width)
		{
			Enemysprites.erase(Enemysprites.begin() + i);
			
		}
		else
		{
			float movement = ENEMY_MOVEMENT_SPEED * dt;

			Enemysprites.at(i).move(-movement, 0);
			
		}

	}
}

void Enemy::DrawEnemy()
{
	for (unsigned short int i = 0; i < Enemysprites.size(); i++)
	{
		_data->window.draw(Enemysprites.at(i));
	}
}

void Enemy::RandomiseEnemyOffset()
{
	_enemySpawnYOffset = rand() % (_landHeight);
}




