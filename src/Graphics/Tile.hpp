#include <SFML/Graphics.hpp>

class Tile : public sf::Drawable
{
public:
	Tile() = default;
	Tile(const sf::Texture &texture,int x,int y,int m,int n,sf::Vector2f tileSize,sf::Vector2f grdSpace);
    void init(const sf::Texture &texture,int x,int y,int m,int n,sf::Vector2f tileSize,sf::Vector2f grdSpace);
	void set_position(int x,int y);
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::IntRect position;
	sf::Vector2f size;
	sf::Sprite sprite;
	sf::Vector2f gridSpace;
};