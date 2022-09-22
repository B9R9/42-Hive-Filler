#!/bin/bash


        if ( "$P1" == "$PLAYER" ); then
            if ( "$P1SCORE" < "$P2SCORE" );then
		    ENEMYWIN=$(( $ENEMYWIN + 1 ))
        elif ( "$P2SCORE" < "$P1SCORE" && "$P1" == "$PLAYER" ); then
		    ENEMYWIN=$(( $ENEMYWIN + 1 ))
        else
            MYWIN=$(( $MYWIN + 1 ))
        fi


if [ "$(( $SCOREO < $SCOREX ))" ];then
    echo "P2 WIN"
elif ( "$SCOREX" < "$SCOREO" ); then
    echo "P1 WIN"
fi
