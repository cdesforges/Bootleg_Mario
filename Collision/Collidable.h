//
// Created by Chandler Desforges on 11/15/24.
//

#ifndef SFML_PONG_COLLIDABLE_H
#define SFML_PONG_COLLIDABLE_H

#include <SFML/Graphics.hpp>

class Collidable
{
public:
    virtual sf::FloatRect getGlobalBounds() const = 0;
    virtual void collisionReaction(const Collidable& other) = 0;
    virtual bool isStatic() = 0;
};
#endif //SFML_PONG_COLLIDABLE_H
