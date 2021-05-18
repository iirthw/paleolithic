#!/bin/bash

clear

if [ ! -d build ]
then
    mkdir build
fi

cd build

# Currently the script supports only the macOS and Windows
if [[ $OSTYPE == "darwin"* ]]; then
    # Mac OSX
    cmake -G Xcode ..
elif [[ $OSTYPE == "msys" ]]; then # for Git bash on Windows
    cmake -G "Visual Studio 16 2019" ..
else
    echo "[ERROR] Only OSX and Windows are supported\n"
    cd ..
    exit 1
fi

# go back to the original directory
cd ..