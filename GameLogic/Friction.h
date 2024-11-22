//
// Created by Chandler Desforges on 11/20/24.
//

#ifndef BOOTLEG_MARIO_FRICTION_H
#define BOOTLEG_MARIO_FRICTION_H

#include "Force.h"

class Friction : public Force
{
public:
    static void apply(PhysicsSprite& physicsSprite, const sf::Time& dt)
    {
        i_isResistive = true;
        i_acceleration = {-500.f, 0.f};
        Force::apply(physicsSprite, dt);
    }
};


#endif //BOOTLEG_MARIO_FRICTION_H
