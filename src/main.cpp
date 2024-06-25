#include <SFML/Graphics.hpp>
#include "marie.h"

int main()
{
    // "Unelmia" is probably a placeholder name, but I like it
    auto window = sf::RenderWindow{ { 640u, 480u }, "Unelmia" };
    window.setFramerateLimit(144);

    Player* marie = new Player(0, 100, 100);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();

        // main game loop
        marie->Update();
        window.draw(marie->sprite);

        window.display();
    }
}
