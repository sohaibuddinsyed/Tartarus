#include "Bonus.hpp" 

Bonus::Bonus()
//: m_visual(texture)
{
	m_visual.setOrigin(15, 15);
	setPowerup(Heart);
}
sf::CircleShape Bonus:: getbonus()
{
	sf::CircleShape m_key;
	
	
	m_key.setRadius(16);
	
    m_key.setOrigin(16, 16);
	
return m_key;
}
void Bonus::setPowerup(Powerups object)
{
	if (object ==Heart)
	m_visual.setTextureRect(sf::IntRect(32, 0, 30, 30));
	else if (object == Binocular)
	m_visual.setTextureRect(sf::IntRect(32+30, 0, 30, 30));
	else if (object == Flash)
	m_visual.setTextureRect(sf::IntRect(32+60, 0, 30, 30));
}

void Bonus::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(m_visual, states);
}
