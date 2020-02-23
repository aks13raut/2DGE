#pragma once

#include "State.hpp"
#include "../GameLogic/GameObject.hpp"
#include "../Graphics/TileArray.hpp"
#include "../PCG/ProceduralGenerator.hpp"
#include <string>

/**
    Game state for the main part of the game
*/
class PCGState : public State
{
     public:
        PCGState(Game& game,std::string filename);

        void handleEvent    (sf::Event e)                   override;
        void handleInput    ()                              override;
        void update         (sf::Time deltaTime)            override;
        void fixedUpdate    (sf::Time deltaTime)            override;
        void render         (sf::RenderTarget& renderer)    override;

    private:
        sf::View m_view;
        GameObject player;
        sf::Clock m_clock;
        ProceduralGenerator* pcg;
        Map *map;
};
