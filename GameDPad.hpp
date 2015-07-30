#ifndef GAMEDPAD_HPP_INCLUDED
#define GAMEDPAD_HPP_INCLUDED

#include "Type.hpp"
#include <map>

namespace rpg
{

class GameKeyboard;

class GameDPad
{
public:

    GameDPad(GameKeyboard& keyboard);
    GameDPad(const GameDPad&) = delete;
    GameDPad& operator=(const GameDPad&) = delete;
    ~GameDPad();

    void update();

    bool isMoveUpPressed() const { return m_DKeys.at(GameKey::moveUp).is_pressed; }
    bool isMoveDownPressed() const { return m_DKeys.at(GameKey::moveDown).is_pressed; }
    bool isMoveLeftPressed() const { return m_DKeys.at(GameKey::moveLeft).is_pressed; }
    bool isMoveRightPressed() const { return m_DKeys.at(GameKey::moveRight).is_pressed; }

private:

    struct DKey_t
    {
        bool was_pressed;
        bool is_pressed;
        int priority;
    };

    std::map<GameKey, DKey_t>::iterator findHighestPriority();
    void adjustPriority();
    void enableHighestPriorityKey();

    bool m_isMoveUpPressed;
    bool m_isMoveDownPressed;
    bool m_isMoveLeftPressed;
    bool m_isMoveRightPressed;

    std::map<GameKey, DKey_t> m_DKeys;
    GameKeyboard& m_keyboard;
};

}

#endif // GAMEDPAD_HPP_INCLUDED
