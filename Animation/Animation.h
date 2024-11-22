//
// Created by Chandler Desforges on 11/18/24.
//

#ifndef BOOTLEG_MARIO_ANIMATION_H
#define BOOTLEG_MARIO_ANIMATION_H


#include <SFML/Graphics.hpp>
#include "AnimationData.h"
#include "../Components/PhysicsSprite/PhysicsSpriteType.h"
#include "../Components/PhysicsSprite/PhysicsSprite.h"
#include "AnimationType.h"

class PhysicsSprite;

class Animation
{
private:
    const sf::Texture* m_texture = nullptr;
    sf::IntRect m_frameRect;
    std::unordered_map<AnimationType, AnimationData> m_animations;

    AnimationType m_currentAnimation;
    sf::Vector2f m_direction = {1,1};
    unsigned int m_currentFrame = 0;
    sf::Time m_elapsedTime = sf::Time::Zero;
    unsigned int m_framesPerSec = 8;
    unsigned int m_buffer = 17;

private:
    void initialize(const PhysicsSpriteType& type);
    void nextFrame();
    void resetFrameRect();

public:
    Animation(const PhysicsSpriteType& type);

    // setters
    void setAnimation(const AnimationType& type, const sf::Vector2f& direction);
    void setAnimation(const AnimationType& type);


    void update(const sf::Time& dt);
    void animate(PhysicsSprite& sprite);
};


#endif //BOOTLEG_MARIO_ANIMATION_H
