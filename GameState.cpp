
#include "GameState.hpp"
#include "Game.hpp"


#include <iostream>

template <typename T>
void centerOrigin(T& drawable)
{
	sf::FloatRect bound = drawable.getLocalBounds();
	drawable.setOrigin(bound.width/2, bound.height/2);
}

GameState::GameState(Game* game)
:m_game(game)
{
}


SplashScreen::~SplashScreen()
{
   
}

Game* GameState::getGame() const
{
	return m_game;
}




///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

SplashScreen::SplashScreen(Game* game)
:GameState(game)
{
    m_sprite1.setTexture(game->getLogo());
	m_sprite1.setPosition(140, 50);
	
	  m_sprite2.setTexture(game->getLogo2());
	m_sprite2.setPosition(0, 0);
	m_displayText1=true;
	
	//music.initialize(game->getmusic());
	if (!music.openFromFile("assets/music.ogg"))
{
    std::cout<<"Error playin";
    // error...
}
		music.play();
		music.setLoop(true);
	
	m_text1.setFont(game->getFont());
	m_text1.setString("Play game");
	m_text1.setOutlineThickness(5.0);
	m_text1.setCharacterSize(70);
	m_text1.setOutlineColor(sf::Color::Black);
	m_text1.setFillColor(sf::Color::White);
		centerOrigin(m_text1);
	m_text1.setPosition(400, 400 );
	
	m_text2.setFont(game->getFont());
	m_text2.setString("Instructions");
	m_text2.setOutlineThickness(5.0);
	m_text2.setCharacterSize(50);
	m_text2.setOutlineColor(sf::Color::Black);
	m_text2.setFillColor(sf::Color::White);
		centerOrigin(m_text2);
	m_text2.setPosition(400, 480 );
	
	m_text3.setFont(game->getFont());
	m_text3.setString("About");
	m_text3.setOutlineThickness(5.0);
	m_text3.setCharacterSize(50);
	m_text3.setOutlineColor(sf::Color::Black);
	m_text3.setFillColor(sf::Color::White);
		centerOrigin(m_text3);
	m_text3.setPosition(400, 540 );
	

	
}
void SplashScreen::insertCoin()
{
    getGame()->changeGameState(GameState::Instruction);
     
	
}
void SplashScreen::pressButton()
{
    getGame()->changeGameState(GameState::About);
	
}
void SplashScreen::moveStick(sf::Vector2i direction)
{if(direction.x==1)
getGame()->changeGameState(GameState::Comic1);
}

void SplashScreen::update(sf::Time delta)
{
static sf::Time timeBuffer = sf::Time::Zero;
	timeBuffer += delta;
	
	while (timeBuffer >= sf::seconds(0.5))
	{
		m_displayText1 = !m_displayText1;
		timeBuffer -= sf::seconds(1);
	}	
}
void SplashScreen::draw(sf::RenderWindow& window)
{
		window.draw(m_sprite2);
		window.draw(m_sprite1);
			
	
	if (m_displayText1)
	{window.draw(m_text1);}
		//window.draw(m_text2);
			//window.draw(m_text3);
}




///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Comic1State::Comic1State(Game* game, GameState* Comic2State) 
:GameState(game)

{
	
	 m_sprite1.setTexture(game->getLogo1());
	m_sprite1.setPosition(30, 80);
	m_text1.setFont(game->getFont());
	m_text1.setString("Next");
		centerOrigin(m_text1);
	m_text1.setPosition(750, 570 );
	 
	 m_sprite3.setTexture(game->getLogo3());
	m_sprite3.setPosition(0, 0);
	
}



void Comic1State::insertCoin()
{
	

}
void Comic1State::pressButton()
{

}
void Comic1State::moveStick(sf::Vector2i direction)
{
    if(direction.x ==1)
	getGame()->changeGameState(GameState::Comic2);
	if(direction.x ==-1)
	getGame()->changeGameState(GameState::SplashScreen);
}
void Comic1State::update(sf::Time delta)
{
}
void Comic1State::draw(sf::RenderWindow& window)
{
    	window.draw(m_sprite3);
    window.draw(m_text1);
	window.draw(m_sprite1);
	
	
}




