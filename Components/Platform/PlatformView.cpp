//
// Created by Chandler Desforges on 11/14/24.
//

#include "PlatformView.h"

PlatformView::PlatformView(const sf::Vector2f& size, const sf::Vector2f& position)
: m_paddleShape(size)
{
    // set origin to the center
    m_paddleShape.setOrigin({m_paddleShape.getSize().x / 2, m_paddleShape.getSize().y / 2});
    m_paddleShape.setPosition(position);
    m_paddleShape.setFillColor(sf::Color::White);

    if(m_debugMode)
    {
        std::cout << "Size = {" << size.x << ", " << size.y << "}\n";
        std::cout << "Position = {" << position.x << ", " << position.y << "}\n";
        std::cout << "Origin = {" << m_paddleShape.getOrigin().x << ", " << m_paddleShape.getOrigin().y << "}\n";
        m_debugOrigin.setSize({5, 5});
        m_debugOrigin.setOrigin({m_debugOrigin.getSize().x / 2, m_debugOrigin.getSize().x / 2});
        m_debugOrigin.setFillColor(sf::Color::Red);
        m_debugOrigin.setPosition(m_paddleShape.getPosition());
    }
}

sf::FloatRect PlatformView::getGlobalBounds() const
{
    return m_paddleShape.getGlobalBounds();
}

void PlatformView::update(const PlatformModel& model)
{
    m_paddleShape.setPosition(model.getPosition());

    if(m_debugMode)
        m_debugOrigin.setPosition(model.getPosition());
}

void PlatformView::draw(sf::RenderTarget& window, sf::RenderStates state) const
{
    window.draw(m_paddleShape);

    if(m_debugMode)
        window.draw(m_debugOrigin);
}
