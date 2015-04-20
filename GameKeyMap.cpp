#include "GameKeyMap.hpp"

namespace rpg
{

GameKeyMap::GameKeyMap()
{
    mGameKeysMap[gameKey::pause] = sf::Keyboard::P;
    mGameKeysMap[gameKey::accept] = sf::Keyboard::Return;
    mGameKeysMap[gameKey::refuse] = sf::Keyboard::Escape;
    mGameKeysMap[gameKey::moveUp] = sf::Keyboard::Up;
    mGameKeysMap[gameKey::moveDown] = sf::Keyboard::Down;
    mGameKeysMap[gameKey::moveLeft] = sf::Keyboard::Left;
    mGameKeysMap[gameKey::moveRight] = sf::Keyboard::Right;
}

GameKeyMap::GameKeyMap(const std::string& fileName)
{

}

GameKeyMap::~GameKeyMap()
{

}

sf::Keyboard::Key GameKeyMap::operator[](const gameKey& key)
{
    return mGameKeysMap[key];
}

void GameKeyMap::setAssociation(const gameKey& gamekey, const sf::Keyboard::Key& key)
{
    mGameKeysMap[gamekey] = key;
}


}
