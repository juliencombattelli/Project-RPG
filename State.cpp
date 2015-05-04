#include "State.hpp"
#include "Application.hpp"

namespace rpg
{

State::State(Application* app) : mApp(app), mRenderManager(app->getRendererManager()), mEvent()
{

}

State::~State()
{

}

}
