
#ifndef TARTARUS_PERSEUS_HPP
#define TARTARUS_PERSEUS_HPP

#include "Animator.hpp"
#include "Character.hpp"

class Perseus : public Character
{
	public:
	Perseus(sf::Texture& texture); 
	void die();
	
	bool isDying() const;
	bool isDead() const;
	
	void update(sf::Time delta);
	
	void reset();	
	bool MOve;
	
	private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	bool m_isDying;
	bool m_isDead;
	sf::Sprite m_visual;
	
	
	Animator m_runAnimator;
	Animator m_dieAnimator;
};

#endif // TARTARUS_PERSEUS_HPP
