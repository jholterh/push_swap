# Push_swap

A sorting algorithm project that sorts a stack of integers using a limited set of operations, implementing the Turk Algorithm for optimal efficiency.

## Description

Push_swap is an algorithm project that challenges you to sort data on a stack with the smallest number of moves possible, using only specific stack operations. This implementation uses the Turk Algorithm for efficient sorting with minimal operations.

## The Challenge

Given a stack `a` containing random integers and an empty stack `b`, sort the integers in ascending order in stack `a` using the fewest operations possible.

## Available Operations

- `sa` - swap first 2 elements of stack a
- `sb` - swap first 2 elements of stack b
- `ss` - sa and sb at the same time
- `pa` - push first element of b to a
- `pb` - push first element of a to b
- `ra` - rotate stack a (shift up all elements by 1)
- `rb` - rotate stack b
- `rr` - ra and rb at the same time
- `rra` - reverse rotate stack a (shift down all elements by 1)
- `rrb` - reverse rotate stack b
- `rrr` - rra and rrb at the same time

## Turk Algorithm

The Turk Algorithm is an efficient sorting strategy that:
1. Pushes all elements except 3 to stack b
2. Sorts the remaining 3 elements in stack a
3. Calculates the optimal "cost" for each element in stack b to return to stack a
4. Moves elements back to stack a in the most efficient order
5. Performs final rotation to ensure ascending order

This approach minimizes the total number of operations required.

## Usage

```bash
make
./push_swap 4 67 3 87 23
```

The checker validates if the operations correctly sort the stack.

## Performance

- 3 numbers: max 3 operations
- 5 numbers: max 12 operations
- 100 numbers: < 700 operations (5 points), < 900 operations (4 points)
- 500 numbers: < 5500 operations (5 points), < 7000 operations (4 points)

## Examples

```bash
./push_swap 2 1 3 6 5 8
# Output: sa pb pb ra pa pa

./push_swap 0 9 1 8 2 7 3 6 4 5
# Outputs optimal sequence of operations
```

## Built With

- C
- Custom sorting algorithm (Turk Algorithm)
