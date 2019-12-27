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


void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(m_sprite, states);
}