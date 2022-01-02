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

	sf::Event movmentEvent;
#if !defined(_DEBUG)
	std::thread fallingThread([&]()
		{
			while (window.isOpen())
			{
				fall(currentGame.currentShape, window);
			}
		});
#endif
	std::thread movmentThread([&]() {
		while (window.isOpen())
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				currentGame.moveShape(Tetromino::Direction::Right);
				delay(50);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				currentGame.moveShape(Tetromino::Direction::Left);
				delay(50);
			}
		}
    });
	std::thread rotationThread([&]() {
            while (window.isOpen())
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    currentGame.currentShape.rotate(Tetromino::Direction::Right);
                    delay(149);
                }
			}
		});
	std::thread fastFallingThread([&]() {
            static sf::Clock fastFallingClock;
            while (window.isOpen())
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    currentGame.currentShape.fall();
                    delay(49);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                    currentGame.instaDrop();
                fastFallingClock.restart();
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
#if !defined(_DEBUG)	
	fallingThread.join();
#endif // _DEBUG
	rotationThread.join();
	fastFallingThread.join();
	movmentThread.join();

	return 0;
}
