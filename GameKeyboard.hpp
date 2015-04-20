#ifndef GAMEKEYBOARD_HPP_INCLUDED
#define GAMEKEYBOARD_HPP_INCLUDED

#include "GameKeyStateManager.hpp"
#include "GameKeyMap.hpp"
#include <SFML/Window/Keyboard.hpp>

namespace rpg
{

class GameKeyboard
{
public:

    GameKeyboard();
    GameKeyboard(const GameKeyboard&) = delete;
    GameKeyboard& operator=(const GameKeyboard&) = delete;
    ~GameKeyboard();

    void changeKeyCode(gameKey key, sf::Keyboard::Key newCode);

	void update();

	bool isPausePressed() const { return mPauseManager.isPressed(); }
	bool isPausePressedOnce() const { return mPauseManager.isPressedOnce(); }
	bool isPausePressedCont() const { return mPauseManager.isPressedCont(); }

private:

    GameKeyMap mGameKeyMap;

    GameKeyStateManager mPauseManager;
    GameKeyStateManager mAcceptManager;
	GameKeyStateManager mRefuseManager;
	GameKeyStateManager mMoveUpManager;
	GameKeyStateManager mMoveDownManager;
	GameKeyStateManager mMoveLeftManager;
	GameKeyStateManager mMoveRightManager;

};

}

#endif // GAMEKEYBOARD_HPP_INCLUDED
