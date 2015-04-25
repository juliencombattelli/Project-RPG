
///////////////////////////////////////////////////////////////////////////////////////////////////
// Animated Sprite test
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include <iostream>

int main()
{
    // setup window
    sf::Vector2i screenDimensions(800,600);
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Animations!");
    window.setFramerateLimit(60);

    // load texture (spritesheet)
    sf::Texture texture;
    if (!texture.loadFromFile("ressource/picture/Heros1.png"))
    {
        std::cout << "Failed to load player spritesheet!" << std::endl;
        return 1;
    }

    // set up the animations for all four directions (set spritesheet and push frames)
    Animation walkingAnimationDown;
    walkingAnimationDown.setSpriteSheet(texture);
    walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(64, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect( 0, 0, 32, 32));

    Animation walkingAnimationLeft;
    walkingAnimationLeft.setSpriteSheet(texture);
    walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect(64, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
    walkingAnimationLeft.addFrame(sf::IntRect( 0, 32, 32, 32));

    Animation walkingAnimationRight;
    walkingAnimationRight.setSpriteSheet(texture);
    walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(64, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect( 0, 64, 32, 32));

    Animation walkingAnimationUp;
    walkingAnimationUp.setSpriteSheet(texture);
    walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(64, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect( 0, 96, 32, 32));

    Animation* currentAnimation = &walkingAnimationDown;

    // set up AnimatedSprite
    AnimatedSprite animatedSprite(sf::seconds(0.2), true, false);
    animatedSprite.setPosition(sf::Vector2f(screenDimensions / 2));

    sf::Clock frameClock;

    float speed = 80.f;
    bool noKeyWasPressed = true;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        sf::Time frameTime = frameClock.restart();

        // if a key was pressed set the correct animation and move correctly
        sf::Vector2f movement(0.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            currentAnimation = &walkingAnimationUp;
            movement.y -= speed;
            noKeyWasPressed = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            currentAnimation = &walkingAnimationDown;
            movement.y += speed;
            noKeyWasPressed = false;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            currentAnimation = &walkingAnimationLeft;
            movement.x -= speed;
            noKeyWasPressed = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            currentAnimation = &walkingAnimationRight;
            movement.x += speed;
            noKeyWasPressed = false;
        }
        animatedSprite.play(*currentAnimation);
        animatedSprite.move(movement * frameTime.asSeconds());

        // if no key was pressed stop the animation
        if (noKeyWasPressed)
        {
            animatedSprite.stop();
        }
        noKeyWasPressed = true;

        // update AnimatedSprite
        animatedSprite.update(frameTime);

        // draw
        window.clear();
        window.draw(animatedSprite);
        window.display();
    }

    return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////////////
// TileMap test
///////////////////////////////////////////////////////////////////////////////////////////////////
/*#include "TileLoader.hpp"
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

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
            cam.zoom(1.05f);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
            cam.zoom(0.95f);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            cam.move(0.f,-10.f);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            cam.move(-10.f,0.f);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            cam.move(0.f,10.f);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            cam.move(10.f,0.f);

        app.setView(cam);
        app.clear();
        app.draw(testmap);
        app.display();
    }
}*/

///////////////////////////////////////////////////////////////////////////////////////////////////
// RPG main
///////////////////////////////////////////////////////////////////////////////////////////////////

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
