#ifndef EXPLORATION_HPP_INCLUDED
#define EXPLORATION_HPP_INCLUDED

#include "State.hpp"
#include "TileMapDrawer.hpp"
#include "HerosSprite.hpp"

namespace rpg
{

class Exploration : public State
{
public:
    Exploration(Application* app);
    virtual ~Exploration();

    virtual void init() final;
    virtual void cleanup() final;

    virtual void handleEvent(sf::Event& event) final;
    virtual void update(float elapsedTime) final;
    virtual void draw() final;

    virtual void pause() final;
    virtual void resume() final;

private:

    void updateView();

    sf::Texture         mTexture;
    sf::View            mView;
    rpg::TileMapDrawer  mTileMap;
    rpg::HerosSprite    mHeros;

};

}


#endif // EXPLORATION_HPP_INCLUDED
