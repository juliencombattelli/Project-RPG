#include "TileLoader.hpp"
#include "StaticTiledMap.hpp"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

class ExampleLoader : public TileLoader
{
public:
    ExampleLoader(void)
    {
        m_mapdata.sizeX=100;
        m_mapdata.sizeY=100;
        m_mapdata.textureName="ressource/picture/World.png";//a simple 32x32 seamless image of brick
    }
    virtual void appendTile(int gx,int gy,sf::VertexArray& garr)
    {
        sf::Vertex ver;
        ver.position=sf::Vector2f(gx*32.f,gy*32.f);
        ver.texCoords=sf::Vector2f(0.f,0.f);
        garr.append(ver);

        ver.position=sf::Vector2f(gx*32.f+32.f,gy*32.f);
        ver.texCoords=sf::Vector2f(32.f,0.f);
        garr.append(ver);

        ver.position=sf::Vector2f(gx*32.f+32.f,gy*32.f+32.f);
        ver.texCoords=sf::Vector2f(32.f,32.f);
        garr.append(ver);

        ver.position=sf::Vector2f(gx*32.f,gy*32.f+32.f);
        ver.texCoords=sf::Vector2f(0.f,32.f);
        garr.append(ver);
    }
};

int main(int argc, char* argv[])
{
    sf::RenderWindow app(sf::VideoMode(600,600),"test Tile map");
    app.setVerticalSyncEnabled(true);
    sf::View cam=app.getDefaultView();

    StaticTiledMap testmap;
    ExampleLoader example;
    testmap.LoadFrom(&example);
    while(app.isOpen())
    {
        sf::Event eve;
        while(app.pollEvent(eve))
            if(eve.type==sf::Event::Closed)
                app.close();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            cam.zoom(1.05f);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            cam.move(0.f,-10.f);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            cam.zoom(0.95f);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            cam.move(-10.f,0.f);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            cam.move(0.f,10.f);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            cam.move(10.f,0.f);

        app.setView(cam);
        app.clear();
        app.draw(testmap);
        app.display();
    }
}



/*#include <iostream>
#include "Application.hpp"
#include "GameKeyStateManager.hpp"

int main()
{
    int exitStatus = rpg::StatusNoError;

    rpg::Application* app = new rpg::Application();

    exitStatus = app->run();

    delete app;

    app = nullptr;

    return exitStatus;
}*/
