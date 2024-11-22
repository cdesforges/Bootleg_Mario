//
// Created by Chandler Desforges on 11/4/24.
//

#ifndef SFML_PONG_BALLVIEW_H
#define SFML_PONG_BALLVIEW_H


#include <SFML/Graphics.hpp>
#include "PhysicsModel.h"
#include "../../TextureManager/TextureManager.h"
#include "PhysicsSpriteType.h"

class SpriteView : public sf::Drawable
{
private:
    sf::Sprite m_characterSprite;
    const sf::Texture* m_texture;

public:
    SpriteView(const PhysicsSpriteType& type, const sf::Vector2f& scale, const sf::Vector2f& initialPosition);

    // getters
    sf::FloatRect getGlobalBounds() const;

    // setters
    void setTextureRect(const sf::IntRect& uvRect);

    void update(const PhysicsModel& model, const sf::Time& dt);

    // inherited
    void draw(sf::RenderTarget& window, sf::RenderStates state) const override;
};


#endif //SFML_PONG_BALLVIEW_H
