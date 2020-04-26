#!/bin/bash

file=$1

function clean() {
  # remove if exists
  if [ -f $file ] ; then
    rm $file
  fi
}

# handle ctrl+c signal
trap clean SIGINT

# compile
cc -o $file -w $file.c ./libs/*.c

# remove first argument (filename)
shift

# run with rest of argument
./$file $@

# clear after finish exicution
clean
