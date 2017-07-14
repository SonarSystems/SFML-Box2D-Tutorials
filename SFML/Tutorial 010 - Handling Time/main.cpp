#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main( )
{
    sf::RenderWindow window( sf::VideoMode( 1920, 1080 ), "Awesome Game" );
    
    sf::Time micro = sf::microseconds( 10000 );
    sf::Time milli = sf::milliseconds( 10 );
    sf::Time second = sf::seconds( 0.01f );
    
    std::cout << micro.asSeconds( ) << std::endl;
    std::cout << micro.asMilliseconds( ) << std::endl;
    std::cout << micro.asMicroseconds( ) << std::endl;
    
    std::cout << ( micro + milli ).asSeconds( ) << std::endl;
    
    sf::Clock clock; // starts the clock
    
    while ( window.isOpen( ) )
    {
        sf::Event event;
        
        while ( window.pollEvent( event ) )
        {
            switch ( event.type )
            {
                case sf::Event::Closed:
                    window.close( );
                    
                    break;
                    
                case sf::Event::KeyReleased:
                    clock.restart( );
                    
                    break;
            }
        }
        
        // update the game
        
        sf::Time elapsed = clock.getElapsedTime( );
        std::cout << elapsed.asSeconds( ) << std::endl;
        
        window.clear( );
                
        window.display( );
    }
    
    return EXIT_SUCCESS;
}





