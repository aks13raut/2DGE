#include "Game.hpp"
#include "PCG/ProceduralGenerator.hpp"

int main()
{   
    ProceduralGenerator pcg("procedural_genration");
    //ProceduralGenerator pcg(50,200,7,2);
    Map *m = pcg.createMap(0,50,50);

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
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
    
        window.clear(sf::Color::Black);
        window.draw(m->tla);
        window.display();
    }
    
    Game game("game/");
    game.run();
}
