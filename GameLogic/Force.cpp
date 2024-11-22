//
// Created by Chandler Desforges on 11/20/24.
//

#include "Force.h"

void Force::apply(PhysicsSprite& physicsSprite, const sf::Time& dt)
{
    if(!i_isEnabled)
        return;

    sf::Vector2f new_velocity = physicsSprite.getVelocity();

    if(i_isResistive)
    {
        if (physicsSprite.getVelocity().x > 0)
            new_velocity.x += i_acceleration.x * dt.asSeconds();
        else if (physicsSprite.getVelocity().x < 0)
            new_velocity.x -= i_acceleration.x * dt.asSeconds();

        if (physicsSprite.getVelocity().y > 0)
            new_velocity.y += i_acceleration.y * dt.asSeconds();
        else if (physicsSprite.getVelocity().y < 0)
            new_velocity.y -= i_acceleration.y * dt.asSeconds();

        // prevent micro glides
        if(-i_buffer < physicsSprite.getVelocity().x && physicsSprite.getVelocity().x < i_buffer)
            new_velocity.x = 0;
    }
    else
    {
        new_velocity.x += i_acceleration.x * dt.asSeconds();
        new_velocity.y += i_acceleration.y * dt.asSeconds();
    }

    physicsSprite.setVelocity(new_velocity);
}

void Force::toggle(bool isOn)
{
    i_isEnabled = isOn;
}
