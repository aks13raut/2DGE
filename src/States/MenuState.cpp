#include "MenuState.hpp"

#include "../GUI/Button.hpp"
#include "../GUI/Textbox.hpp"
#include "../Game.hpp"

#include "spdlog/spdlog.h"

std::string test;

MenuState::MenuState(Game& game)
:   State(game)
,   m_mainMenu(game.getWindow(), 50)
{
    startBtn = gui::makeButton();
    startBtn->setText("START");
    startBtn->setFunction([]() {
        spdlog::info("Starting Game...");
    });
    m_mainMenu.addWidget(std::move(startBtn));

    exitBtn = gui::makeButton();
    exitBtn->setText("EXIT");
    exitBtn->setFunction([]() {
        spdlog::info("Bye!");
    });
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
