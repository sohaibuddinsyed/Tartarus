#ifndef TARTARUS_GAMESTATE_HPP
#define TARTARUS_GAMESTATE_HPP
#include<SFML/Audio.hpp>
#include "Maze.hpp"
#include "Rock.hpp"
#include "bonus.hpp"
#include "Perseus.hpp"
#include <SFML/Graphics.hpp>
class Game;

class GameState
{
	public:
	
	enum State
	{
		SplashScreen,
		Comic1,
		Comic2,
		Comic3,
		Playing,
		Lost,
		Won,
		Instruction,
		LoadingScreen,
		About,
		Count
	};
	
	GameState (Game* game);	
	Game* getGame() const;
		
	virtual void insertCoin()=0;
	virtual void pressButton()=0;
	virtual void moveStick(sf::Vector2i direction)=0;
	virtual void update(sf::Time delta)=0;
	virtual void draw(sf::RenderWindow& window)=0;
	//virtual void moveStick(sf::Vector2i direction,bool m)=0;

		
	private:
			Game* m_game;
    sf::Text m_text;
        sf::Sprite m_sprite;
};


class SplashScreen : public GameState
{
public:

	SplashScreen (Game* game);
	~SplashScreen();
	
	void insertCoin();
	void pressButton();
	void moveStick(sf::Vector2i direction);
	void update(sf::Time Delta);
	void draw(sf::RenderWindow& window);
	
	private:
	sf::Text m_text1,m_text2,m_text3;
	sf::Sprite m_sprite1,m_sprite2,m_sprite3;
	sf::Music music;
	
	bool m_displayText1;
};

class Comic1State : public GameState
{
public:

	Comic1State (Game* game, GameState* Comic2); 
	
	void insertCoin();
	void pressButton();
	void moveStick(sf::Vector2i direction);
	void update(sf::Time Delta);
	void draw(sf::RenderWindow& window);
	
	private:
	sf::Text m_text1;
	sf::Sprite m_sprite1,m_sprite2,m_sprite3;
	GameState* m_Comic2State; 
		
};

class Comic2State : public GameState
{
public:

	Comic2State (Game* game,GameState* Comic3State);
	~Comic2State();
		
	void insertCoin();
	void pressButton();
	void moveStick(sf::Vector2i direction);
	void update(sf::Time Delta);
	void draw(sf::RenderWindow& window);
private:
    sf::Text m_text1;
	sf::Sprite m_sprite1,m_sprite2,m_sprite3;
   // Maze m_maze;

};

class Comic3State : public GameState
{
public:

	Comic3State (Game* game,GameState* PlayingState);
	
	void insertCoin();
	void pressButton();
	void moveStick(sf::Vector2i direction);
	void update(sf::Time Delta);
	void draw(sf::RenderWindow& window);
private:
      sf::Text m_text1;
	sf::Sprite m_sprite1,m_sprite2,m_sprite3;
	
};




class PlayingState : public GameState
{
public:

	PlayingState (Game* game, GameState* Comic2State);
	~PlayingState();
	void insertCoin();
	void pressButton();
	void moveStick(sf::Vector2i direction);
	void moveStickR(sf::Vector2i direction,bool move1);
	void update(sf::Time Delta);
	void draw(sf::RenderWindow& window);
	bool Move;
	
	void loadNextLevel();
		void resetToZero();
	void resetCurrentLevel();
	void resetLiveCount();
	void updateCameraPosition();
//	Key *k;
    void moveCharactersToInitialPosition();
    int ispause();
   sf::Time cd,lcd;
	private:
	sf::Text m_text;
	sf::Texture m_pause1,m_controlZX,m_control12,m_controlud;
	sf::Sprite m_sprite,m_pause,m_spriteZx,m_sprite12,m_spriteud;
	Perseus* m_perseus;
	//Bonus  m_bonus;
	std::vector<Rock*> m_rock;
	Maze m_maze;
	bool drawzx,draw12,drawud;
	int m_level,pause=0; ///pause=0 =>play
		int m_score;
			
	int m_liveCount;
	sf::View m_camera;
	sf::RenderTexture m_scene;
	
		sf::Text m_scoreText;
	sf::Text m_levelText;
	sf::Text m_remainingDotsText;
	sf::Sprite m_liveSprite[3];


};
class InstructionState : public GameState
{
public:

	InstructionState (Game* game);
	
	
	void insertCoin();
	void pressButton();
	void moveStick(sf::Vector2i direction);
	void update(sf::Time Delta);
	void draw(sf::RenderWindow& window);
	
	private:
	   
	    sf::Sprite m_sprite1;
	    sf::Text m_text,m_text1,m_text2,m_text3,m_text4;
};
class LoadingScreen : public GameState
{
public:

	LoadingScreen (Game* game, GameState* PlayingState); 
	
	void insertCoin();
	void pressButton();
	void moveStick(sf::Vector2i direction);
	void update(sf::Time Delta);
	void draw(sf::RenderWindow& window);
	void timeout();
	
	private:
	    int Clear=0;
	sf::Text m_text1,m_text2,m_text3;
	sf::Texture m_texture1;
	sf::Sprite m_sprite1,m_sprite2,m_sprite3;
	bool m_displayText1=true;
	//GameState* m_Comic2State; 
		
};

class AboutState : public GameState
{
public:

	AboutState (Game* game, GameState* SplashScreen);
	
	void insertCoin();
	void pressButton();
	void moveStick(sf::Vector2i direction);
	void update(sf::Time Delta);
	void draw(sf::RenderWindow& window);
private:
    sf::Texture t1;
    sf::Sprite s1;
    sf::Text tx1;
};	

class LostState : public GameState
{
public:

	LostState (Game* game, GameState* PlayingState);
	
	void insertCoin();
	void pressButton();
	void moveStick(sf::Vector2i direction);
	void update(sf::Time Delta);
	void draw(sf::RenderWindow& window);
	
private:
    PlayingState* m_playingState;
    sf::Texture m_texture;
	sf::Sprite m_sprite;
		sf::Time m_countDown=sf::seconds(5);
		sf::Text m_text1,m_text2;
};

class WonState : public GameState
{
public:

	WonState (Game* game, GameState* PlayingState);
	
	void insertCoin();
	void pressButton();
	void moveStick(sf::Vector2i direction);
	void update(sf::Time Delta);
	void draw(sf::RenderWindow& window);
	
private:
    	PlayingState* m_playingState;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};
# endif // TARTARUS_GAMESTATE_HPP
