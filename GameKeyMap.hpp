#ifndef GAMEKEYMAP_HPP_INCLUDED
#define GAMEKEYMAP_HPP_INCLUDED

#include <SFML/Window/Keyboard.hpp>
#include <string>
#include <map>

namespace rpg
{

enum class gameKey : int8_t
{
	pause = 0,
	accept,
	refuse,
	moveUp,
	moveDown,
	moveLeft,
	moveRight,

	count
};

class GameKeyMap
{
public:
    GameKeyMap(); // default keys association
    GameKeyMap(const std::string& fileName); // load keys association in fileName
    GameKeyMap(const GameKeyMap&) = delete;
    GameKeyMap& operator=(const GameKeyMap&) = delete;
    ~GameKeyMap();

    sf::Keyboard::Key operator[](const gameKey& key);// getter

    void setAssociation(const gameKey& gamekey, const sf::Keyboard::Key& key);

private:
    std::map<gameKey, sf::Keyboard::Key> mGameKeysMap;
};

}

#endif // GAMEKEYMAP_HPP_INCLUDED
