//
// Created by Chandler Desforges on 11/4/24.
//

#include "SpriteView.h"
#include <iostream>

SpriteView::SpriteView(const PhysicsSpriteType& type, const sf::Vector2f& scale, const sf::Vector2f& initialPosition)
{
    m_texture = &TextureManager::get(type);
    m_characterSprite.setTexture(*m_texture);
    m_characterSprite.setPosition(initialPosition);
    m_characterSprite.setScale(scale);
}

sf::FloatRect SpriteView::getGlobalBounds() const
{
    return m_characterSprite.getGlobalBounds();
}

void SpriteView::setTextureRect(const sf::IntRect& uvRect)
{
    m_characterSprite.setTextureRect(uvRect);
}

void SpriteView::update(const PhysicsModel& model, const sf::Time& dt)
{
    m_characterSprite.setPosition(model.getPosition());
}

void SpriteView::draw(sf::RenderTarget& window, sf::RenderStates state) const
{
    window.draw(m_characterSprite);
}
