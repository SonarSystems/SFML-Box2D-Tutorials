#include <iostream>

#include <SFML/Graphics.hpp>

int main( )
{
    sf::RenderWindow window( sf::VideoMode( 640, 480 ), "Awesome Game" );

    sf::Texture texture;
    
    //texture.setRepeated(true);
    
    if (!texture.loadFromFile("res/img/Brick.jpg"))
    {
        std::cout << "Load failed" << std::endl;
        
        system("pause");
    }
    
    sf::Sprite sprite;
    sprite.setTexture(texture);
    
    sprite.setTextureRect(sf::IntRect(0, 0, 600, 600));
    
    //sprite.setColor(sf::Color(255, 255, 255, 64));
    
    while ( window.isOpen( ) )
    {
        sf::Event event;
        
        // handle all events
        while ( window.pollEvent( event ) )
        {
            switch ( event.type )
            {
                case sf::Event::Closed:
                    window.close( );
                    
                    break;
            }
        }
        
        // update the game
        
        window.clear( );
        
        window.draw(sprite);
        
        window.display( );
    }
    
    return EXIT_SUCCESS;
}






