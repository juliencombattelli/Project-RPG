#ifndef GAMEKEYBOARD_HPP_INCLUDED
#define GAMEKEYBOARD_HPP_INCLUDED

#include "GameKeyState.hpp"
#include "GameDPad.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <array>

namespace rpg
{

class GameKeyboard
{
public:

    GameKeyboard();
    GameKeyboard(const GameKeyboard&) = delete;
    GameKeyboard& operator=(const GameKeyboard&) = delete;
    ~GameKeyboard();

    void changeKeyCode(GameKey key, sf::Keyboard::Key newCode);

	void update();

	bool isKeyPressed(const GameKey& gameKey) const { return mGameKeyState[static_cast<int>(gameKey)]->isPressed(); }
	bool isKeyPressedOnce(const GameKey& gameKey) const { return mGameKeyState[static_cast<int>(gameKey)]->isPressedOnce(); }
	bool isKeyPressedCont(const GameKey& gameKey) const { return mGameKeyState[static_cast<int>(gameKey)]->isPressedCont(); }

    GameDPad DPad;

private:

    std::array<GameKeyState*, static_cast<uint32_t>(GameKey::count)> mGameKeyState;
};

extern GameKeyboard Keyboard;

}

#endif // GAMEKEYBOARD_HPP_INCLUDED
