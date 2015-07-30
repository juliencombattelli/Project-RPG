#include "GameKeyState.hpp"

namespace rpg
{

GameKeyState::GameKeyState(sf::Keyboard::Key key) :
m_key(key), m_keyPressed(false), m_keyPressedOnce(false), m_keyPressedCont(false), m_state(keyNoPressed)
{

}

GameKeyState::~GameKeyState()
{

}

void GameKeyState::update()
{
	m_keyPressedOnce = false;
	m_keyPressedCont = false;

	const bool isKeyPressed = sf::Keyboard::isKeyPressed(m_key);

	m_keyPressed = isKeyPressed;

	switch (m_state)
	{
		case keyNoPressed:
		{
			if (isKeyPressed)
			{
				m_keyPressedOnce = true;
				m_keyPressedCont = true;
				m_timer.restart();

				m_state = keyPressed;
			}
		}
		break;

		case keyPressed:
		{
			if (isKeyPressed and (m_timer.getElapsedTime().asMilliseconds() >= 1000))
			{
				m_keyPressedCont = true;
				m_keyPressedOnce = false;

				m_timer.restart();

				m_state = keyContPressed;
			}
			else if (not isKeyPressed)
			{
				m_keyPressedOnce = false;
				m_keyPressedCont = false;

				m_state = keyNoPressed;
			}
		}
		break;

		case keyContPressed:
		{
			if (not isKeyPressed)
			{
				m_keyPressedOnce = false;
				m_keyPressedCont = false;

				m_state = keyNoPressed;
			}
			else if(isKeyPressed and (m_timer.getElapsedTime().asMilliseconds() >= 50))
            {
                m_keyPressedOnce = false;
				m_keyPressedCont = true;

				m_timer.restart();

				m_state = keyContPressed;
            }
		}
		break;

		default:
        {
            m_keyPressedOnce = false;
            m_keyPressedCont = false;
            m_state = keyContPressed;
        }
	}
}

}
