//
// Created by Chandler Desforges on 11/20/24.
//

#ifndef BOOTLEG_MARIO_FORCE_H
#define BOOTLEG_MARIO_FORCE_H


#include <SFML/System/Vector2.hpp>
#include "../Components/PhysicsSprite/PhysicsSprite.h"

class PhysicsSprite;

class Force
{
protected:
    inline static sf::Vector2f i_acceleration;
    inline static bool i_isEnabled = true;
    inline static bool i_isResistive;
    inline static float i_buffer = 1;

public:
    static void apply(PhysicsSprite& physicsSprite, const sf::Time& dt);
    void toggle(bool isOn);
};


#endif //BOOTLEG_MARIO_FORCE_H
