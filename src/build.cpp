#include "build.h"
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

// Build the project by executing a list of build commands
// Optionally, build commands can be executed in parallel if parallelExecution is set to true
bool buildProject(const std::vector<std::string> &buildCommands, bool parallelExecution = false) {
    if (parallelExecution) {
        // Use a vector to store the build threads
        std::vector<std::thread> buildThreads;
        // Flag to store the build success status
        bool buildSuccess = true;
        
        // Create a new thread for each build command, and execute it
        for (const auto &command : buildCommands) {
            buildThreads.push_back(std::thread([&buildSuccess, &command]() {
                bool result = executeCommand(command);
                if (!result) {
                    buildSuccess = false;
                }
            }));
        }
        
        // Wait for all threads to finish executing the build commands
        for (auto &thread : buildThreads) {
            thread.join();
        }

        // Return the overall build success status
        return buildSuccess;
    } else {
        // Execute build commands sequentially
        for (const auto &command : buildCommands) {
            if (!executeCommand(command)) {
                return false;
            }
        }
        return true;
    }
}
