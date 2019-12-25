#pragma once

#include <SFML/Graphics.hpp>

#include "Util/NonCopyable.hpp"
#include "Util/NonMoveable.hpp"
#include "States/StateMachine.hpp"
#include "Util/FPSCounter.hpp"
#include "ResourceManager/ResourceHolder.hpp"

static ResourceHolder& assets = ResourceHolder::get();

/**
    Main controlling class of the game.
    Handles state switches and the main loop, as well
    as counting the FPS
*/
class Game : public NonCopyable, public NonMovable
{
    public:
        Game();

        void run();
        void exitGame();
        const sf::RenderWindow& getWindow() const;

        StateMachine* m_pSM;

    private:
        void handleEvent();

        sf::RenderWindow m_window;
        StateMachine m_stateMachine;

        FPSCounter m_fpsCounter;

};
