#include <functions.h>

void fall(Tetromino& tetro, sf::RenderWindow& window)
{
	std::thread fallingThread([&]() {
		sf::Clock fallingTimer;
		sf::Time fallSpeed = sf::milliseconds(500);
		while (window.isOpen())
		{
			if (fallingTimer.getElapsedTime() >= fallSpeed)
			{
                tetro.fall();
				fallingTimer.restart();
			}
		}
    });
	fallingThread.join();
}

void delay(size_t ms)
{
	sf::Clock delayClock;
	while (delayClock.getElapsedTime() < sf::milliseconds(ms));
}