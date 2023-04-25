# ocelotcicd
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

## CLI

Update the commands in the arrays as needed for your specific project.

The `ocelate.py` script uses argparse to define the `build` command with the `--cpp` option. The build() function will be called when the `build` command is executed. Currently, the script only supports building C++ projects with the `compile.py` script.

1. Make the script executable

```
chmod +x ocelate.py
```

2. Create a symlink to the ocelate.py script in a directory that is part of your PATH environment variable, like:

```
ln -s /path/to/your/ocelate.py /usr/local/bin/ocelate
```

2.1 Replace `/path/to/your/ocelate.py` with the actual path to the ocelate.py file.

3. Now you can use the CLI, for example:

```
ocelate build --cpp
```

3.1 This command will execute the build function in the ocelate.py script, which in turn calls the `compile.py` script to compile the C++ files.

## Building, Testing, and Deploying

After configuring your `config.json` file, you can compile and run the Ocelot tool to build, test, and deploy your project:

```
g++ -std=c++11 -I./third_party src/main.cpp src/build.cpp src/test.cpp src/deploy.cpp -o main
./main
```

This command will compile the source files and create an executable named `main`. Running `./main` will execute the Ocelot tool, which will read the `config.json` file and perform the build, test, and deploy steps according to the specified commands.

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
