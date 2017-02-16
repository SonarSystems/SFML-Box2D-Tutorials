#include <iostream>

#include <SFML/Graphics.hpp>

int main( )
{
    sf::RenderWindow window( sf::VideoMode( 640, 480 ), "Awesome Game" );
    
    sf::Font font;
    
    if ( !font.loadFromFile( "res/fonts/FontFile.ttf" ) )
    {
        std::cout << "Error loading file" << std::endl;
        
        system( "pause" );
    }
    
    sf::Text text;

    text.setFont( font );
    
    text.setString( "Hello world!!!" );
    
     // in pixels, not points!
    text.setCharacterSize( 256 );
    
    text.setFillColor( sf::Color::Red );
    
    text.setStyle( sf::Text::Style::Bold | sf::Text::Style::Underlined );
    
    text.setOutlineColor( sf::Color::Yellow );
    text.setOutlineThickness( 10 );
    
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
        
        window.draw( text );
        
        window.display( );
    }
    
    return EXIT_SUCCESS;
}






