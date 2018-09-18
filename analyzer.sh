# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    analyser.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroulin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/26 18:08:32 by aroulin           #+#    #+#              #
#    Updated: 2018/09/18 07:22:49 by cpireyre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

##
##		Need to have ./checker and ./push_swap.
##
##		First request is the range of numbers to be sorted, min to max.
##
##		Second request is the number of attempts the program will perform.
##
##		You may provide a median against which to compare your scores.


echo "\x1B[36m";
echo "\n--- [ ANALYZING PUSH_SWAP] ---";
echo "\x1B[0m";

read -p "Range of numbers? [from ... to] (At least two.) " NBRBOT NBRTOP
read -p "How many loops? " TRY
read -p "Median number of instructions? " MED
NBR=$(($NBRTOP - $NBRBOT))
((NBR++))
MOY=0;
MAX=-1;
MIN=-1;
ACTMAX="";
ACTMIN="";
MORE=0;
LESS=0;
IND=$TRY;
WELL=0;
TEST="";

printf "[ NBR == $NBR && TRY == $TRY && MED == $MED ]\n"

echo "Analysis in progress...\n\n";
while [ $IND -gt 0 ];
do
	ARG=`ruby -e "puts ($NBRBOT..$NBRTOP).to_a.shuffle.join(' ')"`
	NBRCOUP=$(./push_swap $ARG | wc -l);
	TEST=$(./push_swap $ARG | ./checker $ARG);
	if [ $TEST = "OK" ]
	then
		printf "\033[0;32m▓\033[0;0m"
		WELL=$(( $WELL + 1 ));
	else
		printf "a"
	fi;

	if [ $MAX -lt $NBRCOUP ]
	then 
		MAX=$NBRCOUP; 
		ACTMAX=$ARG; 
	fi;
	if [ $MIN -eq "-1" ];
	then 
		MIN=$NBRCOUP; 
		ACTMIN=$ARG; 
	fi;
	if [ $NBRCOUP -lt $MIN ]
	then MIN=$NBRCOUP; 
		ACTMIN=$ARG; 
	fi;
	MOY=$(( $MOY + $NBRCOUP ));
	IND=$(( $IND - 1 ));
	if [ $NBRCOUP -gt $MED ]
	then 
		((MORE++))
	else
		((LESS++))
	fi;
done;
MOY=$(( $MOY / $TRY ));
echo "\n\x1b[33m$WELL/$TRY\x1b[0m lists were sorted correctly."
echo "Of which, x1B[31m$MORE\x1b[0m longer than $MED."
echo "And x1B[32m$LESS\x1b[0m shorter than $MED."
echo "Longest sort:\x1B[31m$MAX\x1b[0m"
echo "Shortest sort:\t\x1b[33m$MOY\x1b[0m"
echo "Average sort::\x1B[32m$MIN\x1b[0m"
echo "Worst list:\t$ACTMAX"
echo "Best list:\t\t$ACTMIN"
