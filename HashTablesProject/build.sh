#!/bin/bash

# Clear previous build
if [ -f main ] ; then
    rm main
  fi

# Build new version
cc hash_table.c\
  utils.c\
  hashing_methods.c\
  cli.c\
  main.c\
  -o main

printf "Build succeed.\n\n"

# Run build
./main