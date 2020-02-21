#include "MenuState.hpp"
#include "stateHandler.hpp"

#include "../GUI/Button.hpp"
#include "../GUI/Textbox.hpp"
#include "../Game.hpp"

#include "spdlog/spdlog.h"

#include "PlayingState.hpp"

std::string test;

MenuState::MenuState(Game& game)
:   State(game)
,   m_mainMenu(game.getWindow(), 50)
{
    startBtn = gui::makeButton();
    startBtn->setText("START");
    startBtn->sig.connect([]() {
        spdlog::info("Starting Game...");
        stateHandler.pushState(PLAYING);
    });
    m_mainMenu.addWidget(std::move(startBtn));

    exitBtn = gui::makeButton();
    exitBtn->setText("EXIT");
    exitBtn->sig.connect(&Game::exitGame,&game);
    m_mainMenu.addWidget(std::move(exitBtn));
    
}

void MenuState::handleEvent(sf::Event e)
{
    m_mainMenu.handleEvent(e, m_pGame->getWindow());
}

void MenuState::handleInput()
{

}

void MenuState::update(sf::Time deltaTime)
{

}

void MenuState::fixedUpdate(sf::Time deltaTime)
{

}

void MenuState::render(sf::RenderTarget& renderer)
{
    m_mainMenu.render(renderer);
}
