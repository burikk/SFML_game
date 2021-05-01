#pragma once
#include <SFML/Graphics.hpp>

class Collisions
{
public:
	Collisions();

	bool CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2);
};
