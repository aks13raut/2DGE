#include "PlayingState.hpp"
#include "../Game.hpp"
#include "MenuState.hpp"

PlayingState::PlayingState(Game& game)
:   State(game)
{
    map.load("res/tilemaps/map1.tmx");
    
    for (int i=0; i<2; ++i)
    {
        m_layers.push_back(new OrthoLayer(map, i));
    }

    player.setTexture(assets.textures.get("player"));
    player.setPosition(250,250);
}

void PlayingState::handleEvent(sf::Event e){

}
void PlayingState::handleInput(){

}
void PlayingState::update(sf::Time deltaTime){
    for(auto* layer : m_layers){
        layer->update(deltaTime);
    }
}
void PlayingState::fixedUpdate(sf::Time deltaTime)
{

}
void PlayingState::render(sf::RenderTarget& renderer){
    for(auto* layer : m_layers){
        renderer.draw(*layer);
    }
    renderer.draw(player);
}
