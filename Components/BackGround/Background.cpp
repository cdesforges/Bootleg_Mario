//
// Created by Chandler Desforges on 11/19/24.
//

#include "Background.h"

Background::Background()
: m_background(BACKGROUND)
{
    m_background.setTextureRect({0,0,3376,240});
}

bool Background::isStatic()
{
    return true;
}

sf::FloatRect Background::getGlobalBounds() const
{
    sf::FloatRect global_bounds;

    global_bounds.left = m_background.getGlobalBounds().left;
    global_bounds.width = m_background.getGlobalBounds().width;
    global_bounds.top = m_background.getGlobalBounds().top + m_background.getGlobalBounds().height - 32;
    global_bounds.height = 16;

    return global_bounds;
}

void Background::collisionReaction(const Collidable& other)
{
    // do nothing!
}

void Background::update(sf::Time& dt)
{
    m_background.update(dt);
}

void Background::draw(sf::RenderTarget& window, sf::RenderStates state) const
{
    window.draw(m_background);
}
