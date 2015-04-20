#include "RendererManager.hpp"

namespace rpg
{

const int   RendererManager::DEFAULT_VIDEO_WIDTH        = 800;
const int   RendererManager::DEFAULT_VIDEO_HEIGHT       = 600;
const int   RendererManager::DEFAULT_VIDEO_BPP          = 32;
const int   RendererManager::DEFAULT_FRAMERATE_LIMIT    = 60;
const char* RendererManager::DEFAULT_TITLE              = "SFML Window";

RendererManager::RendererManager(Application* app) :
    mApp(app),
    mWindow(sf::VideoMode(DEFAULT_VIDEO_WIDTH, DEFAULT_VIDEO_HEIGHT), DEFAULT_TITLE),
    mFullscreen(false)
{
    mWindow.setFramerateLimit(DEFAULT_FRAMERATE_LIMIT);
}

RendererManager::~RendererManager()
{
    mApp = nullptr;
}

}
