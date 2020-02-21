/**
 * @file State.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-02-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once

#include <SFML/Graphics.hpp>

#include "../Util/NonCopyable.hpp"

class Game;

class State : public NonCopyable
{
public:
    State(Game& game)
        : m_pGame(&game)
    {}
    virtual ~State() = default;
    
    virtual void handleInput() = 0;
    virtual void handleEvent(sf::Event e) {}

    virtual void update(sf::Time deltaTime) {}
    virtual void fixedUpdate(sf::Time deltaTime) {}

    virtual void render(sf::RenderTarget& renderer) = 0;

    virtual void pause(){}
    virtual void resume(){}

protected:
    Game* m_pGame;
};
