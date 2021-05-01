//#include "Engine.h"
//using namespace sf;
//
//
//Engine::Engine()
//{
//	Vector2f resolution;
//	resolution.x = 1920.0;
//	resolution.y = 1080.0;
//	window.create(VideoMode(resolution.x, resolution.y),
//	"MY GAME", Style::Fullscreen);
//}
//
//void Engine::update(float time)
//{
//	p.Update(time);
//	enemy1.Update(time);
//}
//
//void Engine::input(float time)
//{
//	if (Keyboard::isKeyPressed(Keyboard::Escape))
//	{
//		window.close();
//	}
//	p.Movement(time);
//}
//
//void Engine::draw()
//{
//	window.clear();
//	window.draw(map.getSprite());
//	window.draw(p.getSprite());
//	window.draw(enemy1.getSprite());
//	window.display();
//}
//
//void Engine::start()
//{
//	Clock clock;
//	while (window.isOpen())
//	{
//		float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
//		float time1 = clock.getElapsedTime().asMicroseconds(); //крутилка самолета
//		clock.restart(); //перезагружает время
//		time = time / 300; //скорость игры
//		time1 = time1 / 100;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//		update(time);
//		input(time1);
//		draw();
//	}
//}
