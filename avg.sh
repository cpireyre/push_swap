ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
./push_swap $ARG > a
./checker $ARG < a
wc -l < a
