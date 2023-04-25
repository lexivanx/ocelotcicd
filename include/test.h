#pragma once

#include <string>
#include <vector>

// Run a list of test commands and return true if all tests are successful
bool runTests(const std::vector<std::string> &testCommands);
