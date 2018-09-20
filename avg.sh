ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
./push_swap $ARG | ASAN_OPTIONS=debug=1 ./checker $ARG
