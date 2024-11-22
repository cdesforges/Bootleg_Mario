//
// Created by Chandler Desforges on 11/19/24.
//

#ifndef BOOTLEG_MARIO_KEYBOARDCONTROLLABLE_H
#define BOOTLEG_MARIO_KEYBOARDCONTROLLABLE_H


#include <SFML/Window/Event.hpp>

class KeyboardControllable
{
public:
    virtual void eventHandler(const sf::Event& event) = 0;
};


#endif //BOOTLEG_MARIO_KEYBOARDCONTROLLABLE_H
