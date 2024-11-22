//
// Created by Chandler Desforges on 11/14/24.
//

#ifndef SFML_PONG_MAINGAMESTATE_H
#define SFML_PONG_MAINGAMESTATE_H

#include "State.h"
#include "../Components/Player/Player.h"
#include "../Components/PhysicsSprite/PhysicsSprite.h"
#include "../Collision/Collision.h"
#include "../Components/Wall/Wall.h"
#include "../Components/Background/Background.h"
#include "../Components/SpecialBlock/SpecialBlock.h"
#include "../Components/Pipe/Pipe.h"
#include "../Components/Block/Block.h"

class MainGameState : public State
{
private:
    // sf::RenderWindow& i_window;
    // StateManager& i_stateManager;
    // sf::View& i_view;
    Background m_background;
    Player m_p1;
    Block m_block1;
    Block m_block2;
    Block m_block3;
    SpecialBlock m_specialBlock1;
    SpecialBlock m_specialBlock2;
    SpecialBlock m_specialBlock3;
    SpecialBlock m_specialBlock4;
    Pipe m_pipe1;
    std::vector<Component*> m_gameComponents;

public:
    explicit MainGameState(sf::RenderWindow& window, StateManager& stateManager, sf::View& view);
    ~MainGameState() override = default;

    void initialize();

    // getters
    std::vector<Collidable*> getCollidableObjects();

    void eventHandler(const sf::Event &event) override;
    void updateObjects(sf::Time &dt) override;
    void updateView() override;
    void draw() override;
};

#endif //SFML_PONG_MAINGAMESTATE_H
