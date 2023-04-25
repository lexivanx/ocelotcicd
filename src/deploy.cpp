#include "deploy.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <thread>
#include <mutex>

// Mutex for synchronizing log messages
std::mutex log_mutex;

// Log a message to the console, taking care of mutex synchronization
// to avoid garbled log messages when logging from multiple threads
void logMessage(const std::string &message) {
    std::unique_lock<std::mutex> lock(log_mutex);
    std::cout << message << std::endl;
}

// Execute a command and return true if the command is successful (exit code is 0)
// Log the command execution and any errors that occur
bool executeCommand(const std::string &command) {
    logMessage("Executing command: " + command);
    int result = std::system(command.c_str());

    if (result != 0) {
        logMessage("Error: Command '" + command + "' failed with error code " + std::to_string(result));
    }

    return result == 0;
}

// Deploy the project using a list of deploy commands and return true if all deployments are successful
bool deployProject(const std::vector<std::string> &deployCommands) {
    bool deploymentSuccess = true;
    for (const auto &deployCommand : deployCommands) {
        logMessage("Deploying project with command: " + deployCommand);

        if (!executeCommand(deployCommand)) {
            deploymentSuccess = false;
        }
    }
    return deploymentSuccess;
}
