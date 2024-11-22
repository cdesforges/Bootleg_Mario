//
// Created by Chandler Desforges on 4/30/24.
//

#ifndef SFML_PONG_BALLMODEL_H
#define SFML_PONG_BALLMODEL_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class PhysicsModel
{
private:
    sf::Vector2f m_scale;
    sf::Vector2f m_position;
    sf::Vector2f m_velocity;

public:
    explicit PhysicsModel(sf::Vector2f scale, sf::Vector2f initialPosition);

    // getters
    const sf::Vector2f& getScale() const;
    const sf::Vector2f& getPosition() const;
    const sf::Vector2f& getVelocity() const;

    // setters
    void setScale(const sf::Vector2f& scale);
    void setPosition(const sf::Vector2f& position);
    void setVelocity(const sf::Vector2f& velocity);
};


#endif //SFML_PONG_BALLMODEL_H
