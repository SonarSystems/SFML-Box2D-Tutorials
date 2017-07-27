#include "SFML/Graphics.hpp"
#include <iostream>
#include <cmath>

#define SPEED 1.5f

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML WORK!");

	sf::Texture redTexture;
	redTexture.loadFromFile("res/img/Red.png");

	sf::Texture yellowTexture;
	yellowTexture.loadFromFile("res/img/Yellow.png");


	sf::Sprite redSprite;
	redSprite.setTexture(redTexture);
	redSprite.setPosition(redSprite.getPosition().x + 300, redSprite.getPosition().y + 300);


	sf::Sprite yellowSprite;
	yellowSprite.setTexture(yellowTexture);


	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();

				break;

			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			yellowSprite.move( -SPEED, 0.0f );
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			yellowSprite.move(SPEED, 0.0f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			yellowSprite.move(0.0f, -SPEED);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			yellowSprite.move(0.0f, SPEED);
		}

		sf::FloatRect shape1 = redSprite.getGlobalBounds();
		sf::FloatRect shape2 = yellowSprite.getGlobalBounds();

		float dx = (redSprite.getPosition().x + (shape1.width / 2)) - (yellowSprite.getPosition().x + (shape2.width / 2));
		float dy = (redSprite.getPosition().y + (shape1.height / 2)) - (yellowSprite.getPosition().y + (shape2.height / 2));
		float distance = std::sqrt((dx * dx) + (dy * dy));

		if (distance <= (shape1.width / 2) + (shape2.width / 2))
		{
			std::cout << "Collision Detected" << std::endl;
		}
		else
		{
			std::cout << "No Collision Detected" << std::endl;
		}

		window.clear();

		window.draw(redSprite);
		window.draw(yellowSprite);

		window.display();
	}

	return EXIT_SUCCESS;
}
