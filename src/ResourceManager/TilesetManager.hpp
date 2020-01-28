#pragma once

#include <unordered_map>
#include <tmxlite/Tileset.hpp>

class TilesetManager
{
    public:
        static TilesetManager& get();
        bool exists(const std::string& name) const;
        void addTileset(tmx::Tileset ts);
        const tmx::Tileset::Tile* getTile(uint32_t id);
    private:
        TilesetManager();
        std::unordered_map<std::string,tmx::Tileset> tilesets;
};

static TilesetManager& tsManager = TilesetManager::get();