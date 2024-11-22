//
// Created by Chandler Desforges on 11/19/24.
//

#ifndef BOOTLEG_MARIO_BLOCK_H
#define BOOTLEG_MARIO_BLOCK_H


#include "../PhysicsSprite/PhysicsSprite.h"

class Block : public PhysicsSprite
{
public:
    explicit Block(const sf::Vector2f& initialPosition);
};


#endif //BOOTLEG_MARIO_SPECIALBLOCK_H
