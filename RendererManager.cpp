#include "RendererManager.hpp"

namespace rpg
{

const int   RendererManager::DEFAULT_VIDEO_WIDTH        = 800;
const int   RendererManager::DEFAULT_VIDEO_HEIGHT       = 600;
const int   RendererManager::DEFAULT_VIDEO_BPP          = 32;
const int   RendererManager::DEFAULT_FRAMERATE_LIMIT    = 60;
const bool  RendererManager::DEFAULT_VSYNC_ENABLE       = false;
const int   RendererManager::DEFAULT_ANTIALIASING       = 1;
const char* RendererManager::DEFAULT_TITLE              = "SFML Window";

RendererManager::RendererManager(Application* app) :
    mApp(app),
    mFullscreen(false)
{
    mVideoMode                  = sf::VideoMode(DEFAULT_VIDEO_WIDTH, DEFAULT_VIDEO_HEIGHT, DEFAULT_VIDEO_BPP);
    mSettings.depthBits         = 24;
    mSettings.stencilBits       = 8;
    mSettings.antialiasingLevel = DEFAULT_ANTIALIASING;
    mSettings.majorVersion      = 2.0;
    mSettings.minorVersion      = 0;
    mTitle                      = DEFAULT_TITLE;
    mStyle                      = sf::Style::Default;

    mWindow.create( mVideoMode, mTitle, mStyle, mSettings );
    mWindow.setFramerateLimit(DEFAULT_FRAMERATE_LIMIT);
    mWindow.setVerticalSyncEnabled(DEFAULT_VSYNC_ENABLE);
    mWindow.setMouseCursorVisible(false);

    /*sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 1;
    settings.majorVersion = 2.0;
    settings.minorVersion = 0;

    sf::Window window(sf::VideoMode(800, 600), "OpenGL", sf::Style::Default, settings);

    sf::ContextSettings settings2 = window.getSettings();

    std::cout << "depth bits:" << settings2.depthBits << std::endl;
    std::cout << "stencil bits:" << settings2.stencilBits << std::endl;
    std::cout << "antialiasing level:" << settings2.antialiasingLevel << std::endl;
    std::cout << "version:" << settings2.majorVersion << "." << settings.minorVersion << std::endl;*/

}

RendererManager::~RendererManager()
{
    mApp = nullptr;
}

}
