//
// Created by Chandler Desforges on 11/14/24.
//

#include "Game.h"


Game::Game()
: m_window({1280, 960}, "Game", sf::Style::Default),
  m_stateManager(m_window), m_view({0,0,320,240})
{
    initialize();
}

void Game::initialize()
{
    m_view.setViewport({0,0,1,1});
    m_FIXED_TIMESTEP = sf::seconds(1.f/1000.f);
    m_window.setFramerateLimit(60);
    m_stateManager.push(new MainGameState(m_window, m_stateManager, m_view));
}

void Game::run()
{
    // main loop
    while(m_window.isOpen())
    {
        // update delta time
        m_dt = m_clock.restart();
        m_accumulator += m_dt;

        sf::Event event{};

        // check for user events
        while(m_window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                m_window.close();
            if(event.type == sf::Event::Resized)
            {
                resetAspectRatio();
            }
        }

        m_stateManager.currentState()->eventHandler(event);

        // update game components
        while(m_accumulator >= m_FIXED_TIMESTEP)
        {
            m_stateManager.currentState()->updateObjects(m_FIXED_TIMESTEP);
            m_accumulator -= m_FIXED_TIMESTEP;
        }

        // move the view
        m_stateManager.currentState()->updateView();

        // clear the window
        m_window.clear();

        // draw everything
        m_stateManager.currentState()->draw();

        // display the window
        m_window.display();

        m_window.setView(m_view);

    }
}

void Game::resetAspectRatio()
{
    // set screen aspect ratio
    float screenWidth = 4.f;
    float screenHeight = 3.f;

    // get the resized size
    sf::Vector2u size = m_window.getSize();

    // setup my wanted aspect ratio
    float  heightRatio = screenHeight / screenWidth;
    float  widthRatio = screenWidth / screenHeight;

    // adapt the resized window to my wanted aspect ratio
    if ((float)size.y * widthRatio <= (float)size.x)
    {
        size.x = (int)((float)size.y * widthRatio);
    }
    else if ((float)size.x * heightRatio <= (float)size.y)
    {
        size.y = (int)((float)size.x * heightRatio);
    }

    // set the new size
    m_window.setSize(size);
}
