#!/bin/bash

# Clear previous build
if [ -f main ] ; then
    rm main
  fi

# Build new version
cc hash_table.c\
  prime.c\
  main.c\
  -o main

# Run build
./main