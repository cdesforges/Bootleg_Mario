//
// Created by Chandler Desforges on 11/14/24.
//

#ifndef SFML_PONG_GAME_H
#define SFML_PONG_GAME_H


#include <SFML/Graphics.hpp>
#include "States/StateManager.h"
#include "States/MenuState.h"
#include "States/MainGameState.h"
#include "States/State.h"

class Game
{
private:
    sf::RenderWindow m_window;
    sf::View m_view;
    StateManager m_stateManager;
    sf::Time m_dt;
    sf::Clock m_clock;
    sf::Time m_FIXED_TIMESTEP;
    sf::Time m_accumulator = sf::Time::Zero;

public:
    Game();

    void initialize();

    void resetAspectRatio();

    void run();
};


#endif //SFML_PONG_GAME_H
