#include "Game.hpp"

#include "States/stateHandler.hpp"
#include "States/SplashState.hpp"
#include "States/MenuState.hpp"

#include "spdlog/spdlog.h"


Game::Game(std::string path)
:   m_gameDir(path)
,   m_config(loadYamlFile(path,"game"))
,   m_stateMachine(*this)
,   m_pSM(&m_stateMachine)
{
    //config
    int window_width = m_config["width"].as<int>();
	int window_height = m_config["height"].as<int>();
    auto title = m_config["title"].as<std::string>();
    auto frame_limit = m_config["frame_rate_limit"].as<int>();
    TPS = m_config["ticks_per_sec"].as<unsigned int>();

    m_window.create(sf::VideoMode(window_width, window_height),title);
    m_window.setFramerateLimit(frame_limit);
    m_window.setVerticalSyncEnabled(true); 

    stateHandler.setStateMachinePtr(m_pSM);
    stateHandler.setGamePtr(this);
    stateHandler.pushState(SPLASH);
    //m_stateMachine.pushState<SplashState>(*this);
}

//Runs the main loop
void Game::run()
{

    //init
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
                exitGame();
                break;

            default:
                break;

        }
    }
}

void Game::exitGame()
{
    spdlog::info("Closing game...");
    m_window.close();
}

const sf::RenderWindow& Game::getWindow() const
{
    return m_window;
}

void Game::setView(const sf::View view){
    m_window.setView(view);
}

void Game::setDefaultView(){
    m_window.setView(m_window.getDefaultView());
}

 void Game::serGameDir(std::string path){
     m_gameDir = path;
 }