#!/bin/bash
premake5 gmake
make config=debug -j$(nproc)
./bin/Debug-linux-x86_64/RacingGame/RacingGame
