//
// Created by Chandler Desforges on 4/30/24.
//

#include "PhysicsModel.h"

PhysicsModel::PhysicsModel(sf::Vector2f scale, sf::Vector2f initialPosition)
: m_scale(scale), m_position(initialPosition), m_velocity({0,0})
{}

const sf::Vector2f& PhysicsModel::getScale() const
{
    return m_scale;
}

const sf::Vector2f& PhysicsModel::getPosition() const
{
    return m_position;
}

const sf::Vector2f& PhysicsModel::getVelocity() const
{
    return m_velocity;
}

void PhysicsModel::setScale(const sf::Vector2f& scale)
{
    m_scale = scale;
}

void PhysicsModel::setPosition(const sf::Vector2f& position)
{
    m_position = position;
}

void PhysicsModel::setVelocity(const sf::Vector2f& velocity)
{
    m_velocity = velocity;
}
