#pragma once

#include <string>
#include "../Graphics/TileArray.hpp"
#include "../ResourceManager/ResourceHolder.hpp"

#include <iostream>

#include "spdlog/spdlog.h"

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
    }
    Tile& operator()(int x,int y){
        return tla(x,y);
    }
    int value(int i,int j){
        return cell[i][j]==ROCK_CHAR?1:0;
    }
    int calcNeighbourhoodValue(int x,int y,int t){
        int m = x-t/2;
        int n = y-t/2;
        int sum = 0;
        for(int i=0;i<t;++i,++m){
            for(int j=0;j<t;++j,++n){
                if((m >= 0 && m < rowCount) && n >= 0 && n < colCount){
                    sum += value(m,n);
                }
                else{
                    sum += 1;
                }
            }
        }
        return sum;
    }
    sf::Vector2f getRandomFloor(){
        float i=0,j=0;
        for(int f=0;f<10;f++){
            i = rand()%rowCount;
            j = rand()%colCount;
            spdlog::info("({},{})={}",i,j,value(i,j));
            if(value(i,j)==0)
                break;
        }
        return {i*16,j*16};
    }
};

class ProceduralGenerator {
    public:
    ProceduralGenerator(float r,int n,int T,int M);
    ProceduralGenerator(std::string filename);
    Map* createMap(int seed,int sizeX=10,int sizeY=10);
    Map* createMap(std::string filename);
    private:
    float m_r;
    int m_n,m_T,m_M;
    int m_t;
    int **neighborhood;
};