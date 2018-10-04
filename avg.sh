ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`
./push_swap $ARG > a
./checker $ARG < a
wc -l < a
