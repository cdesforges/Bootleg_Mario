//
// Created by Chandler Desforges on 11/14/24.
//

#ifndef SFML_PONG_BALLCONTROLLER_H
#define SFML_PONG_BALLCONTROLLER_H


#include "PhysicsModel.h"
#include "SpriteView.h"
#include "../../Collision/Collidable.h"
#include "../Wall/Wall.h"
#include <iostream>
#include "../Platform/Platform.h"

class PhysicsSpriteController
{
private:
    PhysicsModel& m_model;
    SpriteView& m_view;
    float m_collisionBuffer = 2.f;
    bool m_isOnObject;

public:
    PhysicsSpriteController(PhysicsModel& model, SpriteView& view);

    // getters
    bool isOnObject() const;

    // setters
    void setPosition(const sf::Vector2f& position);
    void setVelocity(const sf::Vector2f& velocity);

    // fns
    void collisionReaction(const Collidable& other);
    void update(sf::Time& dt);
};


#endif //SFML_PONG_BALLCONTROLLER_H
