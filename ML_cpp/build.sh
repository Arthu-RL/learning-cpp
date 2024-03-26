#!/bin/bash

# if you want debug a c++ code type "gbd ./bin/main" on terminal
# break or b: Set a breakpoint at a specified line or function.
# run or r: Start the program execution.
# next or n: Execute the next line of the program.
# step or s: Execute the next line, stepping into function calls.
# print or p: Print the value of a variable.
# backtrace or bt: Print a backtrace of the stack.
# quit or q: Exit gdb.

set -e

if [ ! -d ./bin ]; then
    mkdir ./bin
fi

# filesH=$(ls *.h)
# for file in $filesH; do
#     echo "Building $file..."
#     g++ -std=c++11 -g -Wall -Wextra $file -o "./bin/$(grep -E -o '[a-z|A-Z]+' <<< $file)"
# done

# filesCPP=$(ls *.cpp)
# for file in $filesCPP; do
#     echo "Building $file..."
#     g++ -std=c++11 -g -Wall -Wextra $file -o "./bin/learning_$(grep -E -o '[0-9]+' <<< $file)"
# done
g++ -std=c++14 -g -Wall -Wextra main.cpp -o "./bin/main"

echo ''
echo -e "Compilation \033[32mfinished\033[0m at $(date '+%A day %d at %H:%M:%S')"
echo ''
