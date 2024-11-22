//
// Created by Chandler Desforges on 11/14/24.
//

#ifndef SFML_PONG_PLAYER_H
#define SFML_PONG_PLAYER_H


#include <SFML/Graphics.hpp>
#include "../Component.h"
#include "../../KeyboardControls/PlayerControls.h"
#include "../../Collision/Collidable.h"
#include "../PhysicsSprite/PhysicsSprite.h"
#include "../../KeyboardControls/KeyboardControllable.h"
#include "../../Animation/Animation.h"
#include "../../GameLogic/Gravity.h"
#include "../../GameLogic/Friction.h"
#include "../../GameLogic/AirResistance.h"

class Player : public Component, public Collidable, public KeyboardControllable
{
private:
    PhysicsSprite m_physicsSprite;
    Animation m_animation;

    float m_walkSpeed = 150;
    float m_jumpSpeed = -400;
    PlayerControls m_controls;
    unsigned int m_numJumps = 0;
    const unsigned int m_MAX_JUMPS = 1;
    int m_score = 0;
    bool m_canJump = true;

private:
    void updateAnimation(const sf::Time& dt);

public:
    Player();
    explicit Player(const sf::Vector2f& initialPosition);
    Player(const PhysicsSpriteType& type, const sf::Vector2f& initialPosition);

    // getters
    int getScore() const {return m_score;};
    sf::FloatRect getGlobalBounds() const override; // inherited!
    const sf::Vector2f& getPosition() const;

    // setters
    void setScore(int score) {m_score = score;};
    void setControls(const sf::Keyboard::Key& up, const sf::Keyboard::Key& down,
                     const sf::Keyboard::Key& left, const sf::Keyboard::Key& right,
                     const sf::Keyboard::Key& jump);

    // inherited
    bool isStatic() override;
    void collisionReaction(const Collidable& other) override;
    void eventHandler(const sf::Event& event) override;
    void update(sf::Time& dt) override;
    void draw(sf::RenderTarget& window, sf::RenderStates state) const override;
};


#endif //SFML_PONG_PLAYER_H
