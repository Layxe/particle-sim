/// ############################################################################
///
/// @author Alexander Niedermayer
/// @date 2023-08-12
///
/// ############################################################################

// Include files
/// ############################################################################

#include <iostream>

#include "SceneHandler.h"

// Defines
/// ############################################################################

#define SCENE_WIDTH  1280
#define SCENE_HEIGHT 720

// Functions and Procedures
/// ############################################################################

int main(int argc, char* argv[])
{
    SceneHandler* sceneHandler = new SceneHandler(SCENE_WIDTH, SCENE_HEIGHT);

    if (sceneHandler->Init() != 0) {
        std::cout << "Error initializing scene handler" << std::endl;
        return 1;
    }

    delete sceneHandler;

    return 0;
}