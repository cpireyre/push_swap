ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
./push_swap $ARG | ./checker $ARG
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`
./push_swap $ARG | ./checker $ARG
