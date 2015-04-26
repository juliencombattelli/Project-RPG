#include "HerosSprite.hpp"

const float rpg::HerosSprite::DEFAULT_SPEED = 80;

rpg::HerosSprite::HerosSprite(sf::Texture& texture, sf::View& view, bool scrollingEnable) :
    AnimatedSprite(), mView(view), mTexture(texture), mScrollingEnable(scrollingEnable),
    mSpeed(DEFAULT_SPEED), mRunning(false), mAsMoved(false), mMovement(0.0f,0.0f)
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
    if (not mAsMoved)
        stop();

    mAsMoved = false;

    play(*mCurrentAnimation);

    move(mMovement * elapsedTime);

    mView.move(mMovement * elapsedTime);

    if(mRunning == true)
        elapsedTime *= 2;

    update(sf::seconds(elapsedTime));

    mMovement.x = 0;
    mMovement.y = 0;
}

void rpg::HerosSprite::run()
{
    mRunning = true;
    mSpeed = DEFAULT_SPEED*2;
}

void rpg::HerosSprite::walk()
{
    mRunning = false;
    mSpeed = DEFAULT_SPEED;
}

void rpg::HerosSprite::moveRight()
{
    mCurrentAnimation = &mWalkingAnimationRight;
    mMovement.x += mSpeed;
    if(mScrollingEnable)
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
