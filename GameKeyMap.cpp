#include "GameKeyMap.hpp"

namespace rpg
{

GameKeyMap::GameKeyMap()
{
    mKeyAssociation[static_cast<size_t>(GameKey::pause)] = sf::Keyboard::P;
    mKeyAssociation[static_cast<size_t>(GameKey::accept)] = sf::Keyboard::Return;
    mKeyAssociation[static_cast<size_t>(GameKey::refuse)] = sf::Keyboard::Escape;
    mKeyAssociation[static_cast<size_t>(GameKey::moveUp)] = sf::Keyboard::Up;
    mKeyAssociation[static_cast<size_t>(GameKey::moveDown)] = sf::Keyboard::Down;
    mKeyAssociation[static_cast<size_t>(GameKey::moveLeft)] = sf::Keyboard::Left;
    mKeyAssociation[static_cast<size_t>(GameKey::moveRight)] = sf::Keyboard::Right;
}

GameKeyMap::GameKeyMap(const std::string& fileName)
{

}

GameKeyMap::~GameKeyMap()
{

}

sf::Keyboard::Key GameKeyMap::operator[](const GameKey& key)
{
    return mKeyAssociation[static_cast<size_t>(key)];
}

void GameKeyMap::setAssociation(const GameKey& gameKey, const sf::Keyboard::Key& key)
{
    mKeyAssociation[static_cast<size_t>(gameKey)] = key;
}


}
