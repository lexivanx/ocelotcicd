#include <iostream>
#include <cstdlib>
#include "build.h"
#include "test.h"
#include "deploy.h"

int main() {
    // Build project
    std::string buildCommand = "make";
    if (buildProject(buildCommand)) {
        std::cout << "Build successful!" << std::endl;
    } else {
        std::cout << "Build failed!" << std::endl;
        return 1;
    }

    // Run tests
    std::string testCommand = "./run_tests";
    if (runTests(testCommand)) {
        std::cout << "All tests passed!" << std::endl;
    } else {
        std::cout << "Tests failed!" << std::endl;
        return 1;
    }

    // Deploy project
    std::string deployCommand = "scp build/project user@server:/var/www";
    if (deployProject(deployCommand)) {
        std::cout << "Deployment successful!" << std::endl;
    } else {
        std::cout << "Deployment failed!" << std::endl;
        return 1;
    }

    return 0;
}
