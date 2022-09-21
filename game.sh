#!/bin/bash


rm -rf SCORE

./play_game.sh champely $1 &
./play_game.sh abanlin $1 &
./play_game.sh hcao $1 &
./play_game.sh grati $1 &
./play_game.sh superjeannot $1 &
./play_game.sh carli $1 &