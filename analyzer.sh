# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    analyser.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroulin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/26 18:08:32 by aroulin           #+#    #+#              #
#    Updated: 2018/09/18 07:46:37 by cpireyre         ###   ########.fr        #
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


echo "\033[36m";
echo "\n--- [ ANALYZING PUSH_SWAP] ---";
echo "\033[0m";

read -p "Range of numbers? [from ... to] (At least two.) " NBRBOT NBRTOP
read -p "How many loops? " TRY
read -p "Median number of instructions? " MED
NBR=$(($NBRTOP - $NBRBOT))
NBR=$(( $NBR + 1 ));
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
		MORE=$(( $MORE + 1))
	else
		LESS=$(( $LESS + 1))
	fi;
done;
MOY=$(( $MOY / $TRY ));
echo "\n\033[33m$WELL/$TRY\033[0m lists were sorted correctly."
echo "Of which, \033[31m$MORE\033[0m longer than $MED."
echo "And \033[32m$LESS\033[0m shorter than $MED."
echo "Longest sort:\033[31m$MAX\033[0m"
echo "Average sort:\t\033[33m$MOY\033[0m"
echo "Shortest sort:\033[32m$MIN\033[0m"
echo "Worst list:\t$ACTMAX"
echo "Best list:\t\t$ACTMIN"
