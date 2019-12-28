#pragma once


#include "State.hpp"
#include "../GUI/StackMenu.hpp"
#include "../GUI/Button.hpp"

/**
    Game state for the main part of the game
*/
class MenuState : public State
{
    public:
        MenuState(Game& game);

        void handleEvent    (sf::Event e)                   override;
        void handleInput    ()                              override;
        void update         (sf::Time deltaTime)            override;
        void fixedUpdate    (sf::Time deltaTime)            override;
        void render         (sf::RenderTarget& renderer)    override;

    private:
        gui::StackMenu m_mainMenu;
        std::unique_ptr<gui::Button> startBtn;
        std::unique_ptr<gui::Button> exitBtn;
};
