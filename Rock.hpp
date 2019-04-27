#ifndef TARTARUS_ROCK_HPP
#define TARTARUS_ROCK_HPP

#include "Animator.hpp"
#include "Character.hpp"
#include "Perseus.hpp"

class Rock : public Character

{
	public:
	    	
	enum State
	{
		Strong,
		Weak
	};
	void setWeak(sf::Time duration);
	bool isWeak() const;
	void Weakanim_draw1();
	void Weakanim(sf::Time delta);
	    int collided=0; sf::Time m_weaknessDuration;
    Rock(sf::Texture& texture1,sf::Texture& texture2,Perseus* perseus); 
    void update(sf::Time delta); 
       // bool MOve();
    protected:
	void changeDirection();
       
	private:
	int    Weakanim_draw=0;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    bool m_isWeak;
	
	
	sf::Sprite m_visual1,m_visual2;
	
	Animator m_strongAnimator;
	Animator m_weakAnimator;
	Perseus* m_perseus;
	
};
	
	#endif
