#pragma once

#include <string>
#include "../Graphics/TileArray.hpp"
#include "../ResourceManager/ResourceHolder.hpp"

#define ROCK_CHAR 'M'

typedef enum {
    FLOOR,
    ROCK,
    WALL
}TileType;

class Map{
    public:
    char** cell;
    TileType** tileTypes;
    int rowCount,colCount;
    TileArray tla;

    Map(int x, int y)
    :tla(x,y)
    {
        rowCount = x;
        colCount = y;
        cell = new char*[rowCount];
        tileTypes = new TileType*[rowCount];
        for(int i=0; i < rowCount; i++){
            cell[i] = new char[colCount];
            tileTypes[i] = new TileType[colCount];
        }
        auto& textr = assets.textures.get("overworld");
        for(int i=0; i < rowCount; ++i){
            for(int j=0; j< colCount; ++j){
                tla(i,j).init(textr,i,j,0,0,{16,16},{32,32});
            }  
        }
    }
    Tile& operator()(int x,int y){
        return tla(x,y);
    }
    int value(int i,int j){
        return cell[i][j]==ROCK_CHAR?1:0;
    }
    int calcNeighbourhoodValue(int i,int j){
        if( (i==0 && j==0) || 
            (i==0 && j==colCount-1) ||
            (i==rowCount-1 && j==colCount-1) ||
            (i==rowCount-1 && j==0)  )
        {
            return 7;
        }
        if(i==0 || j==0 || i==rowCount-1 || j==colCount-1){
            return 5;
        }
        return   value(i-1,j-1)  +value(i,j-1) +value(i+1,j-1)
                +value(i-1,j)                  +value(i+1,j)
                +value(i-1,j+1)  +value(i,j+1) +value(i+1,j+1);
    }
};

class ProceduralGenerator {
    public:
    ProceduralGenerator(float r,int n,int T,int M);
    ProceduralGenerator(std::string filename);
    Map* createMap(int seed,int sizeX=10,int sizeY=10);
    private:
    float m_r;
    int m_n,m_T,m_M;
};