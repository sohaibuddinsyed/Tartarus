#include "Game.hpp"
#include <iostream>

Game::Game()
:m_window(sf::VideoMode(800, 660), "Tartarus")
{
    cs=0;
	if (!m_font.loadFromFile("assets/haloween.ttf"))
	throw std::runtime_error("Unable to load the font file");

	if (!m_logo.loadFromFile("assets/tartarus_back.png"))
	throw std::runtime_error("Unable to load the logo file");
	
	if (!m_logo1.loadFromFile("assets/comic1.jpeg"))
	throw std::runtime_error("Unable to load the comic1 file");
		
    if (!m_logo2.loadFromFile("assets/background.png"))
	throw std::runtime_error("Unable to load the splash screen background file");
	
    if (!m_logo3.loadFromFile("assets/comic1_back.png"))
	throw std::runtime_error("Unable to load the comic1 background file");
	
	 if (!m_logo4.loadFromFile("assets/comic2.jpeg"))
	throw std::runtime_error("Unable to load the comic2 file");
	
	 if (!m_logo5.loadFromFile("assets/comic3.jpeg"))
	throw std::runtime_error("Unable to load the comic3 file");
	
	 if (!m_logo6.loadFromFile("assets/Instruction.jpg"))
	throw std::runtime_error("Unable to load the comic3 file");
	
	 if (!m_rock.loadFromFile("assets/rock.png"))
	throw std::runtime_error("Unable to load the Rock file");
	
	if (!m_controlbck.loadFromFile("assets/controls_back.jpg"))
	throw std::runtime_error("Unable to load the Rock file");
	
	if (!m_explosion.loadFromFile("assets/explosion.png"))
	throw std::runtime_error("Unable to load the Rock file");

	if (!m_texture.loadFromFile("assets/30.png"))
	throw std::runtime_error("Unable to load the texture file");
	if (!m_lava.loadFromFile("assets/lava.png"))
	throw std::runtime_error("Unable to load the lava file");
	
	if(!m_floor.loadFromFile("assets/wall1.jpg"))
throw std::runtime_error("Unable to load the key file");
if (!m_key.loadFromFile("assets/key.png"))
	throw std::runtime_error("Unable to load the key file");
	if (!m_orb.loadFromFile("assets/orb.png"))
	throw std::runtime_error("Unable to load the orb file");
	if (!m_bonus.loadFromFile("assets/bonus.png"))
	throw std::runtime_error("Unable to load the bonus file");
	

if (!music.openFromFile("assets/music.ogg"))
    throw std::runtime_error("Unable to load the key file");
	
		m_gameStates[GameState::SplashScreen] = new SplashScreen(this);
		m_gameStates[GameState::Comic1] = new Comic1State(this, m_gameStates[GameState::Comic2]); 
		m_gameStates[GameState::Comic2] = new Comic2State(this,m_gameStates[GameState::Comic3]);
		m_gameStates[GameState::Comic3] = new Comic3State(this,m_gameStates[GameState::Playing]);
        m_gameStates[GameState::Lost] = new LostState(this, m_gameStates[GameState::Playing]);
		m_gameStates[GameState::Playing] = new PlayingState(this,m_gameStates[GameState::SplashScreen]);
		m_gameStates[GameState::Instruction] = new InstructionState(this);
		m_gameStates[GameState::LoadingScreen] = new LoadingScreen(this,m_gameStates[GameState::Playing]);
		m_gameStates[GameState::Won] = new WonState(this, m_gameStates[GameState::Playing]);
		
		changeGameState(GameState::SplashScreen);
}

Game::~Game()
{
	for (GameState* gameState : m_gameStates)
	delete gameState;
}

