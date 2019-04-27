
#ifndef PACWOMAN_MAZE_HPP
#define PACWOMAN_MAZE_HPP
#include "Key.hpp"
#include "bonus.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

class Maze : public sf::Drawable , public sf::Transformable
{
	public:
	
	Maze(sf::Texture& texture,sf::Texture& texture7,sf::Texture& texture8,sf::Texture& texture9,sf::Texture& texture10);
	void loadLevel(std::string name);
	
	sf::Vector2i getPerseusPosition() const;
	std::vector<sf::Vector2i> getrockPositions() const;
	
	inline std::size_t positionToIndex(sf::Vector2i position) const;
	inline sf::Vector2i indexToPosition(std::size_t index) const;
	
		sf::Vector2i mapPixelToCell(sf::Vector2f pixel) const;
	sf::Vector2f mapCellToPixel(sf::Vector2i cell) const;
	
	bool isWall(sf::Vector2i position) const;
		sf::Vector2i getSize() const;
		
   // void setKey(Key* k);
    bool isDot(sf::Vector2i position) const;
	bool isSuperDot(sf::Vector2i position) const;
	void pickObject(sf::Vector2i position);
	
	bool isBonus(sf::Vector2i position) const;
	
	sf::Texture* getm_texture();
	sf::Texture* getm_texture11();
int getRemainingDots() const;
	
   private:
	Bonus *m_bonus;
	enum CellData
	{
		Empty,
		Wall,
		Key1,
		Orb,
		Bonus
	};
	
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	sf::Vector2i m_mazeSize;
	std::vector<CellData> m_mazeData;
		sf::Vector2i m_perseusPosition;
	std::vector<sf::Vector2i> m_rockPositions;
		
   
	sf::RenderTexture m_renderTexture;
	sf::Texture m_texture1,m_texture2,m_textureOrb;
	sf::Sprite m_sprite,m_spritekey,m_spriteOrb;
    sf::Texture& m_texture;
    sf::Texture& m_texture11;
     sf::Texture& m_texture12;
    sf::Texture& m_texture13;
    sf::Texture& m_texture14;
    //sf::Texture& keyyy;

};

#endif // PACWOMAN_MAZE_HPP
