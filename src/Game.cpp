#include "Game.hpp"

#include "States/SplashState.hpp"

#include <iostream>

Game::Game()
:   m_window    ({1280, 720}, "Title Here")
,   m_stateMachine(*this)
,   m_pSM(&m_stateMachine)
{
    m_window.setPosition({m_window.getPosition().x, 0});
    m_window.setFramerateLimit(60);
    m_stateMachine.pushState<SplashState>(*this);
}

//Runs the main loop
void Game::run()
{
    constexpr unsigned TPS = 30; //ticks per seconds
    const sf::Time     timePerUpdate = sf::seconds(1.0f / float(TPS));
    unsigned ticks = 0;

    sf::Clock timer;
    auto lastTime = sf::Time::Zero;
    auto lag      = sf::Time::Zero;

    //Main loop of the game
    while (m_window.isOpen() && !m_stateMachine.isEmpty()) {
        auto& state = m_stateMachine.getCurrentState();

        //Get times
        auto time = timer.getElapsedTime();
        auto elapsed = time - lastTime;
        lastTime = time;
        lag += elapsed;

        //Real time update
        m_stateMachine.update(elapsed);
        m_fpsCounter.update();

        //Fixed time update
        while (lag >= timePerUpdate)
        {
            ticks++;
            lag -= timePerUpdate;
            m_stateMachine.fixedUpdate(elapsed);
        }

        //Render
        m_window.clear();

        m_stateMachine.render(m_window);
        m_fpsCounter.draw(m_window);

        m_window.display();

        //Handle window events
        handleEvent();
        m_stateMachine.tryPop();
    }
}

//Handles window events, called every frame
void Game::handleEvent()
{
    sf::Event e;

    while (m_window.pollEvent(e)) {
        m_stateMachine.handleEvent(e);
        switch (e.type) {
            case sf::Event::Closed:
                m_window.close();
                break;

            default:
                break;

        }
    }
}


void Game::exitGame()
{
    m_window.close();
}

const sf::RenderWindow& Game::getWindow() const
{
    return m_window;
}
