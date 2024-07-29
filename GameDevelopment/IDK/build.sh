#!/bin/bash

# Building the project like Handmade Hero taught
gcc ./src/main.c -lraylib -std=c99 -o ./bin/game
# -I./src/thirdparty/raylib/
# Compiling with raylib header file inside thirdparty directory

