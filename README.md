# ocelotcicd
Lightweight CI/CD tool

## CLI

The `ocelate.py` script uses `argparse` to define the 'build' command with the '--cpp' option. The `build()` function will be called when the 'build' command is executed. Currently, the script only supports building C++ projects with the `compile.py` script.

1. Make the script executable
        chmod +x ocelate.py
2. Create a symlink to the `ocelate.py` script in a directory that is part of your PATH environment variable, like:
        ln -s /path/to/your/ocelate.py /usr/local/bin/ocelate
    2.1 Replace /path/to/your/ocelate.py with the actual path to the ocelate.py file.
3. Now you can use the CLI, for example:
        ocelate build --cpp
    3.1 This command will execute the build function in the ocelate.py script, which in turn calls the compile.py script to compile the C++ files.