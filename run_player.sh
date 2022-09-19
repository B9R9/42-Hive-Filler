#!/bin/bash

compil()
{
	rm -f retour.txt
	#./resources/filler_vm -p1 ./briffard.filler -p2 ./resources/players/abanlin.filler -f ./resources/maps/map00
	#./resources/filler_vm -p2 ./briffard.filler -p1 ./resources/players/abanlin.filler -f ./resources/maps/map00 | python3 vis.py
	./resources/filler_vm2 -p2 ./briffard.filler -p1 ./resources/players/abanlin.filler -f ./resources/maps/map00 

}

name=$(find . -name "briffard.filler")

if [ ! -e $name ]; then
   echo -e "File no found!"
else
	compil
fi
