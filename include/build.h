#pragma once

#include <string>
#include <vector>

// Log a message to the console
void logMessage(const std::string &message);

// Execute a command and return true if the command is successful (exit code is 0)
bool executeCommand(const std::string &command);

// Build the project by executing a list of build commands
// Optionally, build commands can be executed in parallel if parallelExecution is set to true
bool buildProject(const std::vector<std::string> &buildCommands, bool parallelExecution = false);
