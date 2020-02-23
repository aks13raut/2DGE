#include "SplashState.hpp"
#include "stateHandler.hpp"
#include "../Game.hpp"
//#include "MenuState.hpp"
#include "PlayingState.hpp"

SplashState::SplashState(Game& game)
:   State(game)
{
    m_background.setTexture(assets.textures.get("splash_bg"));
    m_logo.setTexture(assets.textures.get("logo-default"));
    m_logo.setPosition(1280/2-200,720/2-200);
    m_loadingBar.setPosition({1280/2-400,720-40-20});
}

void SplashState::handleEvent(sf::Event e){

}
void SplashState::handleInput(){

}
void SplashState::update(sf::Time deltaTime){
    float percent = deltaTime.asSeconds()/2.0*100;
    m_loadingBar.progress(percent);
    if (this->m_clock.getElapsedTime().asSeconds() > 2){
        stateHandler.pushState<MenuState>(stateHandler.game());
    }
}
void SplashState::fixedUpdate(sf::Time deltaTime)
{

}
void SplashState::render(sf::RenderTarget& renderer){
    renderer.draw(m_background);
    renderer.draw(m_logo);
    m_loadingBar.render(renderer);
}