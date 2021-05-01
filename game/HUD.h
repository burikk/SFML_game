#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "Game.h"
#include <sstream>

class HUD
{
private:
	GameDataRef _data;
	sf::Text _scoreText;
	sf::Text _scoreText2;

public:
	HUD(GameDataRef data);
	
	void Draw();
	void UpdateScore(int score);
};

