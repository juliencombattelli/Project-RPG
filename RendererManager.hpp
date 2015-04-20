#ifndef RENDERERMANAGER_HPP_INCLUDED
#define RENDERERMANAGER_HPP_INCLUDED

#include "Type.hpp"

#include <SFML/Graphics.hpp>

namespace rpg
{

class Application;

class RendererManager
{
public:

    static const int   DEFAULT_VIDEO_WIDTH;
    static const int   DEFAULT_VIDEO_HEIGHT;
    static const int   DEFAULT_VIDEO_BPP;
    static const int   DEFAULT_FRAMERATE_LIMIT;
    static const char* DEFAULT_TITLE;

    RendererManager() = delete;
    RendererManager(Application* app);
    RendererManager(const RendererManager&) = delete;
    RendererManager& operator=(const RendererManager&) = delete;
    ~RendererManager();

    void init() {}

    sf::RenderWindow& getWindow() { return mWindow; }

    void toggleFullscreen();

private:

    Application* mApp;

    sf::RenderWindow mWindow;
    bool mFullscreen;
};

}

#endif // RENDERERMANAGER_HPP_INCLUDED
