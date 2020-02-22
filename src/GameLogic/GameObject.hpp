#pragma once

#include "SFML/Graphics.hpp"
#include <map>
#include <string>
#include <tmxlite/Object.hpp>

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
    void setSize(float,float);
    void setAABB(const tmx::FloatRect& AABB);
    const sf::FloatRect& getAABB();
    bool intersects(const sf::FloatRect&  target);
    bool contains(const sf::Vector2f&  point);
    void setTexture(const sf::Texture&);
    void setTextureRect(const sf::IntRect &rectangle);
    sf::Vector2f getPosition();
    void move(sf::Vector2f disp);
    const sf::Vector2f getDisplacement();

    void update(sf::Time deltaTime);
    void handleEvent(sf::Event e);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    GameObjectType m_type;
    sf::Sprite     m_sprite;
    sf::Vector2f   m_position;
    sf::FloatRect  m_AABB;
    sf::Vector2f   m_speed;
    sf::Vector2f   m_acceleration;
    sf::Vector2f   displacement;
    std::map<std::string,std::string> m_properties;
};
