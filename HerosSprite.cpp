#include "HerosSprite.hpp"
#include "TileMapDrawer.hpp"

const float rpg::HerosSprite::DEFAULT_SPEED = 100;
const float rpg::HerosSprite::DEFAULT_RUN_FACTOR = 3;

rpg::HerosSprite::HerosSprite() :
    AnimatedSprite(),
    mSpeed(DEFAULT_SPEED), mWalkSpeed(DEFAULT_SPEED), mRunFactor(DEFAULT_RUN_FACTOR),
    mRunning(false), mAsMoved(false), mMovement(0.0f,0.0f)
{

}

void rpg::HerosSprite::init(const sf::Texture& texture)
{
    mWalkingAnimationDown.setSpriteSheet(texture);
    mWalkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
    mWalkingAnimationDown.addFrame(sf::IntRect(64, 0, 32, 32));
    mWalkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
    mWalkingAnimationDown.addFrame(sf::IntRect( 0, 0, 32, 32));

    mWalkingAnimationLeft.setSpriteSheet(texture);
    mWalkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
    mWalkingAnimationLeft.addFrame(sf::IntRect(64, 32, 32, 32));
    mWalkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
    mWalkingAnimationLeft.addFrame(sf::IntRect( 0, 32, 32, 32));

    mWalkingAnimationRight.setSpriteSheet(texture);
    mWalkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
    mWalkingAnimationRight.addFrame(sf::IntRect(64, 64, 32, 32));
    mWalkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
    mWalkingAnimationRight.addFrame(sf::IntRect( 0, 64, 32, 32));

    mWalkingAnimationUp.setSpriteSheet(texture);
    mWalkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
    mWalkingAnimationUp.addFrame(sf::IntRect(64, 96, 32, 32));
    mWalkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
    mWalkingAnimationUp.addFrame(sf::IntRect( 0, 96, 32, 32));

    mCurrentAnimation = &mWalkingAnimationDown;
}

void rpg::HerosSprite::animate(float elapsedTime)
{
    updateAnimation(elapsedTime);

    reInit();
}

void rpg::HerosSprite::run()
{
    mRunning = true;
    mSpeed = mWalkSpeed*mRunFactor;
}

void rpg::HerosSprite::walk()
{
    mRunning = false;
    mSpeed = mWalkSpeed;
}

void rpg::HerosSprite::moveRight()
{
    mCurrentAnimation = &mWalkingAnimationRight;
    mMovement.x += mSpeed;
    mAsMoved = true;
}

void rpg::HerosSprite::moveLeft()
{
    mCurrentAnimation = &mWalkingAnimationLeft;
    mMovement.x -= mSpeed;
    mAsMoved = true;
}

void rpg::HerosSprite::moveUp()
{
    mCurrentAnimation = &mWalkingAnimationUp;
    mMovement.y -= mSpeed;
    mAsMoved = true;
}

void rpg::HerosSprite::moveDown()
{
    mCurrentAnimation = &mWalkingAnimationDown;
    mMovement.y += mSpeed;
    mAsMoved = true;
}

void rpg::HerosSprite::updateAnimation(float elapsedTime)
{
    if (not mAsMoved)
        stop();

    mAsMoved = false;

    play(*mCurrentAnimation);

    move(mMovement * elapsedTime);

    if(mRunning == true)
        elapsedTime *= mRunFactor;

    update(sf::seconds(elapsedTime));
}

void rpg::HerosSprite::reInit()
{
    mMovement.x = 0;
    mMovement.y = 0;
}
