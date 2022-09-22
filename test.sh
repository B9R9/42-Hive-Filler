#!/bin/bash

ME=briffard.filler
PLAYER=abanlin
STRMAP=MAP02
P2=$ME
P1=$PLAYER
P1SCORE=504
P2SCORE=504

        # P1SCORE=$(grep "O fin" $PWD/SCORE/$PLAYER/$STRMAP.result | cut  -d' '  -f 4)
        # P2SCORE=$(grep "X fin" $PWD/SCORE/$PLAYER/$STRMAP.result | cut  -d' '  -f 4)
        # echo -e "GAME $i     P1: $P1 $P1SCORE VS $P2SCORE P2: $P2" >> $PWD/SCORE/$PLAYER/$STRMAP.trace
        if [ "$P2SCORE" -le "$P1SCORE" ];then
		    if [ "$P1" == "$ME" ]; then
                MYWIN=$(( $MYWIN + 1 ))
            fi
		    if [ "$P1" == "$PLAYER" ]; then
                ENEMYWIN=$(( $ENEMYWIN + 1 ))
            fi
        elif [ "$P1SCORE" -le "$P2SCORE" ];then
		    if [ "$P2" == "$ME" ]; then
                MYWIN=$(( $MYWIN + 1 ))
            fi
		    if [ "$P2" == "$PLAYER" ]; then
                MYWIN=$(( $MYWIN + 1 ))
            fi
        fi

        echo -e " ME: $MYWIN    OPP:$ENEMYWIN"


        #     if ( "$P1SCORE" < "$P2SCORE" );then
		#     ENEMYWIN=$(( $ENEMYWIN + 1 ))
        #     fi
        # elif ( "$P2SCORE" < "$P1SCORE" && "$P1" == "$PLAYER" ); then
		#     ENEMYWIN=$(( $ENEMYWIN + 1 ))
        # else
        #     MYWIN=$(( $MYWIN + 1 ))
        # fi