//
// Created by Chandler Desforges on 11/14/24.
//

#include "MainGameState.h"

MainGameState::MainGameState(sf::RenderWindow& window, StateManager& stateManager, sf::View& view)
: State(window, stateManager, view),
m_p1({i_view.getCenter()}),
m_background(),
m_block1({320, 144}),
m_block2({320 + 32, 144}),
m_block3({320 + 64, 144}),
m_specialBlock1({256,144}),
m_specialBlock2({336,144}),
m_specialBlock3({336 + 32,144}),
m_specialBlock4({320 + 32,80}),
m_pipe1({448, 176})
{
    initialize();
}

void MainGameState::initialize()
{
    m_p1.setControls(sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::Space);

    m_gameComponents.push_back(&m_background);
    m_gameComponents.push_back(&m_p1);
    m_gameComponents.push_back(&m_block1);
    m_gameComponents.push_back(&m_block2);
    m_gameComponents.push_back(&m_block3);
    m_gameComponents.push_back(&m_specialBlock1);
    m_gameComponents.push_back(&m_specialBlock2);
    m_gameComponents.push_back(&m_specialBlock3);
    m_gameComponents.push_back(&m_specialBlock4);
    m_gameComponents.push_back(&m_pipe1);
}

std::vector<Collidable*> MainGameState::getCollidableObjects()
{
    std::vector<Collidable*> res;

    for(auto& comp : m_gameComponents)
        if(auto* collidable = dynamic_cast<Collidable*>(comp))
            res.push_back(collidable);

    return res;
}

void MainGameState::eventHandler(const sf::Event& event)
{
    for(auto& component : m_gameComponents)
        if(auto controllableComponent = dynamic_cast<KeyboardControllable*>(component))
            controllableComponent->eventHandler(event);
}

void MainGameState::updateObjects(sf::Time& dt)
{
    // update components
    for(auto& component : m_gameComponents)
        component->update(dt);

    // handle collisions
    Collision::resolveCollisions(getCollidableObjects());
}

void MainGameState::updateView()
{
    i_view.setCenter({m_p1.getPosition().x, i_view.getCenter().y});
}

void MainGameState::draw()
{
    for(auto& component : m_gameComponents)
        i_window.draw(*component);
}
