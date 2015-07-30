#include "GameDPad.hpp"
#include "GameKeyboard.hpp"
#include <algorithm>
#include <iostream>

namespace rpg
{

GameDPad::GameDPad(GameKeyboard& keyboard) : m_keyboard(keyboard)
{
    m_DKeys[GameKey::moveUp]    = {false, false, 0};
    m_DKeys[GameKey::moveDown]  = {false, false, 0};
    m_DKeys[GameKey::moveLeft]  = {false, false, 0};
    m_DKeys[GameKey::moveRight] = {false, false, 0};
}

GameDPad::~GameDPad()
{

}

void GameDPad::update()
{
    m_DKeys[GameKey::moveUp].is_pressed = m_keyboard.isKeyPressed(GameKey::moveUp);
    m_DKeys[GameKey::moveDown].is_pressed = m_keyboard.isKeyPressed(GameKey::moveDown);
    m_DKeys[GameKey::moveLeft].is_pressed = m_keyboard.isKeyPressed(GameKey::moveLeft);
    m_DKeys[GameKey::moveRight].is_pressed = m_keyboard.isKeyPressed(GameKey::moveRight);

    for(std::map<GameKey, DKey_t>::iterator it=m_DKeys.begin() ; it!=m_DKeys.end() ; it++)
    {
        if(not it->second.was_pressed)
        {
            if(it->second.is_pressed)
            {
                it->second.was_pressed = true;
                it->second.priority = findHighestPriority()->second.priority +1 ;
            }
        }
        else
        {
            if(it->second.is_pressed)
            {

            }
            else
            {
                it->second.was_pressed = false;
                it->second.priority = 0;
            }
        }
    }

    adjustPriority();

    enableHighestPriorityKey();
}

std::map<GameKey, GameDPad::DKey_t>::iterator GameDPad::findHighestPriority()
{
    int highestPriority = 0;
    std::map<GameKey, DKey_t>::iterator itOnHighestPriority=m_DKeys.begin();

    for( std::map<GameKey, DKey_t>::iterator it=m_DKeys.begin() ; it!=m_DKeys.end() ; it++ )
    {
        if(it->second.priority > highestPriority)
        {
            highestPriority = it->second.priority;
            itOnHighestPriority = it;
            std::cout << highestPriority << std::endl;
        }
    }

    return itOnHighestPriority;
}

void GameDPad::enableHighestPriorityKey()
{
    for( std::map<GameKey, DKey_t>::iterator it=m_DKeys.begin() ; it!=m_DKeys.end() ; it++ )
        it->second.is_pressed = false;

    std::map<GameKey, DKey_t>::iterator element = findHighestPriority();

    if(element->second.priority != 0)
        element->second.is_pressed = true;
}

void GameDPad::adjustPriority()
{

}

}