///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Comic2State::Comic2State(Game* game,GameState* Comic3State)
:GameState(game)
{
    m_sprite1.setTexture(game->getLogo4());
	m_sprite1.setPosition(00, 00);

	m_text1.setFont(game->getFont());
	m_text1.setString("Thus begins the voyage. ");
	m_text1.setOutlineThickness(5.0);
	m_text1.setCharacterSize(70);
	m_text1.setOutlineColor(sf::Color::Yellow);
	m_text1.setFillColor(sf::Color::White);
		centerOrigin(m_text1);
		m_text1.setPosition(400,550);
}

void Comic2State::insertCoin()
{
	getGame()->changeGameState(GameState::Comic3);//m_Perseus.die();
}
void Comic2State::pressButton()
{
	//getGame()->changeGameState(GameState::Comic1);
}
void Comic2State::moveStick(sf::Vector2i direction)
{
    if(direction.x ==-1)
	getGame()->changeGameState(GameState::Comic1);
	
	if(direction.x ==1)
	getGame()->changeGameState(GameState::LoadingScreen);
}



void Comic2State::update(sf::Time delta)
{		
}

void Comic2State::draw(sf::RenderWindow& window)
{
  window.draw(m_sprite1);
  window.draw(m_text1);  //window.draw(m_maze);
}



///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Comic3State::Comic3State(Game* game,GameState* PlayingState)
:GameState(game)
{
 m_sprite1.setTexture(game->getLogo5());
	m_sprite1.setPosition(00, 00);
//

}

void Comic3State::insertCoin()
{
	
}
void Comic3State::pressButton()
{
	
}
void Comic3State::moveStick(sf::Vector2i direction)
{
    if(direction.x ==-1)
	getGame()->changeGameState(GameState::Comic2);
	
	 if(direction.x ==1)
	{
	
	getGame()->changeGameState(GameState::LoadingScreen);}
	
}
void Comic3State::update(sf::Time delta)
{
}
void Comic3State::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite1);
}

///+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

PlayingState::PlayingState(Game* game, GameState* SplashScreenState)
:GameState(game)
  //,m_perseus(game->getTexture())
  ,m_perseus(nullptr)
  ,m_maze(game->getm_lava(),game->getm_floor(),game->getm_key(),game->getm_orb(),game->getm_bonus())
//,m_bonus(game->getm_bonus())
, m_liveCount(3)
, m_score(0)

{
    cd=sf::seconds(3);
   // cd=getGame()->control_duration;
    //lcd=getGame()->load_control_duration;
   // m_perseus.move(100,100);
   if (!m_pause1.loadFromFile("assets/pause.jpg"))
	throw std::runtime_error("Unable to load the logo file");
	m_pause.setTexture(m_pause1);
	m_pause.setTextureRect(sf::IntRect(10, 10, 600,400));
	//m_pause.setScale(sf::Vector2f(1.2f, 1.2f)); 
	centerOrigin(m_pause);
	   
	 //m_pause.setPosition(400,200);
	 if (!m_controlZX.loadFromFile("assets/controls_backzx.png"))
	throw std::runtime_error("Unable to load the logo file");
	m_spriteZx.setTexture(m_controlZX);
	m_spriteZx.setTextureRect(sf::IntRect(10, 10, 600,400));
	//m_pause.setScale(sf::Vector2f(1.2f, 1.2f)); 

	centerOrigin(m_spriteZx);
	
	 if (!m_control12.loadFromFile("assets/controls_back12.png"))
	throw std::runtime_error("Unable to load the logo file");
	m_sprite12.setTexture(m_control12);
	m_sprite12.setTextureRect(sf::IntRect(10, 10, 600,400));
	//m_pause.setScale(sf::Vector2f(1.2f, 1.2f)); 

	centerOrigin(m_sprite12);
	
	 if (!m_controlud.loadFromFile("assets/controls_backud.png"))
	throw std::runtime_error("Unable to load the logo file");
	m_spriteud.setTexture(m_controlud);
	m_spriteud.setTextureRect(sf::IntRect(10, 10, 600,400));
	//m_pause.setScale(sf::Vector2f(1.2f, 1.2f)); 

	centerOrigin(m_spriteud);
	
   
    //m_maze.loadLevel("large-level");
    m_perseus=new Perseus(game->getTexture());//  Gives 30 png 
    m_perseus->setMaze(&m_maze);

   // m_maze.m_textureKey=getGame()->getm_key7();
    	m_perseus->setPosition(m_maze.mapCellToPixel(m_maze.getPerseusPosition())); 
    	m_camera.setSize(sf::Vector2f(800,600));
    	
    		resetToZero();
    	m_camera.setCenter(m_perseus->getPosition());
    	m_scene.create(800,600);
    	//m_camera.zoom(1.2);
    	//getKey(getGame()->getm_key7());
    	//m_maze.setKey(k);
    
    	
      
   // m_camera.setSize(sf::Vector2f(800, 600)); 
	//m_scene.create(800, 600);
	
		m_scoreText.setFont(game->getFont());
	m_scoreText.setCharacterSize(20);
	//m_scoreText.setString("Score");
	m_scoreText.setPosition(10, 620);
	
	m_levelText.setFont(game->getFont());
	m_levelText.setCharacterSize(20);
	//m_levelText.setString("Level");
	m_levelText.setPosition(160, 620);
	
	m_remainingDotsText.setFont(game->getFont());
	m_remainingDotsText.setCharacterSize(20);
	//m_remainingDotsText.setString("Remaining dots");
	m_remainingDotsText.setPosition(280, 620);
	
	for (auto& liveSprite : m_liveSprite)
	{
		liveSprite.setTexture(game->getm_bonus());
		liveSprite.setScale(0.03,0.03);
		//liveSprite.setTextureRect(sf::IntRect(122, 0, 20, 20));
	}
	
	m_liveSprite[0].setPosition(sf::Vector2f(500, 620));
	m_liveSprite[1].setPosition(sf::Vector2f(550, 620));
	m_liveSprite[2].setPosition(sf::Vector2f(600, 620));
}

