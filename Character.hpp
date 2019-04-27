
#ifndef TARTARUS_CHARACTER_HPP
#define TARTARUS_CHARACTER_HPP
#include "Maze.hpp"
#include<array>
#include <SFML/Graphics.hpp>

class Character : public sf::Drawable, public sf::Transformable
{
	public:
	Character();
	
	virtual void update(sf::Time delta);
	virtual void update1(sf::Time delta,bool m);
	void setSpeed (float speed);
	float getSpeed() const;
		bool willMove() const;
	
		void setDirection(sf::Vector2i direction,bool move); 
	sf::Vector2i getDirection() const; 
		void setMaze(Maze* maze); 
		sf::Event event;
		bool Move;
		sf::FloatRect getCollisionBox() const;
		
    protected: 
	virtual void changeDirection() {};
		
    private:
	float m_speed;
	Maze* m_maze; 
	
	sf::Vector2i m_previousIntersection; 
	std::array<bool, 4> m_availableDirections; 
	
	sf::Vector2i m_currentDirection; 
	sf::Vector2i m_nextDirection;

	
};

#endif 
