#include <SFML/Graphics.hpp>
#include <iostream>
#include <Tetromino.h>

int main()
{
	sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(512, 512), "Tetris");
	Tetromino *tetro = new Tetromino(Tetromino::Kind::O);
	sf::Event *event = new sf::Event;

	while (window->isOpen())
	{
		while (window->pollEvent(*event))
		{
			if (event->type == sf::Event::Closed)
				window->close();
			if (event->type == sf::Event::KeyPressed && event->key.code == sf::Keyboard::Enter)
				window->close();
			if (event->type == sf::Event::KeyPressed && event->key.code == sf::Keyboard::Left)
				tetro->transform.move(Transform::Direction::Left);
			if (event->type == sf::Event::KeyPressed && event->key.code == sf::Keyboard::Right)
				tetro->transform.move(Transform::Direction::Right);
		}
		
		tetro->draw(*window);
	}

	delete window;
	delete tetro;
	delete event;
	return 0;
}
