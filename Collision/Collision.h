//
// Created by Chandler Desforges on 11/5/24.
//

#ifndef SFML_PONG_COLLISION_H
#define SFML_PONG_COLLISION_H


#include <vector>
#include "Collidable.h"

class Collision
{
private:
    static bool checkForCollision(const Collidable* a, const Collidable* b);
public:
    static void resolveCollisions(std::vector<Collidable*> objects);
};


#endif //SFML_PONG_COLLISION_H
