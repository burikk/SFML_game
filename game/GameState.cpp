#pragma once

#include <sstream>
#include <SFML/Audio.hpp>
#include "GameState.h"
#include "DEFINITIONS.h"
#include "GameOverState.h"
#include <iostream>
#include "MainMenuState.h"


GameState::GameState(GameDataRef data) : _data(data)
{

}

void GameState::Init()
{
	/*if (!_playerSoundBuffer.loadFromFile(PLAYER_SOUND_FILEPATH))
	{
		std::cout << "Error loading Player Sound Effect" << std::endl;
	}*/
	if (!_player.openFromFile("audio/airplain.ogg"))
	{
		std::cout << "ERROR" << std::endl;
	}
	_player.setLoop(true);
	_player.play();
	if (!_hitSoundBuffer.loadFromFile(HIT_SOUND_FILEPATH))
	{
		std::cout << "Error loading Hit Sound Effect" << std::endl;
	}

	_hit.setBuffer(_hitSoundBuffer);
	//_player.setBuffer(_playerSoundBuffer);


	this->_data->assets.LoadTexture("Game Backround", GAME_BACKGROUND_FILEPATH);
	this->_data->assets.LoadTexture("Enemy", ENEMY_FILEPATH);
	this->_data->assets.LoadTexture("Hero Frame 1", PLAYER_FRAME_1_FILEPATH);
	this->_data->assets.LoadTexture("Hero Frame 2", PLAYER_FRAME_2_FILEPATH);
	this->_data->assets.LoadTexture("Left Wall", LEFT_WALL_FILEPATH);
	this->_data->assets.LoadFont("Score Font", PLAYER_SCORE_FONT_FILEPATH);
	enemy = new Enemy(_data);
	wall = new LeftWall(_data);
	player = new Player(_data);
	flash = new Flash(_data);
	hud = new HUD(_data);
	_background.setTexture(this->_data->assets.GetTexture("Game Backround"));
	_score = 0;
	hud->UpdateScore(_score);
	_gameState = GameStates::eReady;
}

void GameState::HandleInput()
{
	sf::Event event;

	while (this->_data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->_data->window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			this->_data->window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete))
		{
			_player.stop();
			this->_data->machine.AddState(StateRef(new GameOverState(_data, _score)), true);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			_player.stop();
			this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
	}
}

void GameState::Update(float dt)
{

	if (GameStates::eGameOver != _gameState)
	{
		_gameState = GameStates::ePlaying;

		player->Input(dt);
		player->Animate(dt);

		

	}
	
	if (GameStates::ePlaying == _gameState)
	{
		enemy->MoveEnemy(dt);
		if (clock.getElapsedTime().asSeconds() > ENEMY_SPAWN_FREQUENCY)
		{
			enemy->RandomiseEnemyOffset();

			enemy->SpawnEnemy();

			clock.restart();

		}

		for (int i = 0; i < enemy->GetSizeEnemySprite(); i++)
		{
			
			if (collision.CheckSpriteCollision(player->GetSprite(), enemy->getEnemySprite(i)))
			{
				_hit.play();
				enemy->EraseEnemySprite(i);
				_score++;
				//std::cout << "Score " << _score << std::endl;
				hud->UpdateScore(_score);
			}
			else if (collision.CheckSpriteCollision(wall->GetSprite(), enemy->getEnemySprite(i)))
			{
				_gameState = GameStates::eGameOver;
				clock.restart();
			}
			
		}
		player->Update(dt);

	}
	if (GameStates::eGameOver == _gameState)
	{
		_player.stop();
		flash->Show(dt);
		if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS)
		{
			_data->machine.AddState(StateRef(new GameOverState(_data, _score)), true);
		}
	}
}

void GameState::Draw(float dt)
{
	this->_data->window.clear();

	this->_data->window.draw(this->_background);
	wall->DrawWall();
	enemy->DrawEnemy();
	player->Draw();
	flash->Draw();
	hud->Draw();

	this->_data->window.display();
}
