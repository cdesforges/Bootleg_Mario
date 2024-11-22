//
// Created by Chandler Desforges on 11/14/24.
//

#include "Platform.h"

Platform::Platform()
: Platform({10, 100}, {0, 0})
{}

Platform::Platform(sf::Vector2f size, sf::Vector2f initialPosition)
: m_model(size, initialPosition), m_view(size, initialPosition), m_controller(m_model, m_view)
{}

sf::FloatRect Platform::getGlobalBounds() const
{
    return m_view.getGlobalBounds();
}

void Platform::setControls(const PlayerControls& controls)
{
    m_controller.setControls(controls);
}

void Platform::setPosition(const sf::Vector2f& position)
{
    m_model.setPosition(position);
}

bool Platform::isStatic()
{
    return true;
}

void Platform::collisionReaction(const Collidable& other)
{
    // do nothing
}

void Platform::update(sf::Time& dt)
{
    m_controller.update(dt);
}

void Platform::draw(sf::RenderTarget& window, sf::RenderStates state) const
{
    window.draw(m_view);
}
