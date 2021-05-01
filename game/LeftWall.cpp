#include "LeftWall.h"
#include "DEFINITIONS.h"

LeftWall::LeftWall(GameDataRef data) : _data(data)
{
	_leftWall.setTexture(_data->assets.GetTexture("Left Wall"));
	_leftWall.setPosition(-3, 0);
	
}

void LeftWall::DrawWall()
{
	_data->window.draw(_leftWall);
}

const sf::Sprite &LeftWall::GetSprite() const
{
	return _leftWall;
}