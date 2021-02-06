#!/bin/bash

# The command below would find the an executable in the build directory and execute it.
# maxdepth specified the number of directories to find recursively.
# -executable indicates to find an executable.
# -type f indicates to search files and not directories.
executables=$(find ./cmake_build/ -maxdepth 1 -type f -executable)

# for loop to execute more than one executable if found.
for executable in ${executables}
do
    ${executable}
done