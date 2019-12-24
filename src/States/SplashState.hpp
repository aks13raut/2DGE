#pragma once

#include "State.hpp"

/**
    Game state for the main part of the game
*/
class SplashState : public State
{
     public:
        SplashState(Game& game);

        void handleEvent    (sf::Event e)                   override;
        void handleInput    ()                              override;
        void update         (sf::Time deltaTime)            override;
        void fixedUpdate    (sf::Time deltaTime)            override;
        void render         (sf::RenderTarget& renderer)    override;

    private:
        sf::Sprite m_logo;
        sf::Sprite m_background;
        sf::Clock m_clock;
};
