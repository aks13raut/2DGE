#pragma once

#include "SFML/Graphics.hpp"

enum GameObjectType{
    PLAYER,
    COIN,
    ENEMY
};

class GameObject : public sf::Drawable
{
public:
    GameObject() = default;
    virtual ~GameObject() = default;

    void setPosition(sf::Vector2f);
    void setPosition(float,float);
    void setTexture(const sf::Texture&);
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    GameObjectType m_type;
    sf::Sprite     m_sprite;
    sf::Vector2f   m_position;
    sf::Vector2f   m_speed;
};
