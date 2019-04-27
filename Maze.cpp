#include "Maze.hpp"
#include "key.hpp"
#include <cassert>
#include<iostream>
Maze::Maze(sf::Texture& texture,sf::Texture& texture7,sf::Texture& texture8,sf::Texture& texture9,sf::Texture& texture10)
:m_mazeSize(0,0)
,m_texture(texture)
,m_texture11(texture7)
,m_texture12(texture8)
,m_texture13(texture9)
,m_texture14(texture10)

{ 
 
 if (!m_texture2.loadFromFile("assets/texture.png"))
	throw std::runtime_error("Unable to load the logo file");
//m_sprite(m_renderTexture.getTexture());
  //m_sprite.setTexture(m_texture2);
  //m_sprite.setPosition(0, 0);
	//if (!m_texture11.loadFromFile("assets/texture1.png"))
	//throw std::runtime_error("Unable to load the logo file");
	 //m_sprite.setTexture(m_texture2);
	 
	// if(!m_textureKey->loadFromFile("assets/key.png"))
//throw std::runtime_error("Unable to load the key file");
	 
	 /*if (!m_textureKey.loadFromFile("assets/key.png"))
	throw std::runtime_error("Unable to load the key file");
	 m_spritekey.setTexture(m_textureKey);
	 
	 if (!m_textureOrb.loadFromFile("assets/Orb.png"))
	throw std::runtime_error("Unable to load the key file");
	 m_spriteOrb.setTexture(m_textureOrb);*/
	
	
	}
	

sf::Texture* Maze::getm_texture()
{
	return &m_texture;
}
sf::Texture* Maze::getm_texture11()
{
	return &m_texture11;
}
//sf::Texture* Maze::getm_textureKey()
//{
	//return &m_textureKey;
//}
sf::Vector2i Maze::getPerseusPosition() const
{
    return m_perseusPosition;
}

