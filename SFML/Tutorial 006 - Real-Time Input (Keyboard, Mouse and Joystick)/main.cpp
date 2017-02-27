#include <iostream>

#include <SFML/Graphics.hpp>

int main( )
{
    sf::RenderWindow window( sf::VideoMode( 640, 480 ), "Awesome Game" );
    
    while ( window.isOpen( ) )
    {
        sf::Event event;
        
        while ( window.pollEvent( event ) )
        {
            
            if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left ) )
            {
                std::cout << "Live Keyboard Input: Left Key" << std::endl;
                
                //sf::Mouse::setPosition( sf::Vector2i( 100, 75 ) );
                
                //sf::Mouse::setPosition( sf::Vector2i( 100, 75 ), window );
            }
            
            if ( sf::Mouse::isButtonPressed( sf::Mouse::Button::Left ) )
            {
                std::cout << "Live Mouse Input: Left Button" << std::endl;
            }
            
            sf::Vector2i globalPosition = sf::Mouse::getPosition( );
            
            //std::cout << globalPosition.x << " : " << globalPosition.y << std::endl;
            
            sf::Vector2i localPosition = sf::Mouse::getPosition( window );
            
            //std::cout << localPosition.x << " : " << localPosition.y << std::endl;
            
            if ( sf::Joystick::isConnected( 0 ) )
            {
                //std::cout << "Joystick 0 Connected" << std::endl;
                
                unsigned int buttonCount = sf::Joystick::getButtonCount( 0 );
                
                //std::cout << "Joystick 0 has " << buttonCount << " buttons" << std::endl;
                
                bool hasZ = sf::Joystick::hasAxis( 0, sf::Joystick::Axis::Z );
                
                //std::cout << hasZ << std::endl;
                
                if ( sf::Joystick::isButtonPressed( 0, 1 ) )
                {
                    std::cout << "Button has been pressed" << std::endl;
                }
                
                float xPos = sf::Joystick::getAxisPosition( 0, sf::Joystick::Axis::X );
                
                std::cout << xPos << std::endl;
            }
            else
            {
                std::cout << "Joystick 0 Disconnected" << std::endl;
            }
        }
        
        // update the game
        
        window.clear( );
        
        window.display( );
    }
    
    return EXIT_SUCCESS;
}





