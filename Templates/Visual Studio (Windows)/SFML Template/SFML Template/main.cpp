#include <SFML/Graphics.hpp>

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
