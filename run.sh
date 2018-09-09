ARG=`ruby -e "puts (1..20).to_a.shuffle.join(' ')"`
echo $ARG
./push_swap $ARG | ./checker -v $ARG