void Game::run()
{
	sf::Clock frameClock;
	while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();   
                     
                     if (event.type == sf::Event::KeyPressed)
                     {  
                           
                            move1=true;
                        
						 if (event.key.code == sf::Keyboard::P && m_currentState== m_gameStates[0])
						 m_currentState->moveStick(sf::Vector2i(1, 0));
						 if (event.key.code == sf::Keyboard::I)
						 m_currentState->insertCoin();
						 if (event.key.code == sf::Keyboard::S)
						 m_currentState->pressButton();
						 if(cs==0)
						 {
                        if (event.key.code == sf::Keyboard::Left)
						 m_currentState->moveStick(sf::Vector2i(-1, 0));
						 if (event.key.code == sf::Keyboard::Right)
						 m_currentState->moveStick(sf::Vector2i(1, 0));
						 if (event.key.code == sf::Keyboard::Up)
						 m_currentState->moveStick(sf::Vector2i(0, -1));
						 if (event.key.code == sf::Keyboard::Down)
						 m_currentState->moveStick(sf::Vector2i(0, 1));
						 }
						 
						 if(cs==1)
                         {
                             
                        
						 if(event.key.code == sf::Keyboard::Z && m_currentState == m_gameStates[4])
                            m_currentState->moveStick(sf::Vector2i(0, -1));///up
                            if(event.key.code == sf::Keyboard::X && m_currentState == m_gameStates[4])
                            m_currentState->moveStick(sf::Vector2i(0, 1));///down
                            if(event.key.code == sf::Keyboard::C && m_currentState == m_gameStates[4])
                            m_currentState->moveStick(sf::Vector2i(-1, 0));
                            if(event.key.code == sf::Keyboard::V && m_currentState == m_gameStates[4])
                            m_currentState->moveStick(sf::Vector2i(1, 0));
                            
                         }
                         if(cs==2)
                         {
                            
                            
                            if(event.key.code == sf::Keyboard::Num1 && m_currentState == m_gameStates[4])
                            m_currentState->moveStick(sf::Vector2i(0, -1));///up
                            if(event.key.code == sf::Keyboard::Num2 && m_currentState == m_gameStates[4])
                            m_currentState->moveStick(sf::Vector2i(0, 1));///down
                            if(event.key.code == sf::Keyboard::Num8 && m_currentState == m_gameStates[4])
                            m_currentState->moveStick(sf::Vector2i(-1, 0));
                            if(event.key.code == sf::Keyboard::Num9 && m_currentState == m_gameStates[4])
                            m_currentState->moveStick(sf::Vector2i(1, 0));
                         }
                            
                            
						
					 }
					 
        }
        m_currentState->update(frameClock.restart());
		m_window.clear();
		m_currentState->draw(m_window);
        m_window.display();
    }
    
}

void Game::changeGameState(GameState::State gameState)
{
	   m_currentState = m_gameStates[gameState];
}

sf::Font& Game::getFont()
{
	return m_font;
}

sf::Texture& Game::getLogo()
{
	return m_logo;
}
sf::Texture& Game::getLogo1()
{
	return m_logo1;
}

sf::Texture& Game::getTexture()
{
	return m_texture;
}
sf::Texture& Game::getLogo2()
{
	return m_logo2;
}
sf::Texture& Game::getLogo3()
{
	return m_logo3;
}
sf::Texture& Game::getLogo4()
{
	return m_logo4;
}
sf::Texture& Game::getLogo5()
{
	return m_logo5;
}
sf::Texture& Game::getLogo6()
{
	return m_logo6;
}
sf::Texture& Game::getRock()
{
	return m_rock;
}
sf::Texture& Game::getExplosion()
{
	return m_explosion;
}
sf::Texture& Game::getm_floor()
{
	return m_floor;
}
sf::Texture& Game::getm_lava()
{
	return m_lava;
}

sf::Texture& Game::getm_key()
{
	return m_key;
}
sf::Texture& Game::getm_orb()
{
	return m_orb;
}
sf::Texture& Game::getm_bonus()
{
	return m_bonus;
}
sf::Music& Game::getmusic()
{
    return music;
}

sf::Texture& Game::getm_contlback()
{
    return m_controlbck;
}

void Game::changeGameControl()
{
    
    std::cout<<"Changing control \n";
        if(cs==0)
        {
        cs=1;
        std::cout<<"ZXCV \n";
        }
         
         else if(cs==1)
            {
                cs=2;
                std::cout<<"1234";
            }
         else if(cs ==2)
        {cs=0;
            std::cout<<"up down left right \n";}
           
            //control_duration=sf::seconds(5);
            
      
     
}
