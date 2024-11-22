//
// Created by Chandler Desforges on 11/14/24.
//

#ifndef SFML_PONG_STATE_H
#define SFML_PONG_STATE_H

#include <SFML/Graphics.hpp>

class StateManager;

class State
{
protected:
    StateManager& i_stateManager;
    sf::RenderWindow& i_window;
    sf::View& i_view;

public:
    State(sf::RenderWindow& window, StateManager& stateManager, sf::View& view)
    : i_window(window), i_stateManager(stateManager), i_view(view){};

    virtual ~State() = default;

    virtual void eventHandler(const sf::Event& event) = 0;
    virtual void updateObjects(sf::Time& dt) = 0;
    virtual void updateView() = 0;
    virtual void draw() = 0;
};


#endif //SFML_PONG_STATE_H
