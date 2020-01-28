#include "TileArray.hpp"
#include <cassert>

TileArray::TileArray(int X,int Y)
:   size_x(X)
,   size_y(Y)
,   size_total(X*Y)
{
    m_tiles = new Tile[size_total];
}
TileArray::TileArray(int X,int Y,std::vector<tmx::TileLayer::Tile> tiles)
:   size_x(X)
,   size_y(Y)
,   size_total(X*Y)
{
    m_tiles = new Tile[size_total];
    // for(int i=0; i < size_total; ++i){
    // }
}


TileArray::~TileArray()
{
    delete [] m_tiles;
}

Tile& TileArray::operator[](int gid){
    assert(gid >= 0 && gid < size_total);

    return m_tiles[gid];
}

const Tile& TileArray::operator[](int gid) const{
    assert(gid >= 0 && gid < size_total);

    return m_tiles[gid];
}

Tile& TileArray::operator()(int x,int y){
    assert( x >= 0 && x < size_x);
    assert( y >= 0 && y < size_y);
    
    int gid = size_y*x + y;
    return m_tiles[gid];
}

/* const Tile& TileArray::operator()(int x,int y) const{
    assert( x >= 0 && x < size_x);
    assert( y >= 0 && y < size_y);
    
    int gid = size_y*x + y;
    return m_tiles[gid];
} */

void TileArray::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for(int i=0; i < size_total; ++i){
        auto& tile = m_tiles[i];
        target.draw(tile);
    }
}