
#ifndef TARTARUS_GAME_HPP
#define TARTARUS_GAME_HPP

#include "GameState.hpp"
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <array>

class Game

{
	public:
	Game();
	~Game();
			
	void run();
	
	sf::Font& getFont();
	sf::Texture& getLogo();
	sf::Texture& getLogo1();
	sf::Texture& getLogo2();
	sf::Texture& getLogo3();
	sf::Texture& getLogo4();
	sf::Texture& getLogo5();
    sf::Texture& getLogo6();
	sf::Texture& getTexture();
	sf::Texture& getRock();
	sf::Texture& getExplosion();
	sf::Texture& getm_floor();
	sf::Texture& getm_lava();
	sf::Texture& getm_key();
	sf::Texture& getm_orb();
	sf::Texture& getm_bonus();
	sf::Music& getmusic();
	sf::Texture& getm_contlback();
		bool move1;
	void changeGameState(GameState::State gameState);
	
	void changeGameControl();
	GameState* m_currentState;
	std::array<GameState*, GameState::Count> m_gameStates;
	//std::array<GameState*, GameState::Count> m_gameStates;
	sf::Time control_duration=sf::seconds(10);
	sf::Time load_control_duration=sf::seconds(5);
	bool controlchange=false;
		int cs;
			sf::RenderWindow m_window;
			sf::Music music;
	private:

	
	//std::array<GameState*, GameState::Count> m_gameStates;
	
	sf::Font m_font;
	sf::Texture m_logo,m_logo1,m_logo2,m_logo3,m_logo4,m_logo5,m_logo6,m_controlbck;
	sf::Texture m_texture,m_rock,m_explosion,m_floor,m_lava,m_key,m_orb,m_bonus;
	//sf::Music music;
	


};

#endif //TARTARUS_GAME_HPP
