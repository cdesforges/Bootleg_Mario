//
// Created by Chandler Desforges on 11/5/24.
//

#include "Collision.h"
#include <iostream>

bool Collision::checkForCollision(const Collidable* a, const Collidable* b)
{
    if(!a || !b)
        return false;

    return a->getGlobalBounds().intersects(b->getGlobalBounds());
}

void Collision::resolveCollisions(std::vector<Collidable*> objects)
{
    // no collision to resolve if less than 2 objects
    if(objects.size() < 2)
        return;

    for(size_t i = 0; i < objects.size() - 1; i++)
        for(size_t j = i + 1; j < objects.size(); j++)
        {
            if(objects[i]->isStatic() && objects[j]->isStatic())
                continue;

            if (checkForCollision(objects[i], objects[j]))
            {
                objects[i]->collisionReaction(*objects[j]);
                objects[j]->collisionReaction(*objects[i]);
            }
        }
}
