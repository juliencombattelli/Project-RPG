#include "CarreRouge.hpp"
#include "Application.hpp"

namespace rpg
{

CarreRouge::CarreRouge(Application* app) : State(app), mRectangle(), mSpeed(150)
{
    mRectangle.setSize(sf::Vector2f(50, 50));
    mRectangle.setFillColor(sf::Color::Red);
    mRectangle.setPosition(10, 20);
}

CarreRouge::~CarreRouge()
{

}

void CarreRouge::handleEvent(sf::Event& event)
{
    if(mApp->mKeyboard::isKeyPressed(sf::Keyboard::P))
    {
        mEvent.createState(StateID::MENU);
        LOGE(SeverityInfo, "State <MENU> created");
    }

}

void CarreRouge::update(float elapsedTime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        mRectangle.move( 0,-mSpeed*elapsedTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        mRectangle.move( 0,+mSpeed*elapsedTime);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        mRectangle.move(-mSpeed*elapsedTime, 0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        mRectangle.move(+mSpeed*elapsedTime, 0);
}

void CarreRouge::draw()
{
    mApp->getRendererManager().getWindow().draw(mRectangle);
}

void CarreRouge::pause()
{

}

void CarreRouge::resume()
{

}

void CarreRouge::cleanup()
{

}

}
