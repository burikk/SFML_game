#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "DEFINITIONS.h"


class Flash
{
private:
	GameDataRef _data;

	sf::RectangleShape _shape;

	bool _flashOn;
public:
	Flash(GameDataRef data);

	void Show(float dt);
	void Draw();
};

