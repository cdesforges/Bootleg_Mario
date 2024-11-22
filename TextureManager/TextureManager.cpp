//
// Created by Chandler Desforges on 11/18/24.
//

#include <cassert>
#include "TextureManager.h"

std::string TextureManager::getPath(PhysicsSpriteType key)
{
    if(key == MARIO)
        return "mario.png";
    else if(key == BACKGROUND)
        return "background.png";
    else if(key == BLOCK || key == SPECIAL_BLOCK || key == PIPE)
        return "world.png";
    else
        return "error";
}

void TextureManager::load(PhysicsSpriteType key)
{
    if(!m_map.contains(key))
        m_map[key].loadFromFile(getPath(key));
}

const sf::Texture& TextureManager::get(PhysicsSpriteType key)
{
    load(key);

    return m_map.at(key);
}