#include <iostream>
#include <cstdlib>
#include "build.h"
#include "test.h"
#include "deploy.h"

int main() {
    std::string buildCommand = "g++ -std=c++11 main.cpp -o main";
    std::string testCommand = "./test";
    std::string deployCommand = "scp main user@host:/path/to/deploy";

    if (buildProject(buildCommand)) {
        std::cout << "Build succeeded" << std::endl;

        if (runTests(testCommand)) {
            std::cout << "Tests succeeded" << std::endl;

            if (deployProject(deployCommand)) {
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
