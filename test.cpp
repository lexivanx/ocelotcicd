#include "test.h"
#include <iostream>
#include <cstdlib>

bool executeCommand(const std::string &command) {
    int result = std::system(command.c_str());
    return result == 0;
}

bool runTests(const std::string &testCommand) {
    std::cout << "Running tests with command: " << testCommand << std::endl;
    return executeCommand(testCommand);
}
