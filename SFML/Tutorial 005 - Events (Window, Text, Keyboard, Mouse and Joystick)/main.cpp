#include <iostream>

#include <SFML/Graphics.hpp>

int main( )
{
    sf::RenderWindow window( sf::VideoMode( 640, 480 ), "Awesome Game" );

    //window.setKeyRepeatEnabled(false);
    
    while ( window.isOpen( ) )
    {
        sf::Event event;
        
        bool isKeyPressed = false;
        bool isMouseMoving = false;
        
        // handle all events
        while ( window.pollEvent( event ) )
        {
            switch ( event.type )
            {
                case sf::Event::Closed:
                    window.close( );
                    
                    break;
                    
                case sf::Event::EventType::Resized:
                    std::cout << event.size.width << " : " << event.size.height << std::endl;
                    
                    break;
                    
                case sf::Event::EventType::LostFocus:
                    std::cout << "Lost focus" << std::endl;
                    
                    break;
                    
                case sf::Event::EventType::GainedFocus:
                    std::cout << "Gained focus" << std::endl;
                    
                    break;
                    
                case sf::Event::EventType::TextEntered:
                    if ( event.text.unicode < 128 )
                    {
                        //std::cout << static_cast<char>(event.text.unicode) << std::endl;
                    }
                    
                    break;
                    
                case sf::Event::EventType::KeyPressed:
                    std::cout << "Key has been pressed" << std::endl;
                    
                    if (sf::Keyboard::Left == event.key.code)
                    {
                        std::cout << "Left key has been pressed" << std::endl;
                    }
                    
                    std::cout << "Control: " << event.key.control << std::endl;
                    std::cout << "Alt: " << event.key.alt << std::endl;
                    std::cout << "Shift: " << event.key.shift << std::endl;
                    std::cout << "System: " << event.key.system << std::endl;
                    
                    isKeyPressed = true;
                    
                    break;
                    
                case sf::Event::EventType::KeyReleased:
                    std::cout << "Key has been released" << std::endl;

                    if (sf::Keyboard::Left == event.key.code)
                    {
                        std::cout << "Left key has been released" << std::endl;
                    }
                    
                    isKeyPressed = false;
                    
                    break;
                    
                case sf::Event::EventType::MouseButtonPressed:
                    std::cout << "Mouse button pressed" << std::endl;
                    
                    if (sf::Mouse::Button::Left == event.mouseButton.button)
                    {
                        std::cout << "Left Mouse Button Pressed" << std::endl;
                    }
                    
                    break;
                    
                case sf::Event::EventType::MouseButtonReleased:
                    std::cout << "Mouse button released" << std::endl;
                    
                    if (sf::Mouse::Button::Left == event.mouseButton.button)
                    {
                        std::cout << "Left Mouse Button Released" << std::endl;
                    }
                    
                    break;
                    
                case sf::Event::EventType::MouseWheelScrolled:
                    std::cout << "Mouse Wheel Is Being Scrolled" << std::endl;
                    
                    std::cout << event.mouseWheelScroll.delta << std::endl;
                    
                    break;
                    
                case sf::Event::EventType::MouseMoved:
                    //std::cout << event.mouseMove.x << " : " << event.mouseMove.y << std::endl;
                    
                    isMouseMoving = true;
                    
                    break;
                    
                case sf::Event::EventType::MouseLeft:
                    std::cout << "Mouse has left the window" << std::endl;
                    
                    break;
                    
                case sf::Event::EventType::MouseEntered:
                    std::cout << "Mouse has entered the window" << std::endl;
                    
                    break;
                    
                case sf::Event::EventType::JoystickButtonPressed:
                    std::cout << "Joystick button pressed" << std::endl;
                    
                    break;
                    
                case sf::Event::EventType::JoystickButtonReleased:
                    std::cout << "Joystick button released" << std::endl;
                    
                    std::cout << "Joystick ID : " << event.joystickButton.joystickId << std::endl;
                    
                    std::cout << "Joystick Button : " << event.joystickButton.button << std::endl;
                    
                    break;
                    
                case sf::Event::EventType::JoystickMoved:
                    //std::cout << "Joystick has been moved" << std::endl;
                    
                    if (sf::Joystick::Axis::X == event.joystickMove.axis)
                    {
                        std::cout << event.joystickMove.position << std::endl;
                    }
                    
                    break;
                    
                case sf::Event::EventType::JoystickConnected:
                    std::cout << "Joystick connected" << std::endl;
                    
                    break;
                    
                case sf::Event::EventType::JoystickDisconnected:
                    std::cout << "Joystick disconnected" << std::endl;
                    
                    break;
                    
            }
            
            if (sf::Event::EventType::JoystickDisconnected == event.type)
            {
                // do something the same way
            }
            
            if (isKeyPressed && isMouseMoving)
            {
                std::cout << "Multiple Events" << std::endl;
            }
        }
        
        // update the game
        
        window.clear( );
        
        window.display( );
    }
    
    return EXIT_SUCCESS;
}





