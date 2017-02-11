#include <iostream>

#include <SFML/Graphics.hpp>

int main( )
{
    sf::RenderWindow window( sf::VideoMode( 640, 480 ), "Awesome Game" );
    
    /*
     CIRCLE SHAPE
     */
    sf::CircleShape circle(65);
    
    // radius and point count can be set after as well
    //shape.setRadius(100);
    //shape.setPointCount(3);
    
    // Red, Green and Blue from 0 to 255
    circle.setFillColor(sf::Color(255, 0, 0));
    
    // Red, Green and Blue from 0 to 255
    circle.setOutlineColor(sf::Color(0, 255, 0));
    circle.setOutlineThickness(15); // use negative to make outline go inside of the circle
    
    sf::Texture texture;
    
    if (!texture.loadFromFile("res/img/Brick.jpg"))
    {
        std::cout << "Load failed" << std::endl;
        
        system("pause");
        
        return EXIT_FAILURE;
    }
    
    circle.setTexture(&texture);
    circle.setTextureRect(sf::IntRect(0, 0, 500, 500));
    
    
    /*
     RECTANGLE SHAPE
     */
    sf::RectangleShape rectangle(sf::Vector2f(100, 60));
    
    // change the size after
    //rectangle.setSize(sf::Vector2f(200, 200));
    
    
    /*
     CONVEX SHAPE
     */
    sf::ConvexShape convex(5);
    
    // set point count count after
    //convex.setPointCount(5);
    
    convex.setPoint(0, sf::Vector2f(0, 0));
    convex.setPoint(1, sf::Vector2f(100, 15));
    convex.setPoint(2, sf::Vector2f(200, 75));
    convex.setPoint(3, sf::Vector2f(45, 120));
    convex.setPoint(4, sf::Vector2f(0, 70));
    
    
    /*
     LINE
     */
    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(45, 100)),
        sf::Vertex(sf::Vector2f(200, 400))
    };
    
    line[0].color = sf::Color::Red;
    line[1].color = sf::Color::Blue;

    // change the position of a vertex after
    line[0].position = sf::Vector2f(400, 400);
    
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
        
        // draw objects here
        
        window.draw(line, 2, sf::Lines);
        
        window.display( );
    }
    
    return EXIT_SUCCESS;
}






