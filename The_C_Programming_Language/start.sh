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
cc -o $file $file.c

# run
./$file

# clear after finish exicution
clean
