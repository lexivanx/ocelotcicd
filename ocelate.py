#!/usr/bin/env python3

import argparse
import subprocess

def build(args):
    if args.cpp:
        compile_command = "python compile.py"
        try:
            subprocess.run(compile_command, check=True, shell=True)
            print("C++ build completed successfully")
        except subprocess.CalledProcessError as e:
            print(f"Build failed with error: {e}")
    else:
        print("No build option specified")

def main():
    parser = argparse.ArgumentParser(description="Ocelate - Lightweight CI/CD tool")
    subparsers = parser.add_subparsers()

    # Build command
    build_parser = subparsers.add_parser("build", help="Build the current directory")
    build_parser.add_argument("--cpp", action="store_true", help="Build C++ project")
    build_parser.set_defaults(func=build)

    args = parser.parse_args()
    if hasattr(args, "func"):
        args.func(args)
    else:
        parser.print_help()

if __name__ == "__main__":
    main()
