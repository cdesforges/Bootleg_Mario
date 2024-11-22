//
// Created by Chandler Desforges on 11/14/24.
//

#ifndef SFML_PONG_BALL_H
#define SFML_PONG_BALL_H

#include "PhysicsModel.h"
#include "SpriteView.h"
#include "PhysicsSpriteController.h"
#include "../Component.h"
#include "../../Collision/Collidable.h"
#include "PhysicsSpriteType.h"
#include "../../KeyboardControls/KeyboardControllable.h"

class PhysicsSprite : public Component, public Collidable
{
protected:
    PhysicsModel m_model;
    SpriteView m_view;
    PhysicsSpriteController m_controller;
    bool m_isStatic;
    bool m_debugText = false;

public:
    explicit PhysicsSprite(const PhysicsSpriteType& type);
    PhysicsSprite(const PhysicsSpriteType& type, const sf::Vector2f& initialPosition);

    // getters
    const sf::Vector2f& getPosition() const;
    const sf::Vector2f& getVelocity() const;
    bool isOnObject() const;

    // setters
    void setPosition(const sf::Vector2f& position);
    void setVelocity(const sf::Vector2f& velocity);
    void setTextureRect(const sf::IntRect& uvRect);

    // functions
    void move(const sf::Vector2f& force, float max_speed);
    void jump();

    // inherited
    bool isStatic() override;
    sf::FloatRect getGlobalBounds() const override;
    void collisionReaction(const Collidable& other) override;
    void update(sf::Time &dt) override;
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
};


#endif //SFML_PONG_BALL_H
