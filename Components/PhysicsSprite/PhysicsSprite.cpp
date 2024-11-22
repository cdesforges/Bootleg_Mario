//
// Created by Chandler Desforges on 11/14/24.
//

#include "PhysicsSprite.h"

PhysicsSprite::PhysicsSprite(const PhysicsSpriteType& type)
: PhysicsSprite(type, {0, 0})
{}

PhysicsSprite::PhysicsSprite(const PhysicsSpriteType& type, const sf::Vector2f& initialPosition)
: m_model({1,1}, initialPosition), m_view(type, {1,1}, initialPosition), m_controller(m_model, m_view)
{
    if(type == BACKGROUND)
        m_isStatic = true;
    else
        m_isStatic = false;
}

const sf::Vector2f& PhysicsSprite::getPosition() const
{
    return m_model.getPosition();
}

const sf::Vector2f& PhysicsSprite::getVelocity() const
{
    return m_model.getVelocity();
}

bool PhysicsSprite::isOnObject() const
{
    return m_controller.isOnObject();
}

void PhysicsSprite::setPosition(const sf::Vector2f& position)
{
    m_controller.setPosition(position);
}

void PhysicsSprite::setVelocity(const sf::Vector2f& velocity)
{
    m_controller.setVelocity(velocity);
}

void PhysicsSprite::setTextureRect(const sf::IntRect& uvRect)
{
    m_view.setTextureRect(uvRect);
}

void PhysicsSprite::move(const sf::Vector2f& force, float maxSpeed)
{
    if(force.x > 0 && m_model.getVelocity().x < maxSpeed)
        m_model.setVelocity({m_model.getVelocity().x + force.x, m_model.getVelocity().y});
    if(force.x < 0 && m_model.getVelocity().x > -maxSpeed)
        m_model.setVelocity({m_model.getVelocity().x + force.x, m_model.getVelocity().y});
}

void PhysicsSprite::jump()
{
    m_controller.setVelocity({m_model.getVelocity().x, -400.f});
}

bool PhysicsSprite::isStatic()
{
    return m_isStatic;
}

sf::FloatRect PhysicsSprite::getGlobalBounds() const
{
    return m_view.getGlobalBounds();
}

void PhysicsSprite::collisionReaction(const Collidable& other)
{
    if(!m_isStatic)
        m_controller.collisionReaction(other);
}

void PhysicsSprite::update(sf::Time& dt)
{
    // update model
    m_controller.update(dt);

    if(m_debugText)
        std::cout << "Position = {" << m_model.getPosition().x << ", " << m_model.getPosition().y << "}\n";
}

void PhysicsSprite::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(m_view);
}
