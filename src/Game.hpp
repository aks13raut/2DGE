#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Util/NonCopyable.hpp"
#include "Util/NonMoveable.hpp"
#include "States/StateMachine.hpp"
#include "Util/FPSCounter.hpp"
#include "ResourceManager/ResourceHolder.hpp"
#include "Wrapers/YamlConfig.hpp"

/**
    Main controlling class of the game.
    Handles state switches and the main loop, as well
    as counting the FPS
*/
class Game : public NonCopyable, public NonMovable
{
    public:
        Game(std::string path);

        void run();
        void exitGame();
        const sf::RenderWindow& getWindow() const;
        void setView(const sf::View view);
        void setDefaultView();
        void serGameDir(std::string path);

        StateMachine* m_pSM;

    private:
        void handleEvent();

        unsigned int  TPS = 30; //ticks per seconds

        std::string m_gameDir;

        YAML::Node  m_config;

        sf::RenderWindow m_window;

        StateMachine m_stateMachine;

        FPSCounter m_fpsCounter;
};