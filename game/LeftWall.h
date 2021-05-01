#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>
#include "DEFINITIONS.h"

class LeftWall
{
public:
	LeftWall(GameDataRef data);
	sf::Sprite _leftWall;

	const sf::Sprite &GetSprite() const;
	void DrawWall();
private:
	GameDataRef _data;
	//sf::Sprite _leftWall;
};

