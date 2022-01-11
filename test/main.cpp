#include <SFML/Graphics.hpp>
#include <iostream>
#include <Tetromino.h>
#include <functions.h>
#include <thread>
#include <string>
#include <Board.h>

#define BACKGROUND_COLOR sf::Color(0xC6, 0xD8, 0xF2)

int main()
{
	sf::RenderWindow window(sf::VideoMode(300, 512), "Tetris");
	Board currentGame(window.getSize());

	sf::Time fallDelay = sf::milliseconds(60);
	sf::Event movmentEvent;
	std::thread fallingThread([&]()
		{
			while (window.isOpen())
			{
				fall(currentGame.currentShape, window);
			}
		});
	std::thread movmentThread([&]() {
		while (window.isOpen())
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				currentGame.moveShape(Tetromino::Direction::Right);
				sf::sleep(sf::milliseconds(100));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				currentGame.moveShape(Tetromino::Direction::Left);
				sf::sleep(sf::milliseconds(100));
			}
		}
    });
	std::thread rotationThread([&]() {
            while (window.isOpen())
            {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					currentGame.currentShape.rotate(Tetromino::Direction::Right);
					sf::sleep(sf::milliseconds(149));
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
				    currentGame.currentShape.fall();
					sf::sleep(fallDelay);
				}
			}
		});

    sf::Clock fallingTimer;
    sf::Time fallSpeed = sf::milliseconds(500);

	while (window.isOpen())
	{
        sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
				window.close();
#if defined(_DEBUG)
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::L)
				currentGame.currentShape.log();
#endif // _DEBUG
		}

		if (currentGame.isDown())
		{
			currentGame.addCurrentShape();
			currentGame.createNewShape();
		}
		
		window.clear(BACKGROUND_COLOR);
		window.draw(currentGame);
		window.display();
	}
	fallingThread.join();
	rotationThread.join();
	movmentThread.join();

	return 0;
}
