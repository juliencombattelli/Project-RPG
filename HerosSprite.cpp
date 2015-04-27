#include "HerosSprite.hpp"
#include "TileLoader.hpp"

const float rpg::HerosSprite::DEFAULT_SPEED = 100;
const float rpg::HerosSprite::DEFAULT_RUN_FACTOR = 3;

rpg::HerosSprite::HerosSprite(sf::Texture& texture, sf::View& view, rpg::TileLoader& tileMap) :
    AnimatedSprite(), mTexture(texture), mView(view), mTileMap(tileMap),
    mSpeed(DEFAULT_SPEED), mWalkSpeed(DEFAULT_SPEED), mRunFactor(DEFAULT_RUN_FACTOR),
    mRunning(false), mAsMoved(false), mMovement(0.0f,0.0f)
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

    updateView();

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

void rpg::HerosSprite::updateView()
{
    sf::Vector2f position;

    if(mView.getSize().x > mTileMap.getData().sizeX_pix())
        position.x = mTileMap.getData().sizeX_pix()/2;
    else if(getPosition().x + 16 < mView.getSize().x/2)
        position.x = mView.getSize().x/2;
    else if(getPosition().x + 16 > mTileMap.getData().sizeX_pix() - mView.getSize().x/2)
        position.x = mTileMap.getData().sizeX_pix() - mView.getSize().x/2;
    else
        position.x = getPosition().x + 16;

    if(mView.getSize().y > mTileMap.getData().sizeY_pix())
        position.y = mTileMap.getData().sizeY_pix()/2;
    else if(getPosition().y + 16 < mView.getSize().y/2)
        position.y = mView.getSize().y/2;
    else if(getPosition().y + 16 > mTileMap.getData().sizeY_pix() - mView.getSize().y/2)
        position.y = mTileMap.getData().sizeY_pix() - mView.getSize().y/2;
    else
        position.y = getPosition().y + 16;


    mView.setCenter(position);
}

void rpg::HerosSprite::reInit()
{
    mMovement.x = 0;
    mMovement.y = 0;
}
