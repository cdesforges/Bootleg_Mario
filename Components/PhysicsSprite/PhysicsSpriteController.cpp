//
// Created by Chandler Desforges on 11/14/24.
//

#include "PhysicsSpriteController.h"

PhysicsSpriteController::PhysicsSpriteController(PhysicsModel& model, SpriteView& view)
: m_model(model), m_view(view)
{}

bool PhysicsSpriteController::isOnObject() const
{
    return m_isOnObject;
}

void PhysicsSpriteController::setPosition(const sf::Vector2f& position)
{
    m_model.setPosition(position);
}

void PhysicsSpriteController::setVelocity(const sf::Vector2f& velocity)
{
    m_model.setVelocity(velocity);
}

void PhysicsSpriteController::collisionReaction(const Collidable& other)
{
    // for readability
    float character_top = m_view.getGlobalBounds().top;
    float character_bottom = m_view.getGlobalBounds().top + m_view.getGlobalBounds().height;
    float character_left = m_view.getGlobalBounds().left;
    float character_right = m_view.getGlobalBounds().left + m_view.getGlobalBounds().width;

    float other_top = other.getGlobalBounds().top;
    float other_bottom = other.getGlobalBounds().top + other.getGlobalBounds().height;
    float other_left = other.getGlobalBounds().left;
    float other_right = other.getGlobalBounds().left + other.getGlobalBounds().width;

    // Top collision
    if (character_top < other_bottom && character_top > other_bottom - m_collisionBuffer
    && character_right > other_left + m_collisionBuffer
    && character_left < other_right - m_collisionBuffer)
    {
        m_model.setPosition({m_model.getPosition().x, other_bottom});
        m_model.setVelocity({m_model.getVelocity().x, 0.f});
        return;
    }

    // Bottom collision
    else if (character_bottom > other_top && character_bottom < other_top + m_collisionBuffer
    && character_right > other_left + m_collisionBuffer
    && character_left < other_right - m_collisionBuffer)
    {
        m_model.setPosition({m_model.getPosition().x, other_top - m_view.getGlobalBounds().height});
        m_model.setVelocity({m_model.getVelocity().x, 0.f});
        m_isOnObject = true;
        return;
    }

    // Left collision
    if (character_left < other_right && character_left > other_right - m_collisionBuffer
    && character_top < other_bottom - m_collisionBuffer
    && character_bottom > other_top + m_collisionBuffer)
    {
        m_model.setPosition({other_right, m_model.getPosition().y});
        m_model.setVelocity({0.f, m_model.getVelocity().y});
        return;
    }

    // Right collision
    else if (character_right > other_left && character_right < other_left + m_collisionBuffer
    && character_top < other_bottom - m_collisionBuffer
    && character_bottom > other_top + m_collisionBuffer)
    {
        m_model.setPosition({other_left - m_view.getGlobalBounds().width, m_model.getPosition().y});
        m_model.setVelocity({0.f, m_model.getVelocity().y});
        return;
    }
}

void PhysicsSpriteController::update(sf::Time& dt)
{
    // update bottomContact
    if(m_model.getVelocity().y != 0)
        m_isOnObject = false;

    // update characters's position
    sf::Vector2f new_position;

    new_position.x = m_model.getPosition().x + m_model.getVelocity().x * dt.asSeconds();
    new_position.y = m_model.getPosition().y + m_model.getVelocity().y * dt.asSeconds();

    m_model.setPosition(new_position);

    // update view based on model
    m_view.update(m_model, dt);
}
