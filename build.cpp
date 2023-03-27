#include "build.h"
#include <iostream>
#include <cstdlib>

bool executeCommand(const std::string &command) {
    int result = std::system(command.c_str());
    return result == 0;
}

bool buildProject(const std::string &buildCommand) {
    std::cout << "Building project with command: " << buildCommand << std::endl;
    return executeCommand(buildCommand);
}