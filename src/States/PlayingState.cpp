#include "PlayingState.hpp"
#include "../Game.hpp"
#include "MenuState.hpp"

PlayingState::PlayingState(Game& game)
:   State(game)
{
    m_background.setTexture(assets.textures.get("splash_bg"));
    player.setTexture(assets.textures.get("player"));
    player.setPosition(250,250);
}

void PlayingState::handleEvent(sf::Event e){

}
void PlayingState::handleInput(){

}
void PlayingState::update(sf::Time deltaTime){
    
}
void PlayingState::fixedUpdate(sf::Time deltaTime)
{

}
void PlayingState::render(sf::RenderTarget& renderer){
    renderer.draw(m_background);
    renderer.draw(player);
}
