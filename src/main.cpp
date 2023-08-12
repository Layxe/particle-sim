#include <iostream>

#include "SceneHandler.h"

int main(int argc, char* argv[])
{
    SceneHandler* sceneHandler = new SceneHandler(1280, 720);

    if (sceneHandler->Init() != 0) {
        std::cout << "Error initializing scene handler" << std::endl;
        return 1;
    }

    delete sceneHandler;

    return 0;
}