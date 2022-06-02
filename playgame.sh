#!/bin/bash

echo "Create a new player [Y\n]"
read ANSWER
if [ $ANSWER = 'y' -o $ANSWER = 'Y' ];then
	echo "Player name: "
	read PLAYERNAME

	echo "Creation of $PLAYERNAME"
	gcc -o ./resources/players/$PLAYERNAME.filler  src/*.c  -L libft/ -lft -I includes/ -I libft/includes/
	if [ -e /home/chopper/workspace/Filler/myplayer/briffard.filler ]; then
		echo "Player created"
	else
		echo "Failure to create player"
		exit 1
	fi
fi
echo "List of player:"
i=1
for PLAYER in $(ls ~/workspace/Filler/resources/players/)
do
	if [[ $PLAYER != *"Zone"* ]]; then
		echo $i $PLAYER
		((i++))
	fi
done
echo "Select player 1: "
read P1
echo "Select player 2: "
read P2
i=1
for PLAYER in $(ls ~/workspace/Filler/resources/players/)
do
	if [[ $PLAYER != *"Zone"* ]]; then
		if [ $P1 == $i ]; then
			PLAYERP1=$PLAYER
		fi
		if [ $P2 == $i ]; then
			PLAYERP2=$PLAYER
		fi
		((i++))
	fi
done
echo  "Player 1 = $PLAYERP1"
echo "Player 2 = $PLAYERP2"
i=1
echo "Select your map: "
for MAP in  $(ls ~/workspace/Filler/resources/maps/)
do
	if [[ $MAP != *"Zone"* ]]; then
		echo $i $MAP
		((i++))
	fi
done
read CHOICEMAP
i=1
for MAP in  $(ls ~/workspace/Filler/resources/maps/)
do
	if [[ $MAP != *"Zone"* ]]; then
		if [ $CHOICEMAP == $i ]; then
			MYMAP=$MAP
		fi
		((i++))
	fi
done
echo $MYMAP
echo "Choose between VM(1) and VM2(2) :"; read CHOICEVM
if [ $CHOICEVM = 1 ];then
	VM=filler_vm
else
	VM=filler_vm2
fi
echo "Let's start the fight"
# PLAY music
./resources/$VM -p1 ./resources/players/$PLAYERP1 -p2./resources/players/$PLAYERP2 -f ./resources/maps/$MYMAP