void PlayingState::loadNextLevel()
{
	m_maze.loadLevel("large-level"); 
	
	m_level++;
	
	int mapLevel = m_level % 2;
	
	if (mapLevel == 0)
		m_maze.loadLevel("large");
	else if (mapLevel == 1)
		m_maze.loadLevel("large-level");
	
		
	// Destroy previous characters
	for (Rock* rock : m_rock)
			delete rock;
			
		m_rock.clear();
		
	// Create new characters
	for (auto rockPosition : m_maze.getrockPositions()) 
	{
		Rock* rock = new Rock(getGame()->getRock(),getGame()->getExplosion(), m_perseus);
		rock->setMaze(&m_maze);
		rock->setPosition(m_maze.mapCellToPixel(rockPosition));
		
		m_rock.push_back(rock);
	}
	
	// Change speed according to the new level
	//float speed = 100 + (speedLevel * 50);
	
	//m_pacWoman->setSpeed(speed+25);
	
	//for (auto& ghost : m_ghosts)
			//ghost->setSpeed(speed);
			
	moveCharactersToInitialPosition();
	
	//Update level text
	//m_levelText.setString("level " + std::to_string(speedLevel) + " - " + std::to_string(mapLevel+1));
			
}

PlayingState::~PlayingState()
{
    delete m_perseus;
    for (Rock* rock : m_rock)
		delete rock;
}
void PlayingState::moveCharactersToInitialPosition()
{
	m_perseus->setPosition(m_maze.mapCellToPixel(m_maze.getPerseusPosition()));

    auto rockPositions = m_maze.getrockPositions();
    for (unsigned int i = 0; i < m_rock.size(); i++)
        m_rock[i]->setPosition(m_maze.mapCellToPixel(rockPositions[i]));
        
    updateCameraPosition();    
}


