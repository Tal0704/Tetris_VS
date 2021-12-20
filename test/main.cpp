#include <SFML/Graphics.hpp>
#include <iostream>
#include <Tetromino.h>
#include <functions.h>
#include <thread>

#define BACKGROUND_COLOR sf::Color(0xC6, 0xD8, 0xF2)

// TODO:
// Tetromino.cpp rotate check for right bounderies

int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "Tetris");
	Tetromino tetro(Tetromino::Kind::I);

	//fall(tetro, window);
    sf::Clock fallingTimer;
    sf::Time fallSpeed = sf::milliseconds(500);
#if !defined(_DEBUG)
	std::thread fallingThread([&]() {
            while (window.isOpen())
            {
                if (fallingTimer.getElapsedTime() == fallSpeed)
                {
                    tetro.fall();
                    fallingTimer.restart();
                }
            }
		});
#endif

	while (window.isOpen())
	{
        sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
				window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
                tetro.move(Tetromino::Direction::Left);
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
                tetro.move(Tetromino::Direction::Right);
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
				tetro.rotate(Tetromino::Direction::Right);
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Z)
				tetro.rotate(Tetromino::Direction::Left);
#if defined(_DEBUG)
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
				tetro.fall();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::L)
				tetro.log();
#endif // _DEBUG
		}
		
		window.clear(BACKGROUND_COLOR);
		window.draw(tetro);
		window.display();
	}
#if !defined(_DEBUG)	
	fallingThread.join();
#endif // _DEBUG

	return 0;
}
