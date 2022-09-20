#!/bin/bash

vm=./resources/filler_vm
me=./briffard.filler
players=$(find ./resources/players/*)
maps=$(find ./resources/maps/*)
trace=./filler.trace
i=1
game=5

for player in $players
do
   for map in $maps
    do
        while [ $i -le $game ]
        do
            if [ "$(( $i % 2 ))" -eq 0 ]; then
                $vm -f $map -p1 $me -p2 $player -q
            else
                $vm -f $map -p1 $player -p2 $me -q
            fi
            if (cat $trace | grep $me ); then
		        let MYWIN+=1
	        else
		        let ENEMYWIN+=1
	        fi
            i=$(( $i + 1 ))
        done
    i=1 
    let percent=(100*$MYWIN/$game)
    echo ON $map 
    echo $me: $percent% victory $MYWIN - $game
    let percent=(100*$ENEMYWIN/$game)
    echo $player: $percent% victory $ENEMYWIN - $game
    echo  -e "\n"
    done
done
