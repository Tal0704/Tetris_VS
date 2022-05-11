#include <SFML/Graphics.hpp>
#include <memory>
#include <Block.h>

#if defined(_DEBUG)
#include <iostream>
#endif

int main()
{
	sf::RenderWindow gameWindow(sf::VideoMode(300, 510), "Taltris");
	sf::Event event;
	 
	sf::Texture texture;
	if (!texture.loadFromFile("media/tetros/blue.png"))
		return -1;

	Block block(texture, sf::Vector2f(30, 30));

	block.move(sf::Vector2f(50.0f, 50.0f));

	while (gameWindow.isOpen())
	{
		while (gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				gameWindow.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
				gameWindow.close();
		}

		
		gameWindow.clear();
		gameWindow.draw(block);
		gameWindow.display();
	}

	return 0;
}