void PlayingState::updateCameraPosition()
{
	m_camera.setCenter(m_perseus->getPosition());
	m_pause.setPosition(m_perseus->getPosition());
	m_sprite12.setPosition(m_perseus->getPosition());
	m_spriteud.setPosition(m_perseus->getPosition());
	m_spriteZx.setPosition(m_perseus->getPosition());
	if (m_camera.getCenter().x < 400 )
		{m_camera.setCenter(400, m_camera.getCenter().y);
		 m_pause.setPosition(400,m_camera.getCenter().y);
		 m_spriteZx.setPosition(400,m_camera.getCenter().y);
		 m_spriteud.setPosition(400,m_camera.getCenter().y);
		 m_sprite12.setPosition(400,m_camera.getCenter().y);
		 }
	if (m_camera.getCenter().y < 300)
		{m_camera.setCenter(m_camera.getCenter().x, 300);
		m_pause.setPosition(m_camera.getCenter().x,300);
		m_spriteZx.setPosition(m_camera.getCenter().x,300);
		m_spriteud.setPosition(m_camera.getCenter().x,300);
		m_sprite12.setPosition(m_camera.getCenter().x,300);
		}
		
	if (m_camera.getCenter().x > m_maze.getSize().x *32 - 400)
		{m_camera.setCenter(m_maze.getSize().x *32 - 400, m_camera.getCenter().y);
		m_pause.setPosition(m_maze.getSize().x*32-400,m_camera.getCenter().y);
		m_spriteZx.setPosition(m_maze.getSize().x*32-400,m_camera.getCenter().y);
		m_spriteud.setPosition(m_maze.getSize().x*32-400,m_camera.getCenter().y);
		m_sprite12.setPosition(m_maze.getSize().x*32-400,m_camera.getCenter().y);
		}
		
	if (m_camera.getCenter().y > m_maze.getSize().y *32 - 300)
		{m_camera.setCenter(m_camera.getCenter().x, m_maze.getSize().y *32 - 300);
		m_pause.setPosition(m_camera.getCenter().x,m_maze.getSize().y*32-300);
		m_spriteZx.setPosition(m_camera.getCenter().x,m_maze.getSize().y*32-300);
		m_spriteud.setPosition(m_camera.getCenter().x,m_maze.getSize().y*32-300);
		m_sprite12.setPosition(m_camera.getCenter().x,m_maze.getSize().y*32-300);
		}
		
        
  
}

int PlayingState::ispause()
{
    return pause;
}

void PlayingState::insertCoin()
{
    if(pause==1)
        pause=0;
    else
	pause=1;
	
}
void PlayingState::pressButton()
{
	
	
	getGame()->changeGameState(GameState::SplashScreen);
}
void PlayingState::moveStick(sf::Vector2i direction)
{
 
	moveStickR(direction,getGame()->move1);
	
	
        
}

void PlayingState::moveStickR(sf::Vector2i direction,bool move1)
{
   Move=move1;
	m_perseus->setDirection(direction,Move);///Movement
	m_perseus->MOve=Move;
	
}

void PlayingState::resetToZero()
{
	resetLiveCount();
	
	m_level = 0;
	resetCurrentLevel();
	
	//m_score = 0;
}

void PlayingState::resetCurrentLevel()
{
	m_level--;
	loadNextLevel();
}

