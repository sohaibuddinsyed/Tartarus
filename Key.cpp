#include "key.hpp"
#include "Game.hpp"

//key::key()
//{
    
	
    
//}
sf::CircleShape getKey()
{
	sf::CircleShape m_key;
	//sf::Texture* m_key7;
	 //if (!m_texture1.loadFromFile("assets/loading_back.jpg"))
	//throw std::runtime_error("Unable to load the Rock file");
	
	
	m_key.setRadius(16);
	//m_key.setFillColor(sf::Color::White);
	//m_key.setTexture(t);
	//m_key.setTextureRect(sf::IntRect(0, 0, 1, 1));
    m_key.setOrigin(16, 16);
	
return m_key;
}

sf::CircleShape getOrb()
{
	sf::CircleShape orb;
	//key k;
	orb.setOrigin(16, 16);
	orb.setRadius(16);
	//orb.setFillColor(sf::Color::Black);
	//orb.setTexture(k.m_key7);
	
	
	return orb;
}
