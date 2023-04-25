#!/usr/bin/env python3

import argparse
import json
import subprocess

def load_config():
    with open("config.json", "r") as config_file:
        return json.load(config_file)

def execute_ci_cd_tool(command):
    try:
        subprocess.run(f"./ci_cd_tool {command}", check=True, shell=True)
        print(f"{command.capitalize()} completed successfully")
    except subprocess.CalledProcessError as e:
        print(f"{command.capitalize()} failed with error: {e}")

def build(args):
    if args.cpp:
        config = load_config()
        for command in config["buildCommands"]:
            execute_ci_cd_tool(f"build {command}")
    else:
        print("No build option specified")

def test(args):
    config = load_config()
    for command in config["testCommands"]:
        execute_ci_cd_tool(f"test {command}")

def deploy(args):
    config = load_config()
    for command in config["deployCommands"]:
        execute_ci_cd_tool(f"deploy {command}")

def main():
    parser = argparse.ArgumentParser(description="Ocelate - Lightweight CI/CD tool CLI")
    subparsers = parser.add_subparsers()

    # Build command
    build_parser = subparsers.add_parser("build", help="Build the current directory")
    build_parser.add_argument("--cpp", action="store_true", help="Build C++ project")
    build_parser.set_defaults(func=build)

    # Test command
    test_parser = subparsers.add_parser("test", help="Test the current directory")
    test_parser.set_defaults(func=test)

    # Deploy command
    deploy_parser = subparsers.add_parser("deploy", help="Deploy the current directory")
    deploy_parser.set_defaults(func=deploy)

    args = parser.parse_args()
    if hasattr(args, "func"):
        args.func(args)
    else:
        parser.print_help()

if __name__ == "__main__":
    main()
