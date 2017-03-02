#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main( )
{
    sf::RenderWindow window( sf::VideoMode( 640, 480 ), "Awesome Game" );

    /*
     Sound Effect
     */
    sf::SoundBuffer buffer;
    
    if (!buffer.loadFromFile( "res/audio/Collide.wav" ) )
    {
        std::cout << "ERROR: Loading Sound Effect" << std::endl;
    }
    
    sf::Sound sound;
    
    sound.setBuffer( buffer );
    
    
    
    /*
     Music File
     */
    sf::Music music;
    
    if ( !music.openFromFile( "res/audio/MainMusic.ogg" ) )
    {
        std::cout << "ERROR: Loading Music File" << std::endl;
    }
    
    
    
    /*
     Audio Recording
     */
    if ( !sf::SoundBufferRecorder::isAvailable( ) )
    {
        std::cout << "ERROR: No Recording Device Found" << std::endl;
    }
    
    sf::SoundBufferRecorder recorder;
    
    recorder.start();

    sf::SoundBuffer recordingBuffer;
    
    
    
    /*
     Choose Recording Device
     */
    std::vector<std::string> availableDevices = sf::SoundRecorder::getAvailableDevices( );
    
    for ( int i = 0; i < availableDevices.size( ); i++ )
    {
        std::cout << availableDevices.at( i ) << std::endl;
    }
    
    // choose a device
    std::string inputDevice = availableDevices[0];
    
    // create the recorder
    sf::SoundBufferRecorder recorder2;
    
    
    
    // set the device
    if ( !recorder2.setDevice( inputDevice ) )
    {
        std::cout << "ERROR: Problem Seting Recording Device" << std::endl;
    }
    
    while ( window.isOpen( ) )
    {
        sf::Event event;
        
        while ( window.pollEvent( event ) )
        {
            switch ( event.type )
            {
                case sf::Event::Closed:
                    recorder.stop( );
                    recordingBuffer = recorder.getBuffer( );
                    
                    recordingBuffer.saveToFile( "Recording.ogg" );
                    
                    window.close( );
                    
                    break;
                    
                case sf::Event::KeyReleased:
                    if ( sf::Keyboard::Key::P == event.key.code )
                    {
                        music.play( );
                    }
                    else if ( sf::Keyboard::Key::S == event.key.code )
                    {
                        music.stop( );
                    }
                    else if ( sf::Keyboard::Key::F == event.key.code )
                    {
                        music.pause( );
                    }
                    
                    //sound.play( );
                    
                    break;
            }
        }
        
        // update the game
        
        window.clear( );
        
        window.display( );
    }
    
    return EXIT_SUCCESS;
}





