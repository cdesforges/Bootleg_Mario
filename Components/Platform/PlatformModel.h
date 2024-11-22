//
// Created by Chandler Desforges on 4/29/24.
//

#ifndef SFML_PONG_PLATFORMMODEL_H
#define SFML_PONG_PLATFORMMODEL_H

#include <iostream>
#include <SFML/Graphics.hpp>

class PlatformModel
{
protected:
    sf::Vector2f m_size;
    sf::Vector2f m_position;
    sf::Vector2f m_velocity;

public:
    explicit PlatformModel(sf::Vector2f size, sf::Vector2f initialPosition);

    // getters
    const sf::Vector2f& getSize() const;
    const sf::Vector2f& getPosition() const;
    const sf::Vector2f& getVelocity() const;

    // setters
    void setSize(const sf::Vector2f& size);
    void setPosition(const sf::Vector2f& position);
    void setVelocity(const sf::Vector2f& velocity);
};

#endif //SFML_PONG_PLATFORMMODEL_H
