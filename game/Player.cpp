//#include "Player.h"
//
//
//Player::Player()
//{
//	texture.loadFromFile("images/hero.png");
//	sprite.setTexture(texture);
//	x = 250.0;
//	y = 250.0;
//	w = 270.0;
//	h = 184.0;
//	sprite.setTextureRect(IntRect(0, 0, w, h));
//	float CurrentFrame = 0.0;
//	float time = clock.getElapsedTime().asMicroseconds();
//	health = 12;
//	life = true;
//}
//
//void Player::Update(float time)
//{
//	/*Vector2f res;
//	res.x = 1600.0;
//	res.y = 900.0;*/
//	switch (dir)//��������� ��������� � ����������� �� �����������. (������ ����� ������������� �����������)
//	{
//	case 0: dx = speed; dy = 0;   break;//�� ���� ������ ������������� ��������, �� ������ ��������. ��������, ��� �������� ���� ������ ������
//	case 1: dx = -speed; dy = 0;   break;//�� ���� ������ ������������� ��������, �� ������ ��������. ����������, ��� �������� ���� ������ �����
//	case 2: dx = 0; dy = speed;   break;//�� ���� ������ ������� ��������, �� ������ �������������. ����������, ��� �������� ���� ������ ����
//	case 3: dx = 0; dy = -speed;   break;//�� ���� ������ ������� ��������, �� ������ �������������. ����������, ��� �������� ���� ������ �����
//	}
//
//	x += dx * time;//���� ��������� �� ����� �������� �������� ��������� � ��� ��������� ��������
//	y += dy * time;//���������� �� ������
//	if (x <= 0)x = 1;
//	if (y <= 0)y = 1;
//	/*if (x >= res.x)x = -x;
//	if (y >= res.y)y = -y;*/
//	speed = 0.0;//�������� ��������, ����� �������� �����������.
//	sprite.setPosition(x, y); //������� ������ � ������� x y , ����������. ���������� ������� � ���� �������, ����� �� ��� ������ ����� �� �����.
//}
//
//void Player::Movement(float time)
//{
//
//	if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
//		dir = 1; speed = 0.1;//dir =1 - ����������� �����, speed =0.1 - �������� ��������. �������� - ����� �� ��� ����� �� �� ��� �� �������� � ����� �� ���������� ������ ���
//		CurrentFrame += 0.005*time;
//		if (CurrentFrame > 2) CurrentFrame -= 2;
//		sprite.setTextureRect(IntRect(0, 184 * int(CurrentFrame), 270, 184)); //����� ������ p ������ player ������ ������, ����� �������� (��������� �������� �����)
//	}
//
//	if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
//		dir = 0; speed = 0.1;//����������� ������, �� ����
//		CurrentFrame += 0.005*time;
//		if (CurrentFrame > 2) CurrentFrame -= 2;
//		sprite.setTextureRect(IntRect(0, 184 * int(CurrentFrame), 270, 184));  //����� ������ p ������ player ������ ������, ����� �������� (��������� �������� �����)
//	}
//
//	if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
//		dir = 3; speed = 0.1;//����������� ����, �� ����
//		CurrentFrame += 0.005*time;
//		if (CurrentFrame > 2) CurrentFrame -= 2;
//		sprite.setTextureRect(IntRect(0, 184 * int(CurrentFrame), 270, 184));  //����� ������ p ������ player ������ ������, ����� �������� (��������� �������� �����)
//
//	}
//
//	if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) { //���� ������ ������� ������� ����� ��� ���� ����� �
//		dir = 2; speed = 0.1;//����������� �����, �� ����
//		CurrentFrame += 0.005*time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
//		if (CurrentFrame > 2) CurrentFrame -= 2; //���������� �� ������ � ������� �� ������ ������������. ���� ������ � �������� ����� - ������������ �����.
//		sprite.setTextureRect(IntRect(0, 184 * int(CurrentFrame), 270, 184));
//
//	}
//}
//
//Sprite Player::getSprite()
//{
//	return sprite;
//}

#include "Player.h"

Player::Player(GameDataRef data) : _data(data)
{
	_animationIterator = 0;
	_animationFrames.push_back(_data->assets.GetTexture("Hero Frame 1"));
	_animationFrames.push_back(_data->assets.GetTexture("Hero Frame 2"));
	_heroSprite.setTexture(_animationFrames.at(_animationIterator));

	_heroSprite.setPosition((_data->window.getSize().x / 4) - (_heroSprite.getGlobalBounds().width / 2),
		(_data->window.getSize().y / 2) - (_heroSprite.getGlobalBounds().height / 2));
	PosX = _heroSprite.getPosition().x;
	PosY = _heroSprite.getPosition().y;

	_herostate = PLAYER_STATE_FLYING;
	

}

void Player::Draw()
{
	_data->window.draw(_heroSprite);
}

void Player::Animate(float dt)
{
	if (_clock.getElapsedTime().asSeconds() > PLAYER_ANIMATION_DURATION / _animationFrames.size())
	{
		if (_animationIterator < _animationFrames.size() - 1)
		{
			_animationIterator++;
		}
		else
		{
			_animationIterator = 0;
		}
		_heroSprite.setTexture(_animationFrames.at(_animationIterator));

		_clock.restart();
	}
}

void Player::Update(float dt)
{
	switch (press)//��������� ��������� � ����������� �� �����������. (������ ����� ������������� �����������)
	{
	case 0: dx = -speed; dy = 0;    break;//�� ���� ������ ������������� ��������, �� ������ ��������. ��������, ��� �������� ���� ������ ������
	case 1: dx = speed; dy = 0;   break;//�� ���� ������ ������������� ��������, �� ������ ��������. ����������, ��� �������� ���� ������ �����
	case 2: dx = 0; dy = -speed;   break;//�� ���� ������ ������� ��������, �� ������ �������������. ����������, ��� �������� ���� ������ ����
	case 3: dx = 0; dy = speed;   break;
	}
	PosX += dx * dt;//���� ��������� �� ����� �������� �������� ��������� � ��� ��������� ��������
	PosY += dy * dt;
	if (PosX <= 0)PosX = 1;
	if (PosY <= 0)PosY = 1;
	if (PosX >= _data->window.getSize().x-_heroSprite.getGlobalBounds().width)PosX = _data->window.getSize().x - _heroSprite.getGlobalBounds().width;
	if (PosY >= _data->window.getSize().y - _heroSprite.getGlobalBounds().height)PosY = _data->window.getSize().y - _heroSprite.getGlobalBounds().height;
	speed = 0.0;
	_heroSprite.setPosition(PosX, PosY);
}

void Player::Input(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		press = 0; speed = 350.0;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		press = 1; speed = 350.0;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		press = 2; speed = 350.0;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		press = 3; speed = 350.0;
	}
	
}

sf::Sprite &Player::GetSprite()
{
	return _heroSprite;
}



