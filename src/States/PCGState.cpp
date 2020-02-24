#include "PCGState.hpp"
#include "../Game.hpp"

#include <math.h>
#include "stateHandler.hpp"
#include <spdlog/spdlog.h>

#include "../ResourceManager/TilesetManager.hpp"

PCGState::PCGState(Game& game,std::string filename)
:   State(game)
{
    pcg = new ProceduralGenerator("procedural_genration");
    map = pcg->createMap(filename);

    YAML::Node playerConfig = YAML::LoadFile("game/config/player.yaml");
    std::string textrFile = playerConfig["texture"].as<std::string>();
    sf::IntRect textrRect;
    textrRect.top = playerConfig["texture_rect"]["top"].as<int>();
    textrRect.left = playerConfig["texture_rect"]["left"].as<int>();
    textrRect.width = playerConfig["texture_rect"]["width"].as<int>();
    textrRect.height = playerConfig["texture_rect"]["height"].as<int>();
    player.setSpeed(playerConfig["speed"].as<int>());
    player.setTexture(assets.textures.get(textrFile));
    player.setTextureRect(textrRect);

    YAML::Node gameConfig = game.getConfig();

    float width = gameConfig["width"].as<float>();
    float height = gameConfig["height"].as<float>();
    player.setPosition({45*16,40*16});
    m_view.setCenter(player.getPosition());
    //m_view.setSize(width*0.67,height*0.67);
    player.scale({3,3});
    
}

void PCGState::handleEvent(sf::Event e){
    if(e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::F){
        stateHandler.popState();
    }
    player.handleEvent(e);
}
void PCGState::handleInput(){

}
void PCGState::update(sf::Time deltaTime){
    
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
void PCGState::fixedUpdate(sf::Time deltaTime)
{

}
void PCGState::render(sf::RenderTarget& renderer){
    m_pGame->setView(m_view);
    renderer.draw(map->tla);
    renderer.draw(player);
    m_pGame->setDefaultView();
}
