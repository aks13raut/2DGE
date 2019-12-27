#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include "Util/NonCopyable.hpp"
#include "Util/NonMoveable.hpp"
#include "States/StateMachine.hpp"
#include "Util/FPSCounter.hpp"
#include "ResourceManager/ResourceHolder.hpp"
#include "Wrapers/YamlConfig.hpp"
#include "Messaging/Messager.hpp"

static ResourceHolder& assets = ResourceHolder::get();

/**
    Main controlling class of the game.
    Handles state switches and the main loop, as well
    as counting the FPS
*/
class Game : public Messager, public NonCopyable, public NonMovable
{
    public:
        Game(std::string path);

        void run();
        void exitGame();
        void handleMessage(Message msg) override;
        const sf::RenderWindow& getWindow() const;

        StateMachine* m_pSM;

    private:
        void handleEvent();

        std::string path_to_game;

        YAML::Node  m_config;

        sf::RenderWindow m_window;
        MessageBus       messageBus;
        StateMachine     m_stateMachine;

        FPSCounter      m_fpsCounter;

};
