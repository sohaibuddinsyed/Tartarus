
#ifndef TARTARUS_BONUS_HPP
#define TARTARUS_BONUS_HPP

#include <SFML/Graphics.hpp>

class Bonus : public sf::Drawable, public sf::Transformable
{
	public:
	sf::CircleShape getbonus();
	enum Powerups
	{
		Heart,
		Binocular,
		Flash
	};
	
	public:
	
	Bonus();
	void setPowerup(Powerups object);
	
	private:
	
		sf::Sprite m_visual;
		
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

#endif 
