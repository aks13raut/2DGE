#include "GameObject.hpp"

void GameObject::setPosition(sf::Vector2f pos){
    m_position = pos;
    m_sprite.setPosition(pos);
}

void GameObject::setPosition(float x, float y){
    m_position.x = x;
    m_position.y = y;
    m_sprite.setPosition(x,y);
}

void GameObject::setTexture(const sf::Texture& texture){
    m_sprite.setTexture(texture);
}

void GameObject::setTextureRect(const sf::IntRect &rectangle)  {
    m_sprite.setTextureRect(rectangle);
}

sf::Vector2f GameObject::getPosition(){
    return m_position;
}

void GameObject::handleEvent(sf::Event event){
    int speed = 2;

    switch(event.type) {
    
        case sf::Event::KeyPressed:
        switch (event.key.code) {
            case sf::Keyboard::Up:
            displacement.y = -1*speed;
            break;
            case sf::Keyboard::Down:
            displacement.y = speed;
            break;
            case sf::Keyboard::Left:
            displacement.x = -1*speed;
            break;
            case sf::Keyboard::Right:
            displacement.x = speed;
            break;
        }
        break;

        case sf::Event::KeyReleased:
        switch (event.key.code) {
            case sf::Keyboard::Up:
            if(displacement.y < 0)
                displacement.y = 0;
            break;
            case sf::Keyboard::Down:
            if(displacement.y > 0)
                displacement.y = 0;
            break;
            case sf::Keyboard::Left:
            if(displacement.x < 0)
                displacement.x = 0;
            break;
            case sf::Keyboard::Right:
            if(displacement.x > 0)
                displacement.x = 0;
            break;
        }
        break;
    }
}

void GameObject::move(sf::Vector2f disp){
    m_position += disp;
    m_sprite.setPosition(m_position);
}

const sf::Vector2f GameObject::getDisplacement(){
    return displacement;
}

void GameObject::update(sf::Time deletaTime){
    move(displacement);
}

void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(m_sprite, states);
}