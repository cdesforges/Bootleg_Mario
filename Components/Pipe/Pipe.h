//
// Created by Chandler Desforges on 11/20/24.
//

#ifndef BOOTLEG_MARIO_PIPE_H
#define BOOTLEG_MARIO_PIPE_H


#include "../PhysicsSprite/PhysicsSprite.h"

class Pipe : public PhysicsSprite
{
public:
    explicit Pipe(const sf::Vector2f& initialPosition);
};


#endif //BOOTLEG_MARIO_PIPE_H
