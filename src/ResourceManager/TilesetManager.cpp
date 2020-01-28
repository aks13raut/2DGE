#include "TilesetManager.hpp"

TilesetManager::TilesetManager(){

}

TilesetManager& TilesetManager::get(){
    static TilesetManager tilesetManager;
    return tilesetManager;
}

bool TilesetManager::exists(const std::string& name) const{
    return tilesets.find(name) != tilesets.end();
}

void TilesetManager::addTileset(tmx::Tileset ts){
    if(!exists(ts.getName())){
        tilesets.insert(std::make_pair(ts.getName(), ts));
    }
}

const tmx::Tileset::Tile* TilesetManager::getTile(uint32_t id){
    for(auto ts : tilesets){
        if(ts.second.hasTile(id)){
            return ts.second.getTile(id);
        }
    }
    return NULL;
}