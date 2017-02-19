#include <iostream>

#include <SFML/Graphics.hpp>

int main( )
{
    sf::RenderWindow window( sf::VideoMode( 640, 480 ), "Awesome Game" );
    
    sf::Texture texture;

    if ( !texture.loadFromFile( "res/img/Brick.jpg" ) )
    {
        std::cout << "Load failed" << std::endl;
        
        system( "pause" );
    }
    
    sf::Sprite sprite;
    sprite.setTexture( texture );
    
    /*
     POSITION CODE
     */
    //sprite.setPosition( sf::Vector2f( 320, 240 ) );
    
    //sprite.move( sf::Vector2f( 50, 0 ) );
    
    sf::Vector2f position = sprite.getPosition( );
    //position.x;
    //position.y;
    
    
    /*
     ROTATION CODE
     */
    //sprite.setRotation( 45 );
    
    //sprite.rotate( 10 );
    
    float rotation = sprite.getRotation( );
    
    
    /*
     SCALING CODE
     */
    //sprite.setScale( sf::Vector2f( 1.0f, 2.0f ) );
    
    //sprite.scale( sf::Vector2f( 0.5f, 0.5f ) );
    
    sf::Vector2f scale = sprite.getScale( );
    //scale.x;
    //scale.y;
    
    
    /*
     ORIGIN CODE
     */
    sf::Rect<float> size = sprite.getGlobalBounds( );
    
    //sprite.setOrigin( sf::Vector2f( size.width / 2, size.height / 2  ) );
    
    //sprite.setRotation( 45 );
    
    //sprite.setScale( 2.0f, 1.25f );
    
    
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
        
        window.draw( sprite );
        
        window.display( );
    }
    
    return EXIT_SUCCESS;
}





