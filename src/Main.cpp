#include "Game.hpp"
#include "States/MenuState.hpp"
#include "Messaging/System.hpp"

// #include "spdlog/spdlog.h"
// #include "spdlog/sinks/basic_file_sink.h"

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
    System sys(&msgBus);

    Message msg1(MSG_TEST);
    msgBus.sendMessage(msg1);

    msgBus.notify();
    
    Game game("../game/");
//    game.pushState<SplashState>(game);
//    game.pushState<MenuState>(game);
    game.run();
}
