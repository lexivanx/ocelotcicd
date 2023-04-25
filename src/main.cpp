#include <iostream>
#include <cstdlib>
#include <fstream>
#include "build.h"
#include "test.h"
#include "deploy.h"
#include "json.hpp" // Include the nlohmann/json header

using json = nlohmann::json;

int main() {
    // Read the config.json file
    std::ifstream configFile("config.json");
    json config;
    configFile >> config;

    // Retrieve build, test, and deploy commands from the JSON configuration
    std::vector<std::string> buildCommands = config["buildCommands"].get<std::vector<std::string>>();
    std::vector<std::string> testCommands = config["testCommands"].get<std::vector<std::string>>();
    std::vector<std::string> deployCommands = config["deployCommands"].get<std::vector<std::string>>();

    // Call the buildProject, runTests, and deployProject functions with the new command vectors
    if (buildProject(buildCommands)) {
        std::cout << "Build succeeded" << std::endl;

        if (runTests(testCommands)) {
            std::cout << "Tests succeeded" << std::endl;

            if (deployProject(deployCommands)) {
                std::cout << "Deployment succeeded" << std::endl;
            } else {
                std::cout << "Deployment failed" << std::endl;
                return 1;
            }
        } else {
            std::cout << "Tests failed" << std::endl;
            return 1;
        }
    } else {
        std::cout << "Build failed" << std::endl;
        return 1;
    }

    return 0;
}
