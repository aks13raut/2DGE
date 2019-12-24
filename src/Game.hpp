#pragma once

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

#include "States/State.hpp"
#include "Util/NonMoveable.hpp"
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

        template<typename T, typename... Args>
        void pushState(Args&&... args);
        void pushState(std::unique_ptr<State> state);
        void popState();
        void exitGame();
        template<typename T, typename... Args>
        void changeState(Args&&... args);

        const sf::RenderWindow& getWindow() const;

    private:
        void handleEvent();
        void tryPop();

        State& getCurrentState();

        sf::RenderWindow m_window;
        std::vector<std::unique_ptr<State>> m_states;

        FPSCounter counter;

        bool m_shouldPop = false;
        bool m_shouldExit = false;
        bool m_shouldChageState = false;
        std::unique_ptr<State> m_change;

};

template<typename T, typename... Args>
inline void Game::pushState(Args&&... args)
{
    pushState(std::make_unique<T>(std::forward<Args>(args)...));
}

template<typename T, typename ...Args>
inline void Game::changeState(Args && ...args)
{
    m_change = std::make_unique<T>(std::forward<Args>(args)...);
    m_shouldPop = true;
    m_shouldChageState = true;
}