void PlayingState::resetLiveCount()
{
	m_liveCount = 3;
}
void PlayingState::update(sf::Time delta)
{ if(!pause)
{
      //cd=getGame()->control_duration;
     
      getGame()->control_duration-=delta;
      if(   getGame()->control_duration <= sf::Time::Zero)
       {
           getGame()->changeGameControl();
           getGame()->controlchange=true;
           pause=1;
            
       }

    bool M=true;
  
    	for (Rock* rock : m_rock)
		{rock->update(delta);
		rock->Weakanim(delta);}
		m_perseus->update(delta);
		sf::Vector2f pixelPosition = m_perseus->getPosition();
   
   
             
               
    sf::Vector2f offset(std::fmod(pixelPosition.x, 32), std::fmod(pixelPosition.y, 32));
	offset -= sf::Vector2f(16, 16);
	
	if (offset.x <= 2 && offset.x >= -2 && offset.y <= 2 && offset.y >= -2)
	{
		sf::Vector2i cellPosition = m_maze.mapPixelToCell(pixelPosition);
		
		if (m_maze.isDot(cellPosition))
		{
		    
			//m_perseus->setSpeed(4000);
			
				//m_perseus->setSpeed(1900);
				//for(int i=0;i<1000000;i++);
				//m_perseus->setSpeed(4000);
		}
		else if (m_maze.isSuperDot(cellPosition))
		{
			
			for (Rock* rock : m_rock)
				rock->setWeak(sf::seconds(5));
				
				m_score += 25;
                
				
				
		}
		else if (m_maze.isBonus(cellPosition))
		{
       if(m_liveCount<3)
        m_liveCount++;
			//m_score += 500;
		}
		
		m_maze.pickObject(cellPosition);
	}	
	for (Rock* rock: m_rock)
	{
		if (rock->getCollisionBox().intersects(m_perseus->getCollisionBox()))
		{rock->collided=1;
			if (rock->isWeak())
			{
                //rock->Weakanim(delta);
                //rock->Weakanim_draw1();
                rock->collided=1;
                //if(rock->m_weaknessDuration==sf::Time::Zero)
				m_rock.erase(std::find(m_rock.begin(), m_rock.end(), rock));
				
        m_score += 100;
			}
			else
				m_perseus->die();
		}
		else
            rock->collided=0;
	}
      
	if (m_perseus->isDead())
	{
		m_perseus->reset();
		
		m_liveCount--;
		
		if (m_liveCount < 0)
		    getGame()->changeGameState(GameState::Lost);
		else
		    moveCharactersToInitialPosition();
	}
	
		if (m_maze.getRemainingDots() == 0)
	{
    getGame()->changeGameState(Won);
    // loadNextLevel();
     updateCameraPosition(); 
	}  
      updateCameraPosition(); 
      m_scoreText.setString("Six keys in total");
	m_remainingDotsText.setString(" Find all keys to win ");       
}
    if(pause) 
    {
    
    if(getGame()->controlchange==true )
     {//lcd=getGame()->load_control_duration;
        getGame()->load_control_duration-=delta;
   // updateCameraPosition();
      
       if(getGame()->cs==1)
        drawzx=true;
     else if(getGame()->cs==2)
        draw12=true;
        else if(getGame()->cs==0)
        drawud=true;
         
      
    //sd=getGame()->load_control_duration;
     if( getGame()->load_control_duration <= sf::Time::Zero)
        {
             pause=0;
        
         drawzx=false;
         drawud=false;
         draw12=false;
          getGame()->controlchange=false;
          getGame()->load_control_duration=sf::seconds(5);
          getGame()->control_duration=sf::seconds(10);
          }
     
        }
     
    
    }


}

void PlayingState::draw(sf::RenderWindow& window)
{    
   
    m_scene.clear();
    m_scene.draw(m_maze);
      m_scene.draw(*m_perseus);
     m_scene.setView(m_camera);
   	for (Rock* rock : m_rock)
	  m_scene.draw(*rock);
	  	
	 
	
	
	
	 if(ispause() && drawzx)
     {//m_pause.setPosition(m_perseus->getPosition());
           m_scene.draw(m_spriteZx);
          std::cout<<"SpriteZX\n";
     }
      if(ispause() && draw12)
     {//m_pause.setPosition(m_perseus->getPosition());
          m_scene.draw(m_sprite12);
          std::cout<<"Sprite12\n";
     }
      if(ispause() && drawud)
     {//m_pause.setPosition(m_perseus->getPosition());
         m_scene.draw(m_spriteud);
          std::cout<<"Spriteud\n";
     }
      if(ispause()&&!drawzx && !draw12 && !drawud)
         m_scene.draw(m_pause);
         
         m_scene.display();
         window.draw(sf::Sprite(m_scene.getTexture()));
     
     window.draw(m_scoreText);
	//window.draw(m_levelText);
	window.draw(m_remainingDotsText);
	for (unsigned int i=0; i < m_liveCount; i++)
		window.draw(m_liveSprite[i]);
       
    //window.draw(m_maze);
    	
     //window.display();
    //window.draw(getGame()->getTexture()); 
}




///_________________________________________________________________________________________________

///_______________________________________________________________________________________________________

