#include "PlayingState.hpp"
#include "../Game.hpp"
#include "MenuState.hpp"

#include <math.h>

PlayingState::PlayingState(Game& game)
:   State(game)
{

    player.setTexture(assets.textures.get("M_08"));
    player.setTextureRect({0,1,16,16});
    player.setPosition(51*16,45*16);

    m_view.setCenter(50*16,50*16);
    m_view.setSize(640,360);
}

void PlayingState::handleEvent(sf::Event e){
    player.handleEvent(e);
}
void PlayingState::handleInput(){

}
void PlayingState::update(sf::Time deltaTime){
    
    player.update(deltaTime);
    auto screen_center = m_view.getCenter();
    auto player_center = player.getPosition();
    player_center.x += 8;
    player_center.y += 8;
    auto limit = m_pGame->getWindow().getSize();
    limit.x = limit.x/8;
    limit.y = limit.y/8;
    if( abs(screen_center.x - player_center.x) >= limit.x ||
        abs(screen_center.y - player_center.y) >= limit.y )
    {
        m_view.move(player.getDisplacement());
    }
}
void PlayingState::fixedUpdate(sf::Time deltaTime)
{

}
void PlayingState::render(sf::RenderTarget& renderer){
    m_pGame->setView(m_view);
    
    renderer.draw(player);
    m_pGame->setDefaultView();
}
