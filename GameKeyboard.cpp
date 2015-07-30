#include "GameKeyboard.hpp"

namespace rpg
{

GameKeyboard::GameKeyboard() :
    DPad(*this),
    mGameKeyState{{ new GameKeyState(sf::Keyboard::Pause),
                    new GameKeyState(sf::Keyboard::Return),
                    new GameKeyState(sf::Keyboard::Escape),
                    new GameKeyState(sf::Keyboard::Up),
                    new GameKeyState(sf::Keyboard::Down),
                    new GameKeyState(sf::Keyboard::Left),
                    new GameKeyState(sf::Keyboard::Right) }}
{

}

GameKeyboard::~GameKeyboard()
{
    delete mGameKeyState[static_cast<int>(GameKey::pause)];
    delete mGameKeyState[static_cast<int>(GameKey::accept)];
    delete mGameKeyState[static_cast<int>(GameKey::refuse)];
    delete mGameKeyState[static_cast<int>(GameKey::moveUp)];
    delete mGameKeyState[static_cast<int>(GameKey::moveDown)];
    delete mGameKeyState[static_cast<int>(GameKey::moveLeft)];
    delete mGameKeyState[static_cast<int>(GameKey::moveRight)];
}

void GameKeyboard::changeKeyCode(GameKey key, sf::Keyboard::Key newCode)
{
	mGameKeyState[static_cast<int>(key)]->changeKeyCode(newCode);
}

void GameKeyboard::update()
{
    mGameKeyState[static_cast<int>(GameKey::pause)]->update();
    mGameKeyState[static_cast<int>(GameKey::accept)]->update();
    mGameKeyState[static_cast<int>(GameKey::refuse)]->update();
    mGameKeyState[static_cast<int>(GameKey::moveUp)]->update();
    mGameKeyState[static_cast<int>(GameKey::moveDown)]->update();
    mGameKeyState[static_cast<int>(GameKey::moveLeft)]->update();
    mGameKeyState[static_cast<int>(GameKey::moveRight)]->update();

    DPad.update();
}

GameKeyboard Keyboard;

}
