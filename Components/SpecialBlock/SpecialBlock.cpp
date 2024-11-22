//
// Created by Chandler Desforges on 11/19/24.
//

#include "SpecialBlock.h"

SpecialBlock::SpecialBlock(const sf::Vector2f& initialPosition)
: PhysicsSprite(SPECIAL_BLOCK, initialPosition)
{
    setTextureRect({368,0,16,16});
    m_isStatic = true;
}
