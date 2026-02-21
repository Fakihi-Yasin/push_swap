# push_swap

*This project has been created as part of the 42 curriculum by yafakihi.*

## Description

Push_swap is a sorting algorithm project that sorts a stack of integers using a limited set of operations. The goal is to sort stack A in ascending order using the minimum number of operations, with the help of an auxiliary stack B.

Available operations:
- `sa`, `sb`, `ss`: swap first two elements
- `pa`, `pb`: push from one stack to another
- `ra`, `rb`, `rr`: rotate stack up
- `rra`, `rrb`, `rrr`: rotate stack down

## Instructions

### Compilation

1. Place your `libft` in `./libft/` and build it:
```bash
cd libft && make && cd ..
```

2. Build push_swap:
```bash
make
```

### Usage

```bash
./push_swap [numbers]
```

Example:
```bash
./push_swap 3 2 1 5 4
```

The program outputs the list of operations to sort the stack.

### Testing

Copy the executable to the tester directory and run:
```bash
cp push_swap Push-Swap-Tester/
cd Push-Swap-Tester
bash push_swap_test.sh
```

## Resources

- [Push_swap subject (42 PDF)](https://cdn.intra.42.fr/pdf/pdf/960/push_swap.en.pdf)
- [Sorting algorithms visualization](https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html)
- AI usage: Amazon Q was used for debugging compilation errors, code structure suggestions.
