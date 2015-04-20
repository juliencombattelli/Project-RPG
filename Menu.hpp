#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include "State.hpp"

namespace rpg
{

class Menu : public State
{
public:
    Menu(Application* app);
    virtual ~Menu();

    virtual void checkEvents();
    virtual void update();
    virtual void draw();
};

}

#endif // MENU_HPP_INCLUDED
