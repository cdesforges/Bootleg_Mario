//
// Created by Chandler Desforges on 11/14/24.
//

#include "Player.h"

Player::Player()
: Player(MARIO, {0,0})
{}

Player::Player(const sf::Vector2f& initialPosition)
: Player(MARIO, initialPosition)
{}

Player::Player(const PhysicsSpriteType& type, const sf::Vector2f& initialPosition)
: m_physicsSprite(type, initialPosition), m_animation(type)
{}

void Player::updateAnimation(const sf::Time& dt)
{
    if(m_physicsSprite.isOnObject())
    {
        // if moving left and right
        if(m_physicsSprite.getVelocity().x > 0)
            m_animation.setAnimation(WALK, {1,1});
        else if(m_physicsSprite.getVelocity().x < 0)
            m_animation.setAnimation(WALK, {-1,1});

        // if stopped
        if(m_physicsSprite.getVelocity().x == 0) m_animation.setAnimation(IDLE);
    }
    else
        m_animation.setAnimation(JUMP);

    m_animation.animate(m_physicsSprite);
    m_animation.update(dt);
}

bool Player::isStatic()
{
    return false;
}

sf::FloatRect Player::getGlobalBounds() const
{
    return m_physicsSprite.getGlobalBounds();
}

const sf::Vector2f& Player::getPosition() const
{
    return m_physicsSprite.getPosition();
}

void Player::setControls(const sf::Keyboard::Key& up, const sf::Keyboard::Key& down,
                         const sf::Keyboard::Key& left, const sf::Keyboard::Key& right,
                         const sf::Keyboard::Key& jump)
{
    m_controls = {up, down, left, right, jump};
}

void Player::collisionReaction(const Collidable& other)
{
    m_physicsSprite.collisionReaction(other);
}

void Player::eventHandler(const sf::Event& event)
{
    // horizontal input
    if(sf::Keyboard::isKeyPressed(m_controls.left))
        m_physicsSprite.move({-20,0}, 150);
    else if(sf::Keyboard::isKeyPressed(m_controls.right))
        m_physicsSprite.move({20,0}, 150);

    // jump
    if(sf::Keyboard::isKeyPressed(m_controls.jump) && m_canJump)
    {
        if(m_physicsSprite.isOnObject())
            m_numJumps = 0;

        if(m_numJumps < m_MAX_JUMPS)
        {
            m_canJump = false;
            m_numJumps++;
            m_physicsSprite.jump();
        }
    }

    if(!sf::Keyboard::isKeyPressed(m_controls.jump))
        m_canJump = true;
}

void Player::update(sf::Time& dt)
{
    // apply gravity
    Gravity::apply(m_physicsSprite, dt);

    // apply friction
    if(m_physicsSprite.isOnObject())
        Friction::apply(m_physicsSprite, dt);

    // apply air resistance
    if(!m_physicsSprite.isOnObject())
        AirResistance::apply(m_physicsSprite, dt);

    updateAnimation(dt);

    m_physicsSprite.update(dt);
}

void Player::draw(sf::RenderTarget& window, sf::RenderStates state) const
{
    window.draw(m_physicsSprite);
}
