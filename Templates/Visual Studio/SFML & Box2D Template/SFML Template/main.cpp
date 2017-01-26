#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Starter Template");

	while (window.isOpen())
	{
		// handle events

		// update

		window.clear();

		// draw SFML content

		window.display();
	}

	return EXIT_SUCCESS;
}