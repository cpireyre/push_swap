ARG=`ruby -e "puts (1..4).to_a.shuffle.join(' ')"`
echo $ARG
./push_swap $ARG | ./checker $ARG
