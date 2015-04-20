#include "GameKeyboard.hpp"

namespace rpg
{

GameKeyboard::GameKeyboard() :
    mGameKeyMap(),
    mPauseManager(mGameKeyMap[gameKey::pause]),
    mAcceptManager(mGameKeyMap[gameKey::accept]),
	mRefuseManager(mGameKeyMap[gameKey::refuse]),
	mMoveUpManager(mGameKeyMap[gameKey::moveUp]),
	mMoveDownManager(mGameKeyMap[gameKey::moveDown]),
	mMoveLeftManager(mGameKeyMap[gameKey::moveLeft]),
	mMoveRightManager(mGameKeyMap[gameKey::moveRight])
{

}

GameKeyboard::~GameKeyboard()
{

}

void GameKeyboard::changeKeyCode(gameKey key, sf::Keyboard::Key newCode)
{
	mGameKeyMap.setAssociation(key, newCode);
}

void GameKeyboard::update()
{
    mPauseManager.update();
    mAcceptManager.update();
	mRefuseManager.update();
	mMoveUpManager.update();
	mMoveDownManager.update();
	mMoveLeftManager.update();
	mMoveRightManager.update();
}

}
