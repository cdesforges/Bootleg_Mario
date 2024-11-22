//
// Created by Chandler Desforges on 11/15/24.
//

#ifndef SFML_PONG_WALL_H
#define SFML_PONG_WALL_H


#include "../Platform/Platform.h"

class Wall : public Platform
{
public:
    Wall(const sf::Vector2f& size, const sf::Vector2f& initialPosition) : Platform(size, initialPosition){};
};


#endif //SFML_PONG_WALL_H
