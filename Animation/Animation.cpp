//
// Created by Chandler Desforges on 11/18/24.
//

#include <cassert>
#include "Animation.h"
#include "../TextureManager/TextureManager.h"
#include <iostream>

Animation::Animation(const PhysicsSpriteType& type)
: m_currentAnimation(DEFAULT)
{
    // set values based on enum
    initialize(type);

    // set original frame rectangle boundaries
    resetFrameRect();
}

void Animation::initialize(const PhysicsSpriteType& type)
{
    if(type == MARIO)
    {
        m_texture = &TextureManager::get(type);

        m_animations[IDLE] = {{9,37}, {16,17},1};
        m_animations[WALK] = {{122,37}, {16,17},2};
        m_animations[RUN] = {{192,37}, {16,17}, 2};
        m_animations[JUMP] = {{299,37}, {16,17}, 1};
        m_animations[CROUCH] = {{83,37}, {16,17},1};
        m_animations[DEFAULT] = m_animations[IDLE];
    }
    else
        assert(false && "We can't make that type yet!");
}

void Animation::resetFrameRect()
{
    m_frameRect.left = m_animations[m_currentAnimation].origin.x;
    m_frameRect.width = m_animations[m_currentAnimation].frameSize.x;
    m_frameRect.top = m_animations[m_currentAnimation].origin.y;
    m_frameRect.height = m_animations[m_currentAnimation].frameSize.y;
}

void Animation::nextFrame()
{
    // Advance to the next frame
    m_currentFrame++;

    // Check if we've reached the end of the animation
    if (m_currentFrame >= m_animations[m_currentAnimation].numFrames)
        m_currentFrame = 0; // Reset to the first frame

    // Calculate the new frame rectangle position
    const auto& anim = m_animations[m_currentAnimation];
    m_frameRect.left = (int)(anim.origin.x + (anim.frameSize.x * m_currentFrame) + (m_currentFrame * m_buffer));
    m_frameRect.top = anim.origin.y;
    m_frameRect.width = anim.frameSize.x;
    m_frameRect.height = anim.frameSize.y;

    if(m_direction.x == -1)
    {
        m_frameRect.left += anim.frameSize.x;
        m_frameRect.width *= -1;
    }

    if(m_direction.y == -1)
    {
        m_frameRect.top += anim.frameSize.y;
        m_frameRect.height *= -1;
    }
}

void Animation::setAnimation(const AnimationType& type, const sf::Vector2f& direction)
{
    m_currentAnimation = type;
    m_direction = direction;
}

void Animation::setAnimation(const AnimationType& type)
{
    m_currentAnimation = type;
}

void Animation::update(const sf::Time& dt)
{
    m_elapsedTime += dt;

    if(m_elapsedTime.asSeconds() > (1.f / (float)m_framesPerSec))
    {
        nextFrame();
        m_elapsedTime = sf::Time::Zero;
    }
}

void Animation::animate(PhysicsSprite& sprite)
{
    sprite.setTextureRect(m_frameRect);
}
