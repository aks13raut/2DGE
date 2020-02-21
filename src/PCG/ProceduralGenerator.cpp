#include "ProceduralGenerator.hpp"
#include <iostream>
#include <iomanip>

#include "yaml-cpp/yaml.h"

ProceduralGenerator::ProceduralGenerator(float r,int n,int T,int M)
:m_r(r)
,m_n(n)
,m_T(T)
,m_M(M)
{
    
}

ProceduralGenerator::ProceduralGenerator(std::string filename)
{
    std::string path = "game/config/"+filename+".yaml";
	YAML::Node config = YAML::LoadFile(path);
    m_r = config["percent_of_initial_rocks"].as<int>();
    m_n = config["no_of_iterations"].as<int>();
    m_T = config["threshold"].as<int>();
    m_M = config["moore_neighboorhood_size"].as<int>();
}

void printMap(Map *m){
    for(int i=0; i < m->rowCount; i++){
        for(int j=0; j < m->colCount ; j++) {
            std::cout << std::setw(1) << m->cell[i][j];
        }
        std::cout << "\n";
    }
}

void setTiles(Map* m){
    auto& textr = assets.textures.get("overworld");
    for(int i=0; i < m->rowCount; i++){
        for(int j=0; j < m->colCount ; j++) {
            switch (m->tileTypes[i][j])
            {
            case FLOOR:
                (*m)(i,j).init(textr,i,j,1,1,{16,16},{32,32});
                break;
            case ROCK:
                (*m)(i,j).init(textr,i,j,1,4,{16,16},{32,32});
                break;
            default:
                (*m)(i,j).init(textr,i,j,7,3,{16,16},{32,32});
                break;
            }
            
        }
    }
}

Map* ProceduralGenerator::createMap(int seed,int sizeX,int sizeY)
{
    Map *map = new Map(sizeX,sizeY);
    
    int count = m_r*(sizeX*sizeY)/100.0;
    
    for(int i=0; i < map->rowCount; i++){
        for(int j=0; j < map->colCount ; j++) {
            if(count && rand()%2 == 0){
                count--;
                map->cell[i][j] = ROCK_CHAR;
                map->tileTypes[i][j] = ROCK;
            }
            else{        
                map->cell[i][j] = ' ';
                map->tileTypes[i][j] = FLOOR;
            }
        }
    }
    printMap(map);
    setTiles(map);
    
    for(auto c = 0; c < m_n; c++){
        for(int i=0; i < map->rowCount; i++){
            for(int j=0; j < map->colCount ; j++) {
                if(map->calcNeighbourhoodValue(i,j) > m_T)
                    map->cell[i][j] = ROCK_CHAR;
                else map->cell[i][j] = ' ';
            }
        }
    }
    printMap(map);
    setTiles(map);
    
    return map;
}