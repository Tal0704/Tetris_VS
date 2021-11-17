#include <SFML/Graphics.hpp>
#include <Tetromino.h>

int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "Tetris");
	Tetromino tetro(Tetromino::Kind::O);

	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
				window.close();
		}
		
		tetro.draw(window);

		// This is a test.
	}

	return 0;
}
