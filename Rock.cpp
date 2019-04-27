#include "Rock.hpp"

Rock::Rock(sf::Texture& texture1,sf::Texture& texture2,Perseus* perseus)
: m_visual1(texture1),
m_visual2(texture2),
m_perseus(perseus)
{
   m_visual1.setOrigin(22.5,26);
   m_visual2.setOrigin(81,81);
  // MOve=Move;
    m_strongAnimator.addFrame(sf::IntRect(10, 6, 45, 52)); 
    m_strongAnimator.addFrame(sf::IntRect(75, 6, 45, 52));  
    m_strongAnimator.addFrame(sf::IntRect(140, 6, 45, 52)); 
    m_strongAnimator.addFrame(sf::IntRect(205, 6, 45, 52)); 
    m_strongAnimator.addFrame(sf::IntRect(270, 6, 45, 52)); 
    m_strongAnimator.addFrame(sf::IntRect(335, 6, 45, 52)); 
    m_strongAnimator.addFrame(sf::IntRect(400, 6, 45, 52)); 
    m_strongAnimator.addFrame(sf::IntRect(465, 6, 45, 52)); 
    m_strongAnimator.addFrame(sf::IntRect(530, 6, 45, 52)); 
    m_strongAnimator.addFrame(sf::IntRect(595, 6, 45, 52)); 
    m_strongAnimator.addFrame(sf::IntRect(660, 6, 45, 52)); 
    m_strongAnimator.addFrame(sf::IntRect(725, 6, 45, 52)); 
    m_strongAnimator.addFrame(sf::IntRect(790, 6, 45, 52)); 
    m_strongAnimator.addFrame(sf::IntRect(855, 6, 45, 52)); 
    m_strongAnimator.addFrame(sf::IntRect(920, 6, 45, 52)); 
    m_strongAnimator.addFrame(sf::IntRect(985, 6, 45, 52)); 
    
   
     m_weakAnimator.addFrame(sf::IntRect(0, 0, 0, 0));
        m_weakAnimator.addFrame(sf::IntRect(0, 0, 192, 192));
         m_weakAnimator.addFrame(sf::IntRect(192, 0, 192, 192));
          m_weakAnimator.addFrame(sf::IntRect(384, 0, 192, 192));
         
        m_weakAnimator.addFrame(sf::IntRect(576, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(768, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(960, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(1152, 0, 192, 192));
        
         m_weakAnimator.addFrame(sf::IntRect(1344, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(1536, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(1728, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(1920, 0, 192, 192));
        
         m_weakAnimator.addFrame(sf::IntRect(2112, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(2304, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(2496, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(2688, 0, 192, 192));
        
         m_weakAnimator.addFrame(sf::IntRect(2880, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(3072, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(3264, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(3456, 0, 192, 192));
        
         m_weakAnimator.addFrame(sf::IntRect(3648, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(3840, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(4032, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(4224, 0, 192, 192));
        
         m_weakAnimator.addFrame(sf::IntRect(4416, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(4608, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(4800, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(4992, 0, 192, 192));
        
         m_weakAnimator.addFrame(sf::IntRect(5184, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(5376, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(5568, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(5760, 0, 192, 192));
        
         m_weakAnimator.addFrame(sf::IntRect(5952, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(6144, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(6336, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(6528, 0, 192, 192));
        
         m_weakAnimator.addFrame(sf::IntRect(6720, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(6912, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(7104, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(7296, 0, 192, 192));
        
         m_weakAnimator.addFrame(sf::IntRect(7488, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(7680, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(7872, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(8064, 0, 192, 192));
        
         m_weakAnimator.addFrame(sf::IntRect(8256, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(8448, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(8640, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(8832, 0, 192, 192));
        
         m_weakAnimator.addFrame(sf::IntRect(9024, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(9216, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(9408, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(9600, 0, 192, 192));
        
         m_weakAnimator.addFrame(sf::IntRect(9792, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(9984, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(10176, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(10368, 0, 192, 192));
        
         m_weakAnimator.addFrame(sf::IntRect(10560, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(10752, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(10944, 0, 192, 192));
        m_weakAnimator.addFrame(sf::IntRect(11136, 0, 192, 192));
        
      
    
    //m_strongAnimator.animate(m_visual2);
   //   m_weakAnimator.animate(m_visual2);
    //
    m_strongAnimator.play(sf::seconds(0.1), true);
   m_weakAnimator.play(sf::seconds(3), false);
     
}

void Rock::setWeak(sf::Time duration)
{
	m_isWeak =true;
	m_weaknessDuration = duration;
}

bool Rock::isWeak() const
{
	return m_isWeak;
}
void Rock::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(m_visual1, states);
	if(isWeak() && Weakanim_draw==1)
	target.draw(m_visual2, states);
}
void Rock::Weakanim_draw1()
{
    Weakanim_draw=1;
    
}
void Rock::Weakanim(sf::Time delta)
{
    m_weakAnimator.update(delta);
    m_weakAnimator.animate(m_visual2);
    
}

void Rock::update(sf::Time delta)
{
	//bool m=true;
	if (m_isWeak)
    {
        m_weaknessDuration -= delta;
        if(collided==1)
        {m_weakAnimator.update(delta);
        m_weakAnimator.animate(m_visual2);}
        
    if (m_weaknessDuration <= sf::Time::Zero)
        {
            m_isWeak = false;
            m_strongAnimator.play(sf::seconds(0.25), true);
            
        }
    }
	
    if (!m_isWeak)
    {
        m_strongAnimator.update(delta);
        m_strongAnimator.animate(m_visual1);
    }
    else
    {   if(collided==1){
        m_weakAnimator.update(delta);
        m_weakAnimator.animate(m_visual2);}
  
    }
    
    Character::update(delta);
}


void Rock::changeDirection() 
{
	static sf::Vector2i directions[4] = {
        sf::Vector2i(1, 0),
        sf::Vector2i(0, 1),
        sf::Vector2i(-1, 0),
        sf::Vector2i(0, -1)
        };
	
	std::map<float, sf::Vector2i> directionProb;
	
	float targetAngle;
	
	sf::Vector2f distance = m_perseus->getPosition() - getPosition();
	
	targetAngle = std::atan2(distance.x, distance.y) * (180/3.14);
	
	for (auto direction : directions)
	{
		float directionAngle = std::atan2(direction.x, direction.y) * (180/3.14);
		
		//Normalize the angle difference
		float diff = 180 - std::abs(std::abs(directionAngle - targetAngle) - 180);
		
		directionProb[diff] = direction;		
	}
	setDirection(directionProb.begin()->second,true);
	
	auto it = directionProb.begin();
	
	do
	{
		setDirection(it->second,true);
		it++;
	}
	while(!willMove());
}
