//
// Created by Chandler Desforges on 11/14/24.
//

#ifndef SFML_PONG_PLATFORMVIEW_H
#define SFML_PONG_PLATFORMVIEW_H


#include <SFML/Graphics.hpp>
#include "../Component.h"
#include "PlatformModel.h"

class PlatformView : public sf::Drawable
{
protected:
    sf::RectangleShape m_paddleShape;
    sf::RectangleShape m_debugOrigin;
    bool m_debugMode = false;

public:
    PlatformView(const sf::Vector2f& size, const sf::Vector2f& position);

    // getters
    sf::FloatRect getGlobalBounds() const;

    void update(const PlatformModel& model);

    void draw(sf::RenderTarget& window, sf::RenderStates state) const override;
};


#endif //SFML_PONG_PLATFORMVIEW_H
