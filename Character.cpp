
#include "Character.hpp"

Character::Character()
:m_maze(nullptr),
m_speed(2000),
m_currentDirection(0, 0), 
m_nextDirection(0, 0),
m_previousIntersection(0, 0) 
{
    
}



sf::FloatRect Character::getCollisionBox() const 
{
  sf::FloatRect bounds(3, 3, 34, 34);
    return getTransform().transformRect(bounds);
}

void Character::setMaze(Maze* maze) 
{
	m_maze = maze;
}


void Character::setSpeed(float speed)
{
	m_speed = speed;
}

float Character::getSpeed() const 
{
	return m_speed;
}

void Character::setDirection(sf::Vector2i direction,bool move1) 
{
	m_nextDirection = direction;
	Move=move1;
}

sf::Vector2i Character::getDirection() const 
{
	return m_currentDirection;
}


bool Character::willMove() const
{
	return !m_maze->isWall(m_previousIntersection + m_nextDirection);
}

void Character::update1(sf::Time delta,bool m)   ///update Perseus
{
	sf::Vector2f pixelPosition = getPosition();
	setSpeed(getSpeed());
	float pixelTraveled = getSpeed() * delta.asSeconds();
	setScale(-0.3, 0.3);
    if(Move)
    {
    sf::Vector2f nextPixelPosition = pixelPosition+(sf::Vector2f(m_currentDirection)*pixelTraveled);
	setPosition(nextPixelPosition);
    }
	
	sf::Vector2i cellPosition = m_maze->mapPixelToCell(pixelPosition);
	
	sf::Vector2f offset;
	offset.x = std::fmod(pixelPosition.x, 32) - 16;
	offset.y = std::fmod(pixelPosition.y, 32) - 16;
	
        
    
	if (m_maze->isWall(cellPosition + m_currentDirection))
	{		
		if ((m_currentDirection.x == 1 &&  offset.x > 0))
            {
            setPosition(m_maze->mapCellToPixel(cellPosition));
            }
			else if(m_currentDirection.x == -1 && offset.x < 0) 
			{
			setPosition(m_maze->mapCellToPixel(cellPosition));
            }
			else if(m_currentDirection.y == 1 && offset.y > 0) 
			{
			setPosition(m_maze->mapCellToPixel(cellPosition));
		     }
			else if(m_currentDirection.y == -1 && offset.y < 0)
			{
			setPosition(m_maze->mapCellToPixel(cellPosition));
		    }
		
	}
	
	if (!m_maze->isWall(cellPosition + m_nextDirection) && m_currentDirection != m_nextDirection)
	{
		if ((!m_currentDirection.y && (offset.x > -16 && offset.x < 16)) ||
			(!m_currentDirection.x && (offset.y > -16 && offset.y < 16)))
		{
			setPosition(m_maze->mapCellToPixel(cellPosition));
			m_currentDirection = m_nextDirection;
			
			if (m_currentDirection == sf::Vector2i(1, 0))
            {
                setRotation(270);
                setScale(-0.7, 0.7);
            }
            else if (m_currentDirection == sf::Vector2i(0, 1))
            {
                setRotation(0);
                setScale(-0.7, 0.7);
            }
            else if (m_currentDirection == sf::Vector2i(-1, 0))
            {
                setRotation(90);
                setScale(-0.7, 0.7);
            }
            else if (m_currentDirection == sf::Vector2i(0, -1))
            {
                setRotation(180);
                setScale(-0.7, 0.7);
            }
		}
	}
	/*static sf::Vector2i directions[4] = {
        sf::Vector2i(1, 0),
        sf::Vector2i(0, 1),
        sf::Vector2i(-1, 0),
        sf::Vector2i(0, -1)
        };

    if (cellPosition != m_previousIntersection)
    {
        if ((!m_currentDirection.y  && (offset.x > -16 && offset.x < 16)) ||
            (!m_currentDirection.x  && (offset.y > -16 && offset.y < 16)))
        {
            std::array<bool, 4> availableDirections;

            int i = 0;
            for (auto direction : directions)
            {
                availableDirections[i] = m_maze->isWall(cellPosition + direction);
                i++;
            }

            if (m_availableDirections != availableDirections)
            {

                m_previousIntersection = cellPosition;
                m_availableDirections = availableDirections;

                changeDirection();
            }*/    Move=false;
        }
   // }

//}
	
    
void Character::update(sf::Time delta)   ///Update rock
{
	sf::Vector2f pixelPosition = getPosition();
	setSpeed(100.f);
	float pixelTraveled = getSpeed() * delta.asSeconds();
    if(Move)
    {
    sf::Vector2f nextPixelPosition = pixelPosition+(sf::Vector2f(m_currentDirection)*pixelTraveled);
	setPosition(nextPixelPosition);
    }
	
	sf::Vector2i cellPosition = m_maze->mapPixelToCell(pixelPosition);
	
	sf::Vector2f offset;
	offset.x = std::fmod(pixelPosition.x, 32) - 16;
	offset.y = std::fmod(pixelPosition.y, 32) - 16;
	
        
    
	if (m_maze->isWall(cellPosition + m_currentDirection))
	{		
		if ((m_currentDirection.x == 1 &&  offset.x > 0))
            {
            setPosition(m_maze->mapCellToPixel(cellPosition));
            }
			else if(m_currentDirection.x == -1 && offset.x < 0) 
			{
			setPosition(m_maze->mapCellToPixel(cellPosition));
            }
			else if(m_currentDirection.y == 1 && offset.y > 0) 
			{
			setPosition(m_maze->mapCellToPixel(cellPosition));
		     }
			else if(m_currentDirection.y == -1 && offset.y < 0)
			{
			setPosition(m_maze->mapCellToPixel(cellPosition));
		    }
		
	}
	
	if (!m_maze->isWall(cellPosition + m_nextDirection) && m_currentDirection != m_nextDirection)
	{
		if ((!m_currentDirection.y && (offset.x >-2 && offset.x<2)) ||
			(!m_currentDirection.x && (offset.y >-2 && offset.y<2)))
		{
			setPosition(m_maze->mapCellToPixel(cellPosition));
			m_currentDirection = m_nextDirection;
			
			if (m_currentDirection == sf::Vector2i(1, 0))
            {
                setRotation(270);
                setScale(-0.5, 0.5);
            }
            else if (m_currentDirection == sf::Vector2i(0, 1))
            {
                setRotation(0);
                setScale(-0.5, 0.5);
            }
            else if (m_currentDirection == sf::Vector2i(-1, 0))
            {
                setRotation(90);
                setScale(-0.5, 0.5);
            }
            else if (m_currentDirection == sf::Vector2i(0, -1))
            {
                setRotation(180);
                setScale(-0.5, 0.5);
            }
		}
	}
	static sf::Vector2i directions[4] = {
        sf::Vector2i(1, 0),
        sf::Vector2i(0, 1),
        sf::Vector2i(-1, 0),
        sf::Vector2i(0, -1)
        };

    if (cellPosition != m_previousIntersection)
    {
        if ((!m_currentDirection.y  && (offset.x > -2 && offset.x < 2)) ||
            (!m_currentDirection.x  && (offset.y > -2 && offset.y < 2)))
        {
            std::array<bool, 4> availableDirections;

            int i = 0;
            for (auto direction : directions)
            {
                availableDirections[i] = m_maze->isWall(cellPosition + direction);
                i++;
            }

            if (m_availableDirections != availableDirections)
            {

                m_previousIntersection = cellPosition;
                m_availableDirections = availableDirections;

                changeDirection();
            }
        }
    }
//Move=false;
}


