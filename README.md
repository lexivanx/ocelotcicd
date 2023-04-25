# Ocelot CI/CD
Lightweight CI/CD tool

This CI/CD tool allows you to build, test, and deploy C++ projects using a simple command-line interface. The tool reads build, test, and deploy commands from a `config.json` file, making it easy to configure and customize the tool for different projects.

## Dependencies

- nlohmann/json library: A modern C++ library for working with JSON data. Download it from https://github.com/nlohmann/json/releases and include the single-header `json.hpp` in your project.

## Configuration

Create a `config.json` file at the root of your project with the following structure:

```json
{
  "buildCommands": ["g++ -std=c++11 main.cpp -o main"],
  "testCommands": ["./test"],
  "deployCommands": ["scp main user@host:/path/to/deploy"]
}
```

Update the commands in the arrays as needed for your specific project.

## CLI

The `ocelate.py` script provides a command-line interface (CLI) for Ocelot CI/CD. It uses `argparse` to define the 'build', 'test', and 'deploy' commands. The CLI reads the corresponding commands from the `config.json` file and executes them using the compiled tool (`ocelot_ci_cd`).

1. Make the script executable
        ```chmod +x ocelate.py```
2. Create a symlink to the `ocelate.py` script in a directory that is part of your PATH environment variable, like:
        ```ln -s /path/to/your/ocelate.py /usr/local/bin/ocelate```
    2.1 Replace /path/to/your/ocelate.py with the actual path to the ocelate.py file.
3. Now you can use the CLI, for example:
        ```ocelate build --cpp```
    3.1 This command will execute the build commands specified in the `config.json` file using the compiled tool (`ocelot_ci_cd`).
        ```ocelate test```
    3.2 This command will execute the test commands specified in the `config.json` file using the compiled tool (`ocelot_ci_cd`).
        ```ocelate deploy```
    3.3 This command will execute the deploy commands specified in the `config.json` file using the compiled tool (`ocelot_ci_cd`).

## Building, Testing, and Deploying

After configuring your `config.json` file, you can use the `compile.py` script to compile Ocelot CI/CD  and then run it to build, test, and deploy your project:

1. Compile Ocelot CI/CD tool using the `compile.py` script:
    ```
    python3 compile.py
    ```
    The `compile.py` script will load the `config.json` file, compile the source files with the appropriate flags, and create an executable named `ocelot_ci_cd`.

2. Run Ocelot CI/CD:
    ```
    ./ocelot_ci_cd
    ```
    Running `./ocelot_ci_cd` will execute the tool, which will read the `config.json` file and perform the build, test, and deploy steps according to the specified commands.

Remember to keep the `config.json` file in the same directory as the `ocelot_ci_cd` executable for the CI/CD tool to work properly.

## Customization

You can easily customize the build, test, and deployment process for your project by updating the commands in the `config.json` file. This allows you to use different compilers, test frameworks, or deployment methods without changing the source code.

## Troubleshooting

If you encounter any issues while using the Ocelot CI/CD tool, check the following:

1. Ensure that your `config.json` file is in the correct location (the root of your project) and has the correct structure.
2. Verify that the paths in your `config.json` file are correct and point to the appropriate files or directories.
3. Make sure that you have included the `nlohmann/json` library and specified the correct include path while compiling your project.

If you continue to have issues, consider checking the output messages during the build, test, and deploy stages for any errors or warnings that may help identify the problem.

## Contributing

If you'd like to contribute to this project, please feel free to open an issue or submit a pull request on the project's GitHub repository. We appreciate your help in improving and expanding the capabilities of the Ocelot CI/CD tool.

## License

This project is licensed under the Apache-2.0 license.