InstructionState::InstructionState(Game* game)
:GameState(game)
{
      m_text.setFont(game->getFont());
	m_text.setString("Instructions ");
		centerOrigin(m_text);
		m_text.setOutlineThickness(5.0);
	m_text.setCharacterSize(70);
	m_text.setOutlineColor(sf::Color::Red);
	m_text.setFillColor(sf::Color::White);
	m_text.setPosition(400, 100 );
      m_sprite1.setTexture(game->getm_contlback());
      //centerOrigin(m_sprite1);
	m_sprite1.setPosition(0, 0);
	//m_sprite1.setScale(0.5,0.5);
	
	m_text1.setFont(game->getFont());
	m_text1.setString("Collect all the keys while dodging the rocks. ");
	m_text1.setOutlineThickness(2.0);
	m_text1.setCharacterSize(50);
	
	m_text1.setFillColor(sf::Color::White);
		centerOrigin(m_text1);
		
		m_text1.setPosition(400,200);
	m_text2.setFont(game->getFont());
	m_text2.setString("Absorb the orbs to destroy the rocks.");
	m_text2.setOutlineThickness(2.0);
	m_text2.setCharacterSize(50);
	
	m_text2.setFillColor(sf::Color::White);
		centerOrigin(m_text2);
		m_text2.setPosition(400,230);
		
		
	m_text3.setFont(game->getFont());
	m_text3.setString("Collect the hearts to gain an extra life.");
	m_text3.setOutlineThickness(2.0);
	m_text3.setCharacterSize(50);
	
	m_text3.setFillColor(sf::Color::White);
		centerOrigin(m_text3);
		m_text3.setPosition(400,260);
		
		m_text4.setPosition(400,290);
	m_text4.setFont(game->getFont());
	m_text4.setString("Collect the hearts to gain an extra life.");
	m_text4.setOutlineThickness(2.0);
	m_text4.setCharacterSize(50);
	
	m_text4.setFillColor(sf::Color::White);
		centerOrigin(m_text4);
		
		//::Texture& Game::getm_contlback();
		
    
}

void InstructionState::insertCoin()
{
	getGame()->changeGameState(GameState::SplashScreen);
}
void InstructionState::pressButton()
{
	
}
void InstructionState::moveStick(sf::Vector2i direction)
{
	
	
	
	if(getGame()->controlchange==true)
	if(direction.x ==-1)
        getGame()->changeGameState(GameState::Playing);
}
void InstructionState::update(sf::Time delta)
{
}
void InstructionState::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite1);
    window.draw(m_text1);
}

///_________________________________________________________________________________________________
LoadingScreen::LoadingScreen(Game* game,GameState* PlayingState)
:GameState(game)
{
    
    if (!m_texture1.loadFromFile("assets/loading_back.jpg"))
	throw std::runtime_error("Unable to load the Rock file");
m_sprite1.setTexture(m_texture1);
	m_sprite1.setPosition(00, 00);
	
	m_text1.setFont(game->getFont());
	m_text1.setString("Press S to Start");
	m_text1.setOutlineThickness(5.0);
	m_text1.setCharacterSize(100);
	m_text1.setOutlineColor(sf::Color::Black);
	m_text1.setFillColor(sf::Color::White);
		centerOrigin(m_text1);
	m_text1.setPosition(400, 400 );
	
	m_text2.setFont(game->getFont());
	m_text2.setString("LOading..........");
	m_text2.setCharacterSize(70);
	m_text2.setOutlineThickness(5.0);
	m_text2.setOutlineColor(sf::Color::Black);
	m_text2.setFillColor(sf::Color::White);
		centerOrigin(m_text2);
	m_text2.setPosition(400, 400 );
	
	m_text3.setFont(game->getFont());
	m_text3.setString("Welcome to Tartarus ");
	m_text3.setOutlineThickness(5.0);
	m_text3.setCharacterSize(70);
	m_text3.setOutlineColor(sf::Color::Black);
	m_text3.setFillColor(sf::Color::White);
		centerOrigin(m_text3);
		m_text3.setPosition(430,100);
}

void LoadingScreen::insertCoin()
{
	
}
void LoadingScreen::pressButton()
{Clear=1;

getGame()->music.stop();
draw(getGame()->m_window);
	timeout();
}
void LoadingScreen::timeout()
{
    
    for(int i=0;i<1500;i++)
    {
        std::cout<<"a\n";
    }
    
    getGame()->changeGameState(GameState::Playing);
	
}
void LoadingScreen::moveStick(sf::Vector2i direction)
{
    	if(direction.x==-1)
    	getGame()->changeGameState(GameState::Comic2);
}
void LoadingScreen::update(sf::Time delta)
{
static sf::Time timeBuffer = sf::Time::Zero;
	timeBuffer += delta;
	
	while (timeBuffer >= sf::seconds(0.5))
	{
		m_displayText1 = !m_displayText1;
		timeBuffer -= sf::seconds(1);
	}	
}
void LoadingScreen::draw(sf::RenderWindow& window)
{ 
    window.draw(m_sprite1);
    window.draw(m_text3);
    if(Clear==1)
    {window.draw(m_text2);}
    if(Clear==0)
    {   
        if (m_displayText1)
        {window.draw(m_text1);}
    }
   
     
      
}

