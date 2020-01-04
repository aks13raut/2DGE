#pragma once

#include "Tile.hpp"

class TileArray : public sf::Drawable
{
    public:
    TileArray(int X,int Y);
    ~TileArray();
    Tile& operator[](int gid);
    const Tile& operator[](int gid) const;
    Tile& operator()(int x,int y);
    //const Tile& operator()(int x,int y) const;
    private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    Tile*  m_tiles;
    int size_x, size_y;
    int size_total;
};