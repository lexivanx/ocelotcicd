#include "deploy.h"
#include <iostream>
#include <cstdlib>

bool executeCommand(const std::string &command) {
    int result = std::system(command.c_str());
    return result == 0;
}

bool deployProject(const std::string &deployCommand) {
    std::cout << "Deploying project with command: " << deployCommand << std::endl;
    return executeCommand(deployCommand);
}
