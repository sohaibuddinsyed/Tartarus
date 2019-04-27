#include "Perseus.hpp"
#include <iostream>
Perseus::Perseus(sf::Texture& texture)
: m_visual(texture)
, m_isDying(false)
, m_isDead(false)

{
	m_visual.setOrigin(32, 36); 
	texture.setSmooth(true);
	MOve=true;
	
	 m_runAnimator.addFrame(sf::IntRect(125, 8, 64, 72)); 
	 m_runAnimator.addFrame(sf::IntRect(28, 8, 64, 72)); 
     m_runAnimator.addFrame(sf::IntRect(327, 8, 64, 72)); 
     m_runAnimator.addFrame(sf::IntRect(229, 8, 64, 72)); 
   


    m_dieAnimator.addFrame(sf::IntRect(422, 8, 64, 84));
    m_dieAnimator.addFrame(sf::IntRect(522, 8, 64, 84));

         
         //m_runAnimator.animate(m_visual);
         
        // m_runAnimator.play(sf::seconds(0.25), true);
     m_runAnimator.play(sf::seconds(0.1), true);
    
}

void Perseus::die()
{
	//if (m_isDying)
	{
		m_dieAnimator.play(sf::seconds(1), false);
		m_isDead = true;
	} 
}

void Perseus::reset()
{
	//m_isDying = false;
	m_isDead = false;
	
    m_runAnimator.play(sf::seconds(1), true);
	 m_runAnimator.animate(m_visual);
}

bool Perseus::isDying() const
{
	return m_isDying;
}

bool Perseus::isDead() const
{
	return m_isDead;
}

void Perseus::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(m_visual, states);
	//if (!m_isDead)
	
}

void Perseus::update(sf::Time delta)
{
    
   //if (!m_isDead )//&& !m_isDying)
    //{ 
       
       
        if(MOve)
        {   m_runAnimator.update(delta);
            m_runAnimator.animate(m_visual);
           
        
         //m_runAnimator.play(sf::seconds(1), true);
         }
       
    
   else
    {
        m_dieAnimator.update(delta);
        m_dieAnimator.animate(m_visual);

       // if (!m_dieAnimator.isPlaying())
        {
           // m_isDying = false;
            //m_isDead = true;
        }
    }
    
   
      bool mMOve=false;
      Character::update1(delta,mMOve);

}
