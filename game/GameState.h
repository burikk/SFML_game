#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.h"
#include "Game.h"
#include "Enemy.h"
#include "Player.h"
#include "Collisions.h"
#include "LeftWall.h"
#include "Flash.h"
#include "HUD.h"


class GameState : public State
{
public:
	GameState(GameDataRef data);

	void Init();

	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataRef _data;

	sf::Sprite _background;

	Enemy *enemy;
	LeftWall *wall;
	Player *player;
	Collisions collision;
	Flash *flash;
	HUD *hud;

	sf::Clock clock;

	int _gameState;
	
	int _score;
	
	sf::SoundBuffer _hitSoundBuffer;
	//sf::SoundBuffer _playerSoundBuffer;
	sf::Music _player;
	sf::Sound _hit;
	//sf::Sound _player;
};


