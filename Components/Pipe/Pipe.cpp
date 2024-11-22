//
// Created by Chandler Desforges on 11/20/24.
//

#include "Pipe.h"

Pipe::Pipe(const sf::Vector2f& initialPosition)
: PhysicsSprite(PIPE, initialPosition)
{
    setTextureRect({0, 128, 32, 32});
    m_isStatic = true;
}
