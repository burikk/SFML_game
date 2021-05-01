#pragma once

#include <sstream>
#include "GameOverState.h"
#include "DEFINITIONS.h"
#include "GameState.h"
#include "MainMenuState.h"

#include <iostream>
#include <fstream>

GameOverState::GameOverState(GameDataRef data, int score) : _data(data), _score(score)
{

}

void GameOverState::Init()
{
	std::ifstream readFile;
	readFile.open("fonts/HighScore.txt");

	if (readFile.is_open())
	{
		while (!readFile.eof())
		{
			readFile >> _highScore;
		}
	}
	readFile.close();
	std::ofstream writeFile("fonts/HighScore.txt" );
	if (writeFile.is_open())
	{
		if (_score > _highScore)
		{
			_highScore = _score;
			this->_data->assets.LoadTexture("Coin", COIN_FILEPATH);
			_coin.setTexture(_data->assets.GetTexture("Coin"));
			_coin.setPosition((_data->window.getSize().x / 2)-_coin.getGlobalBounds().width/2, (_data->window.getSize().y / 2)- _coin.getGlobalBounds().height*0.4);
		}
		writeFile << _highScore;
	}
	writeFile.close();


	this->_data->assets.LoadTexture("Game Over Backround", GAME_OVER_BACKGROUND_FILEPATH);
	this->_data->assets.LoadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);
	this->_data->assets.LoadTexture("Game Over Container", GAME_OVER_CONTAINER_FILEPATH);
	this->_data->assets.LoadTexture("Game Over Retry Button", GAME_OVER_RETRY_BUTTON_FILEPATH);
	this->_data->assets.LoadTexture("Game Over Bar", GAME_OVER_BAR_FILEPATH);
	

	_background.setTexture(this->_data->assets.GetTexture("Game Over Backround"));
	_gameOverTitle.setTexture(this->_data->assets.GetTexture("Game Over Title"));
	_gameOverContainer.setTexture(this->_data->assets.GetTexture("Game Over Container"));
	_retryButton.setTexture(this->_data->assets.GetTexture("Game Over Retry Button"));
	_bar.setTexture(this->_data->assets.GetTexture("Game Over Bar"));

	_gameOverContainer.setPosition((_data->window.getSize().x / 2) - (_gameOverContainer.getGlobalBounds().width / 2),
		(_data->window.getSize().y / 2) - (_gameOverContainer.getGlobalBounds().height / 2));

	_gameOverTitle.setPosition((_data->window.getSize().x / 2) - (_gameOverTitle.getGlobalBounds().width / 2),
		(_gameOverContainer.getPosition().y + (_gameOverTitle.getGlobalBounds().height*0.5)));
		
	_bar.setPosition((_data->window.getSize().x / 2) - (_bar.getGlobalBounds().width / 2), (_data->window.getSize().y/2) - (_bar.getGlobalBounds().height*0.4));

	_retryButton.setPosition((_data->window.getSize().x / 2) - (_retryButton.getGlobalBounds().width / 2),
		(_data->window.getSize().y / 2) + (_retryButton.getGlobalBounds().height / 3));

	_scoreText.setFont(_data->assets.GetFont("Score Font"));
	_scoreText.setString("YOUR SCORE IS : " + std::to_string(_score));
	_scoreText.setCharacterSize(72);
	_scoreText.setFillColor(sf::Color::Black);
	_scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);
	_scoreText.setPosition((_data->window.getSize().x / 2) - (_scoreText.getGlobalBounds().width*0.9), (_data->window.getSize().y / 2));

	_highScoreText.setFont(_data->assets.GetFont("Score Font"));
	_highScoreText.setString("THE BEST SCORE IS : " + std::to_string(_highScore));
	_highScoreText.setCharacterSize(72);
	_highScoreText.setFillColor(sf::Color::Black);
	_highScoreText.setOrigin(_highScoreText.getGlobalBounds().width / 2, _highScoreText.getGlobalBounds().height / 2);
	_highScoreText.setPosition((_data->window.getSize().x / 2) - (_scoreText.getGlobalBounds().width) + (_highScoreText.getGlobalBounds().width*1.5), (_data->window.getSize().y / 2));
}

void GameOverState::HandleInput()
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
		if (_data->input.IsSpriteClicked(_retryButton, sf::Mouse::Left, _data->window))
		{
			_data->machine.AddState(StateRef(new GameState(_data)), true);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
	}
}

void GameOverState::Update(float dt)
{

}

void GameOverState::Draw(float dt)
{
	this->_data->window.clear();

	this->_data->window.draw(this->_background);
	_data->window.draw(_gameOverContainer);
	_data->window.draw(_gameOverTitle);
	_data->window.draw(_bar);
	_data->window.draw(_retryButton);
	_data->window.draw(_scoreText);
	_data->window.draw(_highScoreText);
	_data->window.draw(_coin);
	

	this->_data->window.display();
}