#include <iostream>

#include "Application.hpp"

#include "GameKeyStateManager.hpp"

int main()
{
    int exitStatus = rpg::StatusNoError;

    rpg::Application* app = new rpg::Application();

    exitStatus = app->run();

    delete app;

    app = nullptr;

    return exitStatus;
}
