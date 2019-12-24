#include "SplashState.hpp"
#include "../Game.hpp"
#include "StatePlaying.h"

SplashState::SplashState(Game& game)
:   State(game)
{
    m_background.setTexture(assets.textures.get("splash_bg"));
    m_logo.setTexture(assets.textures.get("logo-default"));
    m_logo.setPosition(1280/2-200,720/2-200);
}

void SplashState::handleEvent(sf::Event e){

}
void SplashState::handleInput(){

}
void SplashState::update(sf::Time deltaTime){
    if (this->m_clock.getElapsedTime().asSeconds() > 3){
        m_pGame->pushState<StatePlaying>(*m_pGame);
    }
}
void SplashState::fixedUpdate(sf::Time deltaTime)
{

}
void SplashState::render(sf::RenderTarget& renderer){
    renderer.draw(m_background);
    renderer.draw(m_logo);
}
