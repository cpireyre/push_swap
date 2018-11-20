# push_swap
One program to push and swap numbers on a list. One program to verify that the aforementioned list is sorted. Together they fight crime.
---
## Usage
echo "9 1 7 1337 3 6 5 2 42 777" > a && make && ./push_swap a | ./checker -v a
## What it's about
push_swap takes numbers as input. It then writes, on the standard output, a sequence of _instructions_ through which to sort them.
The constraints are thus: you start with all the numbers in one stack (call it **a**), and must sort everything using the **fewest** instructions. (Defined below). 
To do this, you can make use of an alternate stack referred to as **b**.

The allowed moves are:
* `sa`, swaps the two uppermost integers of **a**,
* `pa`, pushes the uppermost integer of **a** onto **b**,
* `ra`, rotates the **a** stack upwards, i.e. the first element becomes last and the second becomes first,
* `rra`, the opposite rotation;
* `sb`, which swaps on stack **b**,
* `pb`, pushes from **b** to **a**,
* `rb`,
* `rrb`;
* lastly, `ss`, `rr`, and `rrr` perform the corresponding operations on both stacks at once.
