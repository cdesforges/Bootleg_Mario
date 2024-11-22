//
// Created by Chandler Desforges on 11/19/24.
//

#include "Block.h"

Block::Block(const sf::Vector2f& initialPosition)
: PhysicsSprite(BLOCK, initialPosition)
{
    setTextureRect({16,0,16,16});
    m_isStatic = true;
}
