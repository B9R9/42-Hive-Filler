#!/bin/bash

./resources/filler_vm -p1 ./$1 -p2 ./resources/players/$2 -f ./resources/maps/map0$3 | python3 vis.py
