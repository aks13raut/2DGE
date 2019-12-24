#include "StatePlaying.h"

#include "../GUI/Button.hpp"
#include "../GUI/Textbox.hpp"
#include "../Game.hpp"

#include "spdlog/spdlog.h"

std::string test;

StatePlaying::StatePlaying(Game& game)
:   State   (game)
,   m_TestMenu  (game.getWindow(), 50)
{
    auto b = std::make_unique<gui::Button>();
    b->setText("Button 1");
    b->setFunction([]() {
        spdlog::info("Button 1 clicked!");
    });

    m_TestMenu.addWidget(std::move(b));
}

void StatePlaying::handleEvent(sf::Event e)
{
    m_TestMenu.handleEvent(e, m_pGame->getWindow());
}

void StatePlaying::handleInput()
{

}

void StatePlaying::update(sf::Time deltaTime)
{

}

void StatePlaying::fixedUpdate(sf::Time deltaTime)
{

}

void StatePlaying::render(sf::RenderTarget& renderer)
{
    m_TestMenu.render(renderer);
}
