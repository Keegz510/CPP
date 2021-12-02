// PlayerProfiles.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "AppController.h"

int main()
{
    AppController::Init();
    AppController::Update();

    if(!AppController::hasQuit)
    {
        AppController::Quit();
    }
}
