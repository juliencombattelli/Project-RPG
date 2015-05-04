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
    static const bool  DEFAULT_VSYNC_ENABLE;
    static const int   DEFAULT_ANTIALIASING;
    static const char* DEFAULT_TITLE;

    RendererManager() = delete;
    RendererManager(Application* app);
    RendererManager(const RendererManager&) = delete;
    RendererManager& operator=(const RendererManager&) = delete;
    ~RendererManager();

    void init();

    void clear();
    void draw(const sf::Drawable & object);
    void display();

    sf::RenderWindow& getWindow() { return mWindow; }

    void toggleFullscreen();

private:

    Application* mApp;

    sf::RenderWindow    mWindow;
    sf::ContextSettings mSettings;
    sf::VideoMode       mVideoMode;
    std::string         mTitle;
    uint8_t             mStyle;
    bool                mFullscreen;
};

}

#endif // RENDERERMANAGER_HPP_INCLUDED
