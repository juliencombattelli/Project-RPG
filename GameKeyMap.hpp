#ifndef GAMEKEYMAP_HPP_INCLUDED
#define GAMEKEYMAP_HPP_INCLUDED

#include "Type.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <string>
#include <array>

namespace rpg
{

class GameKeyMap
{
public:
    GameKeyMap(); // default keys association
    GameKeyMap(const std::string& fileName); // load keys association in fileName
    GameKeyMap(const GameKeyMap&) = delete;
    GameKeyMap& operator=(const GameKeyMap&) = delete;
    ~GameKeyMap();

    sf::Keyboard::Key operator[](const GameKey& key);// getter

    void setAssociation(const GameKey& gameKey, const sf::Keyboard::Key& key);

private:

    std::array<sf::Keyboard::Key, static_cast<size_t>(GameKey::count)> mKeyAssociation;
};

}

#endif // GAMEKEYMAP_HPP_INCLUDED
