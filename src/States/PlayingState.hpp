#pragma once

#include "State.hpp"
#include "../GameObject.hpp"

/**
    Game state for the main part of the game
*/
class PlayingState : public State
{
     public:
        PlayingState(Game& game);

        void handleEvent    (sf::Event e)                   override;
        void handleInput    ()                              override;
        void update         (sf::Time deltaTime)            override;
        void fixedUpdate    (sf::Time deltaTime)            override;
        void render         (sf::RenderTarget& renderer)    override;

    private:
        sf::Sprite m_background;
        GameObject player;
        sf::Clock m_clock;
};