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
    bool intersects(GameObject& target);
    bool intersects(const std::vector<GameObject*>& list);
    bool contains(const sf::Vector2f&  point);
    void setTexture(const sf::Texture&);
    void setTextureRect(const sf::IntRect &rectangle);
    void scale(const sf::Vector2f scl);
    void setSpeed(int spd);
    sf::Vector2f getPosition();
    void move(sf::Vector2f disp);
    void move(sf::Vector2f disp,const std::vector<GameObject*>& list);
    void revertMove();
    const sf::Vector2f getDisplacement();
    void addProp(std::string key,std::string value);
    std::string getProp(std::string key);
    void update(sf::Time deltaTime);
    void handleEvent(sf::Event e);

    std::string name;
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    GameObjectType m_type;
    sf::Sprite     m_sprite;
    sf::Vector2f   m_position;
    sf::Vector2f   m_revertDisp;
    sf::FloatRect  m_AABB;
    int            m_speed;
    sf::Vector2f   m_acceleration;
    sf::Vector2f   displacement;
    std::map<std::string,std::string> m_properties;

    
};
