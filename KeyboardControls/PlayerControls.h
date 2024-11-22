//
// Created by Chandler Desforges on 11/14/24.
//

#ifndef SFML_PONG_PLAYERCONTROLS_H
#define SFML_PONG_PLAYERCONTROLS_H

#include <SFML/Window/Keyboard.hpp>

struct PlayerControls
{
    sf::Keyboard::Key up = sf::Keyboard::Unknown;
    sf::Keyboard::Key down = sf::Keyboard::Unknown;
    sf::Keyboard::Key left = sf::Keyboard::Unknown;
    sf::Keyboard::Key right = sf::Keyboard::Unknown;
    sf::Keyboard::Key jump = sf::Keyboard::Unknown;

    sf::Keyboard::Key quit = sf::Keyboard::Escape;
};
#endif //SFML_PONG_PLAYERCONTROLS_H
