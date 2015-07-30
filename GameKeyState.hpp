#ifndef GAMEKEYSTATEMANAGER_HPP_INCLUDED
#define GAMEKEYSTATEMANAGER_HPP_INCLUDED

#include "Type.hpp"
#include <SFML\System\Clock.hpp>
#include <SFML\Window\Keyboard.hpp>
#include <cstdint>
#include <vector>

namespace rpg
{

class GameKeyState
{
public:

	GameKeyState() = delete;
	GameKeyState(sf::Keyboard::Key key);
	GameKeyState(const GameKeyState&) = delete;
	GameKeyState& operator=(const GameKeyState&) = delete;
	~GameKeyState();

	void update();

	void changeKeyCode(const sf::Keyboard::Key& new_key){ m_key = new_key; }

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