///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
AboutState::AboutState(Game* game, GameState* SplashScreen)
:GameState(game)

{
	 if (!t1.loadFromFile("assets/about.jpg"))
	throw std::runtime_error("Unable to load the Rock file");
s1.setTexture(t1);
	s1.setPosition(00, 00);
	
	tx1.setFont(game->getFont());
	tx1.setString("About");
	tx1.setOutlineThickness(5.0);
	tx1.setCharacterSize(70);
	tx1.setOutlineColor(sf::Color::Black);
	tx1.setFillColor(sf::Color::White);
		centerOrigin(tx1);
	tx1.setPosition(400, 50 );
	
}


void AboutState::insertCoin()
{
}
void AboutState::pressButton()
{
	 getGame()->changeGameState(GameState::SplashScreen);
}
void AboutState::moveStick(sf::Vector2i direction)
{
	
}
void AboutState::update(sf::Time delta)
{
	
}
void AboutState::draw(sf::RenderWindow& window)
{
   window.draw(s1);
   window.draw(tx1);
}
///________________________________________________________________________________________________________
LostState::LostState(Game* game, GameState* LoadingScreen)
:GameState(game)
, m_playingState(static_cast<PlayingState*>( LoadingScreen))
{
    m_countDown=sf::Time::Zero;
    if (!m_texture.loadFromFile("assets/lose..jpg"))
	throw std::runtime_error("Unable to load the logo file");
	 m_sprite.setTexture(m_texture);
	m_sprite.setPosition(0,0);
	
		m_text1.setFont(game->getFont());
	m_text1.setString("You lost ");
	m_text1.setOutlineThickness(5.0);
	m_text1.setCharacterSize(70);
	m_text1.setOutlineColor(sf::Color::Red);
	m_text1.setFillColor(sf::Color::White);
		centerOrigin(m_text1);
		m_text1.setPosition(400,100);
		
		m_text2.setFont(game->getFont());
	m_text2.setString("You lost ");
	m_text2.setOutlineThickness(5.0);
	m_text2.setCharacterSize(50);
	//m_text2.setOutlineColor(sf::Color::);
	m_text2.setFillColor(sf::Color::White);
		centerOrigin(m_text2);
		m_text2.setPosition(400,500);
		
	
}


void LostState::insertCoin()
{
}
void LostState::pressButton()
{
	m_playingState->resetCurrentLevel();
	m_playingState->resetLiveCount();
	
	getGame()->changeGameState(GameState::LoadingScreen);
}
void LostState::moveStick(sf::Vector2i direction)
{
	
}
void LostState::update(sf::Time delta)
{	m_countDown += delta;
	
	if (m_countDown.asSeconds() >= 10)
	{
		m_playingState->resetToZero();
		
		getGame()->changeGameState(GameState::SplashScreen);
	}
	
}
void LostState::draw(sf::RenderWindow& window)
{
      window.draw(m_sprite);
      window.draw(m_text1);
}
///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
WonState::WonState(Game* game, GameState*LoadingScreen)
:GameState(game)
, m_playingState(static_cast<PlayingState*>(LoadingScreen))
{if (!m_texture.loadFromFile("assets/win.jpg"))
	throw std::runtime_error("Unable to load the logo file");
	 m_sprite.setTexture(m_texture);
	m_sprite.setPosition(0,0);
}


void WonState ::insertCoin()
{
}
void WonState::pressButton()
{
	
}
void WonState::moveStick(sf::Vector2i direction)
{
	
}
void WonState::update(sf::Time delta)
{
		static sf::Time timeBuffer = sf::Time::Zero;
	timeBuffer += delta;
	
	if (timeBuffer.asSeconds() > 5)
	{
		m_playingState->loadNextLevel();
		
		getGame()->changeGameState(GameState::LoadingScreen);
	}
}
void WonState::draw(sf::RenderWindow& window)
{
   window.draw(m_sprite);
   }
