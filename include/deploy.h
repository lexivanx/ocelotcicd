#pragma once

#include <string>
#include <vector>

// Deploy the project using a list of deploy commands and return true if all deployments are successful
bool deployProject(const std::vector<std::string> &deployCommands);
