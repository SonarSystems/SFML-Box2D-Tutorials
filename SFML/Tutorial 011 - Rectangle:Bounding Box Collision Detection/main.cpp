#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main( )
{
    sf::RenderWindow window( sf::VideoMode( 1920, 1080 ), "Awesome Game" );
    
    sf::Texture crashTexture;
    crashTexture.loadFromFile( "res/img/CrashBandicoot.png" );
    
    sf::Texture akuTexture;
    akuTexture.loadFromFile( "res/img/AkuAku.png" );
    
    sf::Sprite crashBandicoot;
    crashBandicoot.setTexture( crashTexture );
    
    sf::Sprite akuAku;
    akuAku.setTexture( akuTexture );
    
    akuAku.setPosition( window.getSize( ).x / 2 - akuAku.getLocalBounds( ).width / 2, window.getSize( ).y / 2 - akuAku.getLocalBounds( ).height / 2 );
    
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
                    
                case sf::Event::KeyPressed:
                    
                    
                    break;
            }
        }
        
        // update the game
        
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left ) )
        {
            crashBandicoot.move( -2, 0 );
        }
        else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right ) )
        {
            crashBandicoot.move( 2, 0 );
        }
        
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Up ) )
        {
            crashBandicoot.move( 0, -2 );
        }
        else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Down ) )
        {
            crashBandicoot.move( 0, 2 );
        }
        
        if ( crashBandicoot.getGlobalBounds( ).intersects( akuAku.getGlobalBounds( ) ) )
        {
            std::cout << "Collision" << std::endl;
        }
        else
        {
            std::cout << "No collision" << std::endl;
        }
        
        window.clear( );
        
        window.draw( akuAku );
        window.draw( crashBandicoot );
        
        window.display( );
    }
    
    return EXIT_SUCCESS;
}










