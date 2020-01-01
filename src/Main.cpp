#include "Game.hpp"
#include "States/MenuState.hpp"
#include "Messaging/Messager.hpp"

// #include "spdlog/spdlog.h"
// #include "spdlog/sinks/basic_file_sink.h"
#include <tmxlite/Map.hpp>
#include <tmxlite/Layer.hpp>
#include "Graphics/OrthoLayer.hpp"

int main()
{
/*     spdlog::info("Sample Info output.");
    spdlog::warn("Sample Warn output.");
    spdlog::error("Sample Error output.");

    auto filelog = spdlog::basic_logger_mt("sample-logger", "sample-log.txt");

    filelog.get()->info("Sample Info output.");
    filelog.get()->warn("Sample Warn output.");
    filelog.get()->error("Sample Error output."); */

    MessageBus msgBus;
    Messager sys(&msgBus);

    Message msg1(MSG_TEST);
    msgBus.sendMessage(msg1);

    msgBus.notify();

    /* sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    tmx::Map map;
    map.load("res/tilemaps/map1.tmx");
    
    MapLayer layerZero(map, 0);
    MapLayer layerOne(map, 1);

    sf::Clock globalClock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time duration = globalClock.getElapsedTime();
        layerZero.update(duration);

        window.clear(sf::Color::Black);
        window.draw(layerZero);
        window.draw(layerOne);
        window.display();
    } */
    
    Game game("../game/");
//    game.pushState<SplashState>(game);
//    game.pushState<MenuState>(game);
    game.run();
}
