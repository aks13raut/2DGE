#pragma once

#include "State.hpp"
#include "../GUI/ProgressBar.hpp"

/**
    Game state for Splash screen or Loading screen
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
        gui::ProgressBar m_loadingBar;
        sf::Clock m_clock;
};
