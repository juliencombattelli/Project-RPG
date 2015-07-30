#include "Exploration.hpp"
#include "Application.hpp"
#include "Global.hpp"
#include <SFML/Window/Keyboard.hpp>

namespace rpg
{

Exploration::Exploration(Application* app) : State(app)
{

}

Exploration::~Exploration()
{

}

void Exploration::init()
{
    if (!mTexture.loadFromFile(pictureFolder+"Heros1"+pictureExt))
    {
        std::cout << "Failed to load player spritesheet!" << std::endl;
    }

    mView.setSize(mRenderManager.DEFAULT_VIDEO_WIDTH, mRenderManager.DEFAULT_VIDEO_HEIGHT);
    mView.setCenter(mHeros.getPosition().x+16, mHeros.getPosition().y+16);
    mView.setViewport(sf::FloatRect(0,0,1.0f, 1.0f));

    mTileMap.load("WorldMap");

    mHeros.init(mTexture);
}

void Exploration::cleanup()
{

}

void Exploration::handleEvent(sf::Event& event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        mHeros.run();
    else
        mHeros.walk();

    if (Keyboard.DPad.isMoveUpPressed())
        mHeros.moveUp();
    if (Keyboard.DPad.isMoveDownPressed())
        mHeros.moveDown();
    if (Keyboard.DPad.isMoveLeftPressed())
        mHeros.moveLeft();
    if (Keyboard.DPad.isMoveRightPressed())
        mHeros.moveRight();
}

void Exploration::update(float elapsedTime)
{
    mHeros.animate(elapsedTime);
    updateView();
}

void Exploration::draw()
{
    mRenderManager.setView(mView);
    mRenderManager.draw(mTileMap);
    mRenderManager.draw(mHeros);
}

void Exploration::pause()
{

}

void Exploration::resume()
{

}

void rpg::Exploration::updateView()
{
    sf::Vector2f position;

    if(mView.getSize().x > mTileMap.getSizeX_pix())
        position.x = mTileMap.getSizeX_pix()/2;
    else if(mHeros.getPosition().x + 16 < mView.getSize().x/2)
        position.x = mView.getSize().x/2;
    else if(mHeros.getPosition().x + 16 > mTileMap.getSizeX_pix() - mView.getSize().x/2)
        position.x = mTileMap.getSizeX_pix() - mView.getSize().x/2;
    else
        position.x = mHeros.getPosition().x + 16;

    if(mView.getSize().y > mTileMap.getSizeY_pix())
        position.y = mTileMap.getSizeY_pix()/2;
    else if(mHeros.getPosition().y + 16 < mView.getSize().y/2)
        position.y = mView.getSize().y/2;
    else if(mHeros.getPosition().y + 16 > mTileMap.getSizeY_pix() - mView.getSize().y/2)
        position.y = mTileMap.getSizeY_pix() - mView.getSize().y/2;
    else
        position.y = mHeros.getPosition().y + 16;


    mView.setCenter(position);
}

}
