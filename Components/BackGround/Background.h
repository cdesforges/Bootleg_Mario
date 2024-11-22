//
// Created by Chandler Desforges on 11/19/24.
//

#ifndef BOOTLEG_MARIO_BACKGROUND_H
#define BOOTLEG_MARIO_BACKGROUND_H

#include "../PhysicsSprite/PhysicsSprite.h"
#include "../../Animation/Animation.h"

class Background : public Component, public Collidable
{
private:
    PhysicsSprite m_background;

public:
    Background();

    bool isStatic() override;
    sf::FloatRect getGlobalBounds() const override;
    void collisionReaction(const Collidable& other) override;
    void update(sf::Time& dt) override;
    void draw(sf::RenderTarget& window, sf::RenderStates state) const override;
};


#endif //BOOTLEG_MARIO_BACKGROUND_H
