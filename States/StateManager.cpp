//
// Created by Chandler Desforges on 11/14/24.
//

#include <cassert>
#include "StateManager.h"

StateManager::StateManager(sf::RenderWindow& window)
: m_window(window)
{}

void StateManager::push(State* state)
{
    m_states.push(state);
}

void StateManager::pop()
{
    if(!m_states.empty())
    {
        delete m_states.top();
        m_states.pop();
    }
}

void StateManager::replace(State* state)
{
    pop();
    m_states.push(state);
}

State* StateManager::currentState()
{
    assert(!m_states.empty() && "Tried to currentState from empty state stack!");

    return m_states.empty() ? nullptr : m_states.top();
}
