//
// Created by Chandler Desforges on 11/15/24.
//

#ifndef BOOTLEG_MARIO_GRAVITY_H
#define BOOTLEG_MARIO_GRAVITY_H

#include "Force.h"

class Gravity : public Force
{
public:
    static void apply(PhysicsSprite& physicsSprite, const sf::Time& dt)
    {
        i_isResistive = false;
        i_acceleration = {0.f, 1000.f};
        Force::apply(physicsSprite, dt);
    }
};


#endif //BOOTLEG_MARIO_GRAVITY_H
