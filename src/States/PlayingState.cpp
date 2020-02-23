#include "PlayingState.hpp"
#include "../Game.hpp"
#include "MenuState.hpp"

#include <math.h>
#include "stateHandler.hpp"
#include <spdlog/spdlog.h>
#include <tmxlite/Map.hpp>
#include <tmxlite/Layer.hpp>
#include <tmxlite/TileLayer.hpp>
#include <tmxlite/ObjectGroup.hpp>
#include "yaml-cpp/yaml.h"

#include "../ResourceManager/TilesetManager.hpp"

PlayingState::PlayingState(Game& game)
:   State(game)
{
    YAML::Node playerConfig = YAML::LoadFile("game/config/player.yaml");
    std::string textrFile = playerConfig["texture"].as<std::string>();
    sf::IntRect textrRect;
    textrRect.top = playerConfig["texture_rect"]["top"].as<int>();
    textrRect.left = playerConfig["texture_rect"]["left"].as<int>();
    textrRect.width = playerConfig["texture_rect"]["width"].as<int>();
    textrRect.height = playerConfig["texture_rect"]["height"].as<int>();

    player.setTexture(assets.textures.get(textrFile));
    player.setTextureRect(textrRect);
    //player.setPosition(51*16,45*16);
    //player.setAABB({0,0,11,11});

    YAML::Node gameConfig = game.getConfig();

    int width = gameConfig["width"].as<int>();
    int height = gameConfig["height"].as<int>();
    m_view.setSize(width*0.75,height*0.75);

    
    tmx::Map map;
    map.load("res/tilemaps/"+gameConfig["map file"].as<std::string>()+".tmx");

    MapLayer* layerZero = new MapLayer(map, 0);
    layers.emplace_back(layerZero);
    MapLayer* layerOne = new MapLayer(map, 1);
    layers.emplace_back(layerOne);
    // MapLayer* layerTwo = new MapLayer(map, 2);
    // layers.emplace_back(layerTwo);
    
    const auto& layers = map.getLayers();
    spdlog::info("Map has {} layers",layers.size());
    for (const auto& layer : layers)
    {
        spdlog::info("Found Layer: "+layer->getName());
        spdlog::info("Layer Type: {}",int(layer->getType()));

        if(layer->getType() == tmx::Layer::Type::Object)
        {
            const auto& objects = layer->getLayerAs<tmx::ObjectGroup>().getObjects();
            spdlog::info("Found {} objects in layer",objects.size());
            for(const auto& object : objects)
            {
                GameObject* obj = new GameObject();
                spdlog::info("Object "+object.getName());
                const auto& properties = object.getProperties();
                spdlog::info("Object has {} properties",properties.size());
                for(const auto& prop : properties)
                {
                    spdlog::info("Found property: "+prop.getName());
                    spdlog::info("Type: {}",int(prop.getType()));
                }
                if(object.getName() == "starting_point"){
                    player.setPosition(object.getPosition().x,object.getPosition().y);
                    player.setSize(object.getAABB().width,object.getAABB().height);
                    m_view.setCenter(object.getPosition().x,object.getPosition().y);
                }
                else{
                    obj->name = object.getName();
                    obj->setAABB(object.getAABB());
                    m_objects.emplace_back(obj);
                }
            }
        }
    }

}

void printAABB(sf::FloatRect aabb){
    spdlog::warn("AABB = ({},{},{},{}",aabb.top,aabb.left,aabb.width,aabb.height);
}

void PlayingState::handleEvent(sf::Event e){
    if(e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::F){
<<<<<<< HEAD
        stateHandler.pushState<PCGState>(stateHandler.game(),"cave2");
=======
        stateHandler.pushState<PCGState>(stateHandler.game(),"cave1");
>>>>>>> d5ada0ec19a4f6a2d2b4eed76974dc8fbb89d330
    }
    for(auto* object : m_objects){
        if(object->intersects(player.getAABB())){
            player.move({0,+11});
            stateHandler.pushState<PCGState>(stateHandler.game(), object->name);
        }
    }
    player.handleEvent(e);
}
void PlayingState::handleInput(){

}
void PlayingState::update(sf::Time deltaTime){
    for(auto layer : layers){
        (*layer).update(deltaTime);
    }
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
    for(auto layer : layers){
        renderer.draw(*layer);
    }
    renderer.draw(player);
    m_pGame->setDefaultView();
}
