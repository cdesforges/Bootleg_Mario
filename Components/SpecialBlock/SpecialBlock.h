//
// Created by Chandler Desforges on 11/19/24.
//

#ifndef BOOTLEG_MARIO_SPECIALBLOCK_H
#define BOOTLEG_MARIO_SPECIALBLOCK_H


#include "../PhysicsSprite/PhysicsSprite.h"

class SpecialBlock : public PhysicsSprite
{
public:
    explicit SpecialBlock(const sf::Vector2f& initialPosition);
};


#endif //BOOTLEG_MARIO_SPECIALBLOCK_H
