import subprocess

# Define source and header files
source_files = ['build.cpp', 'test.cpp', 'deploy.cpp', 'main.cpp']
header_files = ['build.h', 'test.h', 'deploy.h']
output_file = 'ocelot_ci_cd'

# Define compiler and flags
compiler = 'g++'
compiler_flags = '-std=c++11 -o'

# Construct compile command
compile_command = f"{compiler} {compiler_flags} {output_file} {' '.join(source_files)}"

# Execute compile command
try:
    print(f"Compiling C++ files with command: {compile_command}")
    subprocess.run(compile_command, check=True, shell=True)
    print(f"Compilation successful, output file: {output_file}")
except subprocess.CalledProcessError as e:
    print(f"Compilation failed with error: {e}")