void Maze::loadLevel(std::string name)
{
   m_mazeSize = sf::Vector2i(0, 0);
	m_mazeData.clear();
	
	m_perseusPosition = sf::Vector2i(0, 0);
	m_rockPositions.clear();
    	sf::Image levelData;
    	if (!levelData.loadFromFile("assets/levels/" + name + ".png"))
        throw std::runtime_error("Failed to load level (" + name + ")");
        
        m_mazeSize = sf::Vector2i(levelData.getSize());
        
        if (m_mazeSize.x < 15 || m_mazeSize.y < 15)
        throw std::runtime_error("The loaded level is too small (min 15 cells large)");
        
        for (unsigned int y = 0; y < m_mazeSize.y; y++)
		 {
			 for (unsigned int x = 0; x < m_mazeSize.x; x++)
			 {
				 sf::Color cellData = levelData.getPixel(x, y);
				 
		if (cellData == sf::Color::Black)
        {
        	m_mazeData.push_back(Wall);
        }
        else if (cellData == sf::Color::Yellow)
        {
                m_mazeData.push_back(Key1);
        }
        else if (cellData == sf::Color::Green)
        {
        	m_mazeData.push_back(Orb);
        }
        else if (cellData == sf::Color::Blue)
        {
			//pacwoman position
			m_perseusPosition = sf::Vector2i(x, y);
                m_mazeData.push_back(Empty);
        }
        else if (cellData == sf::Color::Red)
        {
			//rock position
			m_rockPositions.push_back(sf::Vector2i(x, y));
                m_mazeData.push_back(Empty);
        }
        else if (cellData == sf::Color::Cyan)
        {
			//rock position
			m_mazeData.push_back(Bonus);
        }
        else{
                m_mazeData.push_back(Empty);
        }
			 }
		 }
		 
		    m_renderTexture.create(32* m_mazeSize.x, 32* m_mazeSize.y);
          //m_renderTexture.draw();
		
		// m_renderTexture.clear();
		  
		  
		  sf::Sprite border(m_texture2);
		 border.setTextureRect(sf::IntRect(16, 0, 16, 32));
		 border.setOrigin(0, 16);
		 
		 sf::Sprite innerCorner(m_texture2);
		 innerCorner.setTextureRect(sf::IntRect(0, 0, 16, 16));
		 innerCorner.setOrigin(0, 16);
		 
		 sf::Sprite outerCorner(m_texture2);
		 outerCorner.setTextureRect(sf::IntRect(0, 16, 16, 16));
		 outerCorner.setOrigin(0, 16);
		 
		
		
		sf::RectangleShape floor;
		floor.setSize(sf::Vector2f(32, 32));
       // floor.setRadius(16);
        floor.setTexture(this->getm_texture11());
		// floor.setTextureRect(sf::IntRect(0, 0, 150, 150)) ;
		 
     
		  sf::CircleShape wall;
		 // wall.setSize(sf::Vector2f(32, 32));
      wall.setRadius(16);
		wall.setTexture(this->getm_texture());
		//wall.setTextureRect(sf::IntRect(0, 0, 150, 150));
		 
		   
    m_renderTexture.clear();
        
        	 
            
        for(unsigned int i=0; i<=m_mazeData.size();i++)
        {
          
        
        sf::Vector2i position = indexToPosition(i);
    
         if(!isWall(position))
            { m_renderTexture.draw(floor);
                floor.setPosition(32*position.x, 32*position.y);
             //m_renderTexture.display();//m_renderTexture.display();
        	 //m_renderTexture.clear();}
             }
		 
		 if (m_mazeData[positionToIndex(position)] == Wall)
		 {
		 m_renderTexture.draw(wall);
		 wall.setPosition(32*position.x, 32*position.y);
		 	//wall.setPosition(32*position.x, 32*position.y);
        //m_renderTexture.draw(wall);
			//std::cout<<"Umar\n"; //
			
			
			border.setPosition(mapCellToPixel(position));
			innerCorner.setPosition(mapCellToPixel(position));
			outerCorner.setPosition(mapCellToPixel(position));
			
			if (!isWall(position + sf::Vector2i(1, 0)))
			{
				border.setRotation(0);
				m_renderTexture.draw(border);
			}
			
			if (!isWall(position + sf::Vector2i(0, 1)))
			{
				border.setRotation(90);
				m_renderTexture.draw(border);
			}
			
			if (!isWall(position + sf::Vector2i(-1, 0)))
			{
				border.setRotation(180);
				m_renderTexture.draw(border);
			}
			
			if (!isWall(position + sf::Vector2i(0, -1)))
			{
				border.setRotation(270);
				m_renderTexture.draw(border);
			}
			
			if (isWall(position + sf::Vector2i(1, 0)) && isWall(position + sf::Vector2i(0, -1)))
			{
				innerCorner.setRotation(0);
				m_renderTexture.draw(innerCorner);
			}
			
			if (isWall(position + sf::Vector2i(0, 1)) && isWall(position + sf::Vector2i(1, 0)))
			{
				innerCorner.setRotation(90);
				m_renderTexture.draw(innerCorner);
			}
			
			if (isWall(position + sf::Vector2i(-1, 0)) && isWall(position + sf::Vector2i(0, 1)))
			{
				innerCorner.setRotation(180);
				m_renderTexture.draw(innerCorner);
			}
			
			if (isWall(position + sf::Vector2i(0, -1)) && isWall(position + sf::Vector2i(-1, 0)))
			{
				innerCorner.setRotation(270);
				m_renderTexture.draw(innerCorner);
			}
						
			if (!isWall(position + sf::Vector2i(1, 0)) && !isWall(position + sf::Vector2i(0, -1)))
			{
				outerCorner.setRotation(0);
				m_renderTexture.draw(outerCorner);
			}
			
			if (!isWall(position + sf::Vector2i(0, 1)) && !isWall(position + sf::Vector2i(1, 0)))
			{
				outerCorner.setRotation(90);
				m_renderTexture.draw(outerCorner);
			}
			
			if (!isWall(position + sf::Vector2i(-1, 0)) && !isWall(position + sf::Vector2i(0, 1)))
			{
				outerCorner.setRotation(180);
				m_renderTexture.draw(outerCorner);
			}
			
			if (!isWall(position + sf::Vector2i(0, -1)) && !isWall(position + sf::Vector2i(-1, 0)))
			{
				outerCorner.setRotation(270);
				m_renderTexture.draw(outerCorner);
			}			
		 }m_renderTexture.display();
			
		 
    }
}
        
