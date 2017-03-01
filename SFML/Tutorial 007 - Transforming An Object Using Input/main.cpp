#include <iostream>

#include <SFML/Graphics.hpp>

int main( )
{
    sf::RenderWindow window( sf::VideoMode( 640, 480 ), "Awesome Game" );
    
    sf::RectangleShape shape;
    shape.setSize( sf::Vector2f( 200, 100 ) );
    shape.setFillColor( sf::Color::Red );
    shape.setPosition( sf::Vector2f( window.getSize( ).x / 2, window.getSize( ).y / 2 ) );
    shape.setOrigin( sf::Vector2f( shape.getSize( ).x / 2, shape.getSize( ).y / 2 ) );
    
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
                    
                /*case sf::Event::KeyPressed:
                    
                    if ( sf::Keyboard::Key::Left == event.key.code )
                    {
                        shape.move( sf::Vector2f( -5.0f, 0.0f ) );
                    }
                    
                    break;*/
            }
        }
        
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left ) )
        {
            shape.move( sf::Vector2f( -0.5f, 0.0f ) );
        }
        
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right ) )
        {
            shape.move( sf::Vector2f( 0.5f, 0.0f ) );
        }
        
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Up ) )
        {
            shape.move( sf::Vector2f( 0.0f, -0.5f ) );
        }
        
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Down ) )
        {
            shape.move( sf::Vector2f( 0.0f, 0.5f ) );
        }
        
        //shape.rotate( 0.1f );
        
        // update the game
        
        window.clear( );
        
        window.draw( shape );
        
        window.display( );
    }
    
    return EXIT_SUCCESS;
}





