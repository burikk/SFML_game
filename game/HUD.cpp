#include "HUD.h"
#include <string>

HUD::HUD(GameDataRef data) : _data(data)
{
	_scoreText.setFont(_data->assets.GetFont("Score Font"));
	_scoreText.setCharacterSize(80);
	_scoreText.setFillColor(sf::Color::Black);
	_scoreText.setOrigin(_scoreText.getGlobalBounds().width, _scoreText.getGlobalBounds().height);
	_scoreText.setPosition(0, 0);
}

void HUD::Draw()
{
	_data->window.draw(_scoreText);
}

void HUD::UpdateScore(int score)
{
	_scoreText.setString("YOUR SCORE IS : " + std::to_string(score));
}
