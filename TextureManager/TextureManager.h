//
// Created by Chandler Desforges on 11/18/24.
//

#ifndef BOOTLEG_MARIO_TEXTUREMANAGER_H
#define BOOTLEG_MARIO_TEXTUREMANAGER_H

#include <map>
#include <SFML/Graphics.hpp>
#include "../Components/PhysicsSprite/PhysicsSpriteType.h"

class TextureManager
{
private:
    inline static std::unordered_map<PhysicsSpriteType, sf::Texture> m_map;
    static void load(PhysicsSpriteType filePath);

    static std::string getPath(PhysicsSpriteType key);

public:
    static const sf::Texture& get(PhysicsSpriteType key);
};

#endif //BOOTLEG_MARIO_TEXTUREMANAGER_H
