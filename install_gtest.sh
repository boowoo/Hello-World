#!/bin/bash

# filename: install_gtest.sh
# description:
#   installing google test library
#   for Hello-World project by boowoo
# usage:  cd ~(boowoo-project)
#         ./install_gtest.sh

if [ ! -d ./thirdparty/gtest ]; then
  wget http://googletest.googlecode.com/files/gtest-1.6.0.zip
  unzip gtest-1.6.0.zip
  rm gtest-1.6.0.zip
  mkdir thirdparty
  mv gtest-1.6.0 thirdparty/gtest
  cd thirdparty/gtest
  ./configure
  make
  cd
else
  echo "google test already installed"
fi
