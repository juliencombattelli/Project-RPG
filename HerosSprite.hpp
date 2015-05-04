#ifndef HEROSSPRITE_HPP_INCLUDED
#define HEROSSPRITE_HPP_INCLUDED

#include "AnimatedSprite.hpp"

namespace rpg
{

class TileMapDrawer;

class HerosSprite : public AnimatedSprite
{
public:
    HerosSprite(sf::Texture& texture, sf::View& view, rpg::TileMapDrawer& tileMap);

    void animate(float elapsedTime);
    void run();
    void walk();
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

protected:

    static const float DEFAULT_SPEED;
    static const float DEFAULT_RUN_FACTOR;

    sf::Texture& mTexture;
    sf::View& mView;
    rpg::TileMapDrawer& mTileMap;

    float mSpeed;
    float mWalkSpeed;
    float mRunFactor;
    bool mRunning;
    bool mAsMoved;

    sf::Vector2f mMovement;

    Animation mWalkingAnimationRight;
    Animation mWalkingAnimationLeft;
    Animation mWalkingAnimationUp;
    Animation mWalkingAnimationDown;

    Animation* mCurrentAnimation;

    void updateAnimation(float elapsedTime);
    void updateView();
    void reInit();
};

}

#endif // HEROSSPRITE_HPP_INCLUDED
