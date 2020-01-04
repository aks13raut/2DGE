#include "Tile.hpp"


void Tile::init(const sf::Texture &texture,int x,int y,int m,int n,sf::Vector2f tileSize,sf::Vector2f grdSpace){
    size = tileSize;
    gridSpace = grdSpace;
    position = sf::IntRect(
        m * tileSize.x, n * tileSize.y, tileSize.x, tileSize.y
    );
    sprite.setTexture(texture);
    sprite.setTextureRect(position);

    sprite.setScale(sf::Vector2f(
        gridSpace.x/tileSize.x,
        gridSpace.y/tileSize.y
    ));

    sprite.setPosition(sf::Vector2f(
        x * gridSpace.x, y * gridSpace.y
    ));
}

Tile::Tile(const sf::Texture &texture,int x,int y,int m,int n,sf::Vector2f tileSize,sf::Vector2f grdSpace)
:size(tileSize),gridSpace(grdSpace)
{
    position = sf::IntRect(
        m * tileSize.x, n * tileSize.y, tileSize.x, tileSize.y
    );
    sprite.setTexture(texture);
    sprite.setTextureRect(position);

    sprite.setScale(sf::Vector2f(
        gridSpace.x/tileSize.x,
        gridSpace.y/tileSize.y
    ));

    sprite.setPosition(sf::Vector2f(
        x * gridSpace.x, y * gridSpace.y
    ));
};

void Tile::set_position(int x,int y){
    sprite.setPosition(sf::Vector2f(
        x * gridSpace.x, y * gridSpace.y
    ));
}

void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}