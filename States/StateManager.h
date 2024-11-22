//
// Created by Chandler Desforges on 11/14/24.
//

#ifndef SFML_PONG_STATEMANAGER_H
#define SFML_PONG_STATEMANAGER_H

#include "State.h"

class StateManager
{
private:
    std::stack<State*> m_states;

public:
    sf::RenderWindow& m_window;

public:
    StateManager(sf::RenderWindow& window);

    void push(State* state);
    void pop();
    void replace(State* state);
    State* currentState();
};


#endif //SFML_PONG_STATEMANAGER_H
