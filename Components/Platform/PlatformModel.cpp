//
// Created by Chandler Desforges on 4/29/24.
//

#include "PlatformModel.h"

PlatformModel::PlatformModel(sf::Vector2f size, sf::Vector2f initialPosition)
: m_size(size), m_position(initialPosition), m_velocity({0,0})
{}

const sf::Vector2f& PlatformModel::getSize() const
{
    return m_size;
}

const sf::Vector2f& PlatformModel::getPosition() const
{
    return m_position;
}

const sf::Vector2f& PlatformModel::getVelocity() const
{
    return m_velocity;
}

void PlatformModel::setSize(const sf::Vector2f& size)
{
    m_size = size;
}

void PlatformModel::setPosition(const sf::Vector2f& position)
{
    m_position = position;
}

void PlatformModel::setVelocity(const sf::Vector2f& velocity)
{
    m_velocity = velocity;
}