std::vector<sf::Vector2i> Maze::getrockPositions() const
{
    return m_rockPositions;
    
}
			


bool Maze::isWall(sf::Vector2i position) const
{
	if (position.x < 0 || position.y < 0 || position.x >= m_mazeSize.x || position.y >= m_mazeSize.y)
		return false;
		
	return m_mazeData[positionToIndex(position)] == Wall;
}

void Maze::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
 	target.draw(sf::Sprite(m_renderTexture.getTexture()), states);
 	//target.draw(sf::Sprite(m_renderTexture.getTexture11()), states);
 	//target.draw(m_sprite);
 	//target.draw(m_sprite);
 	
    static sf::CircleShape key= getKey();
	static sf::CircleShape orb= getOrb();
	static sf::CircleShape b= m_bonus->getbonus();
	
	//sf::Texture key;
	 //if (!key.loadFromFile("assets/key.png"))
	//throw std::runtime_error("Unable to load the Rock file");
	
	//m_sprite1.setPosition(140, 50);
	
	//m_textureKey=m_key->getTexture();
	
	
         for (unsigned int i = 0; i < m_mazeData.size(); i++)
    {
        sf::Vector2i position = indexToPosition(i);

        if (m_mazeData[i] == Key1)
        {  key.setPosition(32*position.x+16, 32*position.y+16);
           key.setTexture(&m_texture12);
	       target.draw(key, states);
        }//
        else if (m_mazeData[i] == Orb)
        {
            
            orb.setPosition(32*position.x+16, 32*position.y+16);
            orb.setTexture(&m_texture13);
            target.draw(orb, states);
        }
        else if (m_mazeData[i] == Bonus)
        {
            
            b.setPosition(32*position.x+16, 32*position.y+16);
            b.setTexture(&m_texture14);
            target.draw(b, states);
        }
	}
}







std::size_t Maze::positionToIndex(sf::Vector2i position) const
{
    return position.y * m_mazeSize.x + position.x;
}




sf::Vector2i Maze::indexToPosition(std::size_t index) const
{
    sf::Vector2i position;

    position.x = index % m_mazeSize.x;
    position.y = index / m_mazeSize.x;

    return position;
}

sf::Vector2i Maze::mapPixelToCell(sf::Vector2f pixel) const
{
    sf::Vector2i cell;
    cell.x = std::floor(pixel.x / 32.f);
    cell.y = std::floor(pixel.y / 32.f);

    return cell;
}

sf::Vector2f Maze::mapCellToPixel(sf::Vector2i cell) const
{
    sf::Vector2f pixel;
    pixel.x = cell.x * 32 + 16;
    pixel.y = cell.y * 32 + 16;

    return pixel;
}
sf::Vector2i Maze::getSize() const
{
	return m_mazeSize;
}
bool Maze::isDot(sf::Vector2i position) const
{
	return m_mazeData[positionToIndex(position)] == Key1;
}

bool Maze::isSuperDot(sf::Vector2i position) const
{
	return m_mazeData[positionToIndex(position)] == Orb;
}

bool Maze::isBonus(sf::Vector2i position) const
{
	return m_mazeData[positionToIndex(position)] == Bonus;
}

void Maze::pickObject(sf::Vector2i position)
{
	if(!isWall(position))
	m_mazeData[positionToIndex(position)] = Empty;
}

int Maze::getRemainingDots() const
{
	int remainingDots = 0;
	
	for (unsigned int i = 0; i < m_mazeData.size(); i++)
	{
		if (m_mazeData[i] == Key1 )
			remainingDots++;
	}
	
	return remainingDots;
}
