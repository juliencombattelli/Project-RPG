#ifndef HEROSSPRITE_HPP_INCLUDED
#define HEROSSPRITE_HPP_INCLUDED

#include "AnimatedSprite.hpp"

namespace rpg
{

class HerosSprite : public AnimatedSprite
{
public:
    HerosSprite(sf::Texture& texture);

    void animate(float elapsedTime);
    void run();
    void walk();
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

protected:

    sf::Texture& mTexture;

    float mSpeed;
    bool mRunning;
    bool mAsMoved;

    sf::Vector2f mMovement;

    Animation mWalkingAnimationRight;
    Animation mWalkingAnimationLeft;
    Animation mWalkingAnimationUp;
    Animation mWalkingAnimationDown;

    Animation* mCurrentAnimation;
};

}

#endif // HEROSSPRITE_HPP_INCLUDED
