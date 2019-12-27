#include "SplashState.hpp"
#include "../Game.hpp"
#include "MenuState.hpp"

#include "spdlog/spdlog.h"

SplashState::SplashState(MessageBus *msgBus, Game& game)
:   State(msgBus, game)
,   m_loadingBar(msgBus)
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
    float percent = deltaTime.asSeconds()/3.0*100;
    m_loadingBar.progress(percent);
    if (this->m_clock.getElapsedTime().asSeconds() > 3){
        send(MSG_SPLASH_STATE_FINISHED);
        spdlog::warn("Splash Fin message sent");
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
