#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main( )
{
    sf::RenderWindow window( sf::VideoMode( 640, 480 ), "Awesome Game" );
    
    sf::Texture texture;
    
    if ( !texture.loadFromFile( "res/img/Background.png" ) )
    {
        std::cout << "Error Loading Texture" << std::endl;
    }
    
    sf::Sprite sprite( texture );
    
    sf::View view1( sf::FloatRect( 200, 200, 300, 200 ) );
    
    // create a view with its center and size
    //sf::View view2( sf::Vector2f( 350, 300 ), sf::Vector2f( 300, 200 ) );
    
    //view1.reset( sf::FloatRect( 200, 200, 400, 600 ) );
    //view1.setCenter( sf::Vector2f( 350, 350 ) );
    //view1.setSize( sf::Vector2f( 150, 30 ) );
    
    window.setView( view1 );
    
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
                    if ( sf::Keyboard::Key::Space == event.key.code )
                    {
                        view1.setCenter( sf::Vector2f( 0, 0 ) );
                    }
                    else if ( sf::Keyboard::Key::Up == event.key.code )
                    {
                        view1.move( sf::Vector2f( 0, -1 ) );
                    }
                    else if ( sf::Keyboard::Key::Down == event.key.code )
                    {
                        view1.move( sf::Vector2f( 0, 1 ) );
                    }
                    else if ( sf::Keyboard::Key::Left == event.key.code )
                    {
                        view1.move( sf::Vector2f( -1, 0 ) );
                    }
                    else if ( sf::Keyboard::Key::Right == event.key.code )
                    {
                        view1.move( sf::Vector2f( 1, 0 ) );
                    }
                    else if ( sf::Keyboard::Key::S == event.key.code )
                    {
                        view1.setRotation( 45 );
                    }
                    else if ( sf::Keyboard::Key::A == event.key.code )
                    {
                        view1.rotate( 1 );
                    }
                    else if ( sf::Keyboard::Key::D == event.key.code )
                    {
                        view1.rotate( -1 );
                    }
                    else if ( sf::Keyboard::Key::O == event.key.code )
                    {
                        view1.setSize( 600, 400 );
                    }
                    else if ( sf::Keyboard::Key::I == event.key.code )
                    {
                        view1.zoom( 2.0f );
                    }
                    else if ( sf::Keyboard::Key::P == event.key.code )
                    {
                        view1.zoom( 0.5f );
                    }


                    break;
            }
        }
        
        window.setView( view1 );
        
        // update the game
        
        window.clear( );
        
        window.draw( sprite );
        
        window.display( );
    }
    
    return EXIT_SUCCESS;
}





