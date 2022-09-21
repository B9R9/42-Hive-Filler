#!/bin/bash

PLAYER=$1
GAME=$2
ME=briffard.filler
VM=./resources/filler_vm
TRACE=./filler.trace
MAPS=$(find ./resources/maps/*)
i=1
ENEMYWIN=0
MYWIN=0

mkdir -p /Users/briffard/Desktop/filler/SCORE/$PLAYER
for MAP in $MAPS
do
    rm -f /Users/briffard/Desktop/filler/SCORE/trash.txt
    STRMAP=$(echo $MAP |  cut -d '/' -f 4)
    while [ $i -le $GAME ]
    do
        if [ "$(( $i % 2 ))" -eq "0" ]; then
            echo -e "IN $STRMAP MATCH $i P1 $ME vs $PLAYER P2 ..."
            $VM -f $MAP -p1 ./$ME -p2 ./resources/players/$PLAYER.filler -q > /Users/briffard/Desktop/filler/SCORE/trash.txt
        else
            echo -e "IN $STRMAP MATCH $i P1 $PLAYER vs $ME P2 ..."
            $VM -f $MAP -p1 ./resources/players/$PLAYER.filler  -p2 ./$ME -q > /Users/briffard/Desktop/filler/SCORE/trash.txt
        fi
        if (cat $TRACE | grep $ME ) then
		    MYWIN=$(( $MYWIN + 1 ))
	    fi
        if (cat $TRACE | grep $PLAYER ) then
		    ENEMYWIN=$(( $ENEMYWIN + 1 ))
	    fi
        i=$(( $i + 1 ))
    done
    i=1
    if [ ! -e "/Users/briffard/Desktop/filler/SCORE/$PLAYER/$STRMAP.trace" ]; then
        touch /Users/briffard/Desktop/filler/SCORE/$PLAYER/$STRMAP.trace
    fi
    let percent=$(((100*$MYWIN)/$GAME))
    echo -e "ON $STRMAP FOR $GAME game:" >> /Users/briffard/Desktop/filler/SCORE/$PLAYER/$STRMAP.trace 
    echo -e "---------------------------------------------------" >> /Users/briffard/Desktop/filler/SCORE/$PLAYER/$STRMAP.trace
    echo -e "PLAYER              |    %v   |    victory - game |" >> /Users/briffard/Desktop/filler/SCORE/$PLAYER/$STRMAP.trace  
    echo -e "--------------------------------------------------" >> /Users/briffard/Desktop/filler/SCORE/$PLAYER/$STRMAP.trace
    echo -e "$ME     |    "$percent%"    |       $MYWIN - $GAME   |" >> /Users/briffard/Desktop/filler/SCORE/$PLAYER/$STRMAP.trace
    echo -e "--------------------------------------------------" >> /Users/briffard/Desktop/filler/SCORE/$PLAYER/$STRMAP.trace 
    let percent=$(((100*$ENEMYWIN)/$GAME)) >> /Users/briffard/Desktop/filler/SCORE/$PLAYER/$STRMAP.trace 
    echo -e "$PLAYER               |   $percent%  |           $ENEMYWIN - $GAME   |" >> /Users/briffard/Desktop/filler/SCORE/$PLAYER/$STRMAP.trace 
    echo -e "--------------------------------------------------" >> /Users/briffard/Desktop/filler/SCORE/$PLAYER/$STRMAP.trace 
    echo -e "\n" >> /Users/briffard/Desktop/filler/SCORE/$PLAYER/$STRMAP.trace 
    ENEMYWIN=0
    MYWIN=0
done