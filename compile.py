import json
import subprocess

# Load the config.json file
with open("config.json", "r") as config_file:
    config = json.load(config_file)

# Define the source and header files
source_files = ['src/build.cpp', 'src/test.cpp', 'src/deploy.cpp', 'src/main.cpp']
header_files = ['include/build.h', 'include/test.h', 'include/deploy.h']
output_file = 'ocelot_ci_cd'

# Define the compiler and flags
compiler = 'g++'
compiler_flags = '-std=c++11 -Iinclude -Ithird_party -o'

# Construct the compile command
compile_command = f"{compiler} {compiler_flags} {output_file} {' '.join(source_files)}"

# Execute the compile command
try:
    print(f"Compiling C++ files with command: {compile_command}")
    subprocess.run(compile_command, check=True, shell=True)
    print(f"Compilation successful, output file: {output_file}")
except subprocess.CalledProcessError as e:
    print(f"Compilation failed with error: {e}")
