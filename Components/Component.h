//
// Created by Chandler Desforges on 11/14/24.
//

#ifndef SFML_PONG_COMPONENT_H
#define SFML_PONG_COMPONENT_H


class Component : public sf::Drawable
{
public:
    virtual void update(sf::Time& dt) = 0;
};


#endif //SFML_PONG_COMPONENT_H
