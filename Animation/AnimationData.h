//
// Created by Chandler Desforges on 11/18/24.
//

#ifndef BOOTLEG_MARIO_ANIMATIONDATA_H
#define BOOTLEG_MARIO_ANIMATIONDATA_H


#include <SFML/System/Vector2.hpp>

struct AnimationData
{
    sf::Vector2i origin;
    sf::Vector2i frameSize;
    int numFrames;
};


#endif //BOOTLEG_MARIO_ANIMATIONDATA_H
