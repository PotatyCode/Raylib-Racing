#!/bin/bash
premake5 gmake
make config=debug -j$(nproc)
echo "compiled"
./bin/Debug-linux-x86_64/RacingGame/RacingGame
