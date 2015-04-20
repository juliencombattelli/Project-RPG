#ifndef GAMEKEYSTATEMANAGER_HPP_INCLUDED
#define GAMEKEYSTATEMANAGER_HPP_INCLUDED

#include <SFML\System\Clock.hpp>
#include <SFML\Window\Keyboard.hpp>
#include <cstdint>

namespace rpg
{

class GameKeyStateManager
{
public:

	GameKeyStateManager() = delete;
	GameKeyStateManager(sf::Keyboard::Key key);
	GameKeyStateManager(const GameKeyStateManager&) = delete;
	GameKeyStateManager& operator=(const GameKeyStateManager&) = delete;
	~GameKeyStateManager();

	void update();

	bool isPressed() const { return m_keyPressed; }
	bool isPressedOnce() const { return m_keyPressedOnce; }
	bool isPressedCont() const { return m_keyPressedCont; }

private:

	sf::Keyboard::Key m_key;

    bool m_keyPressed;
	bool m_keyPressedOnce;
	bool m_keyPressedCont;

    enum : int8_t {keyNoPressed, keyPressed, keyContPressed} m_state;

	sf::Clock m_timer;
};

}

#endif //GAMEKEYSTATEMANAGER_HPP_INCLUDED
