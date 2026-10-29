*This project has been created as part of the 42 curriculum by besaipid and ealbespy.*

## Description

**push_swap** sorts a list of integers using two stacks, `a` and `b`, and a
limited set of operations. The program receives the numbers as arguments (the
first argument is the top of stack `a`) and prints on the standard output the
list of operations that sorts stack `a` in ascending order, with stack `b`
empty at the end. The goal is to use **as few operations as possible**.

| Operation | Effect |
|---|---|
| `sa` / `sb` / `ss` | swap the first two elements of `a` / `b` / both |
| `pa` / `pb` | take the top of `b` and put it on `a` / the top of `a` on `b` |
| `ra` / `rb` / `rr` | rotate `a` / `b` / both up: the first element becomes the last |
| `rra` / `rrb` / `rrr` | rotate `a` / `b` / both down: the last element becomes the first |

The program contains **four strategies**:

- **simple**, in O(n²): selection sort;
- **medium**, in O(n√n): chunk sort;
- **complex**, in O(n log n): 3-way quicksort;
- **adaptive** (default): measures the **disorder** of the input and chooses
  one of the three strategies above.

A **benchmark mode** (`--bench`) prints statistics about the sort, and, as a
bonus, a **`checker`** program verifies a list of operations.

## Instructions

### Compilation

```bash
make          # builds push_swap
make bonus    # builds checker
make clean    # removes the object files
make fclean   # removes the object files, push_swap and checker
make re       # fclean, then all
```

The project is compiled with `cc -Wall -Wextra -Werror`.

### Usage

```bash
./push_swap 2 1 3 6 5 8          # numbers as separate arguments
./push_swap "2 1 3 6 5 8"        # or as one string
./push_swap                      # no argument: prints nothing
./push_swap 1 2 3                # already sorted: prints nothing
```

Optional flags, placed **before** the numbers (one strategy flag and/or
`--bench`):

| Flag | Effect |
|---|---|
| `--adaptive` (default) | chooses the strategy from the disorder of the input |
| `--simple` | forces the O(n²) strategy |
| `--medium` | forces the O(n√n) strategy |
| `--complex` | forces the O(n log n) strategy |
| `--bench` | also prints statistics on the standard error |

```bash
./push_swap --complex 4 67 3 87 23
./push_swap --bench --medium 4 67 3 87 23
```

The operations are always printed on the standard output, one per line. With
`--bench`, the statistics are printed on the **standard error**, so both can be
separated:

```bash
ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')
./push_swap --bench $ARG 2> bench.txt | ./checker_linux $ARG    # OK
cat bench.txt
```

```
[bench] disorder: 48.74%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 5042
[bench] sa: 0 sb: 0 ss: 0 pa: 500 pb: 500
[bench] ra: 1898 rb: 1079 rr: 0 rra: 0 rrb: 1065 rrr: 0
```

In adaptive mode, the strategy line shows the complexity class of the method
that was actually used (here, 48.74% < 50%, so the medium strategy).

### Errors

`Error` followed by a newline is printed on the standard error when an argument
is not an integer, is outside the `int` range, or appears twice:

```bash
./push_swap 3 2 one 0       # Error
./push_swap 1 2 2           # Error
./push_swap "3 1 3"         # Error
./push_swap 2147483648      # Error
./push_swap ""              # Error
```

### Bonus: checker

`checker` takes the same arguments as `push_swap`, reads operations from the
standard input (one per line, each followed by `\n`), executes them, and
prints `OK` if stack `a` is sorted and stack `b` is empty, `KO` otherwise. It
prints `Error` on the standard error if an argument is invalid or if an
instruction does not exist or is badly formatted.

```bash
ARG="3 2 1 0"
./push_swap $ARG | ./checker $ARG          # OK
printf "sa\nrra\npb\n" | ./checker $ARG    # KO
```

## Project structure

| Folder / file | Content |
|---|---|
| `mains/main.c` | `push_swap` entry point and strategy selection |
| `parse/` | argument splitting and validation, flags, disorder computation |
| `moves/` | the 11 operations (`sa` … `rrr`) |
| `sort/` | the sorting strategies and their helpers |
| `bench.c` | the `--bench` output |
| `mains/bonus_main.c`, `bonus/` | the `checker` and its `get_next_line` |
| `includes/` | headers |

Each stack is a **singly linked list** (`t_list`): the head of the list is the
top of the stack. A `t_flags` structure stores the chosen strategy, the
disorder and the counter of each operation (used by `--bench`).

## Algorithms

### 1. Parsing and normalization

The arguments are split (one string or several arguments), checked (optional
sign followed by digits only, inside the `int` range, no duplicates) and stored
in a linked list in the same order.

The medium and complex strategies first replace each value by its **rank**:
the smallest value becomes `0`, the next one `1`, …, the largest `n - 1`. The
order of the elements does not change, but the values become the contiguous
range `0 .. n-1`. This makes it possible to split the values into exact groups
(chunks, thirds) without searching for a median.

### 2. Disorder

The disorder is the proportion of **pairs of elements that are in the wrong
order** (inversions):

```
disorder = number of pairs (i, j) with i before j and value(i) > value(j)
           ---------------------------------------------------------------
                          total number of pairs = n(n-1)/2
```

A sorted list has a disorder of 0, a reversed list 1, and a random list about
0.5. It is stored multiplied by 10000, so that `--bench` can print it with two
decimals without floating-point numbers. Computing it takes O(n²) comparisons
but **no stack operation**.

### 3. Strategy selection and thresholds

| Situation | Strategy |
|---|---|
| already sorted | nothing is printed |
| 5 numbers or fewer | small sort (whatever the flag) |
| disorder < 0.2 | simple, O(n²) |
| 0.2 ≤ disorder < 0.5 | medium, O(n√n) |
| disorder ≥ 0.5 | complex, O(n log n) |

The thresholds 0.2 and 0.5 are the regimes defined by the subject. They match
how each method behaves:

- **Low disorder (< 0.2)**: most numbers are already close to their final
  position, so the minimum of `a` is usually close to the top and the
  rotations of the selection sort stay short (for example, 386 operations for
  100 numbers with a disorder of 8.8%). The method is also the simplest one,
  and cannot fail on a nearly sorted input.
- **Medium disorder (0.2 to 0.5)**: the chunk sort only needs the numbers to be
  roughly in the right region. Its cost depends on the size of the chunks, not
  on the exact order, and it is very efficient on this kind of input.
- **High disorder (≥ 0.5)**: the input is close to random (or reversed), so a
  method whose cost does not depend on the order is needed: the quicksort
  always splits the values into exact thirds.

### 4. Small sort (5 numbers or fewer)

- 2 numbers: `sa` if needed.
- 3 numbers: each of the 6 possible orders is solved directly with at most two
  operations (`sa`, `ra`, `rra`).
- 4 or 5 numbers: the minimum is brought to the top with the shortest rotation
  and pushed to `b` until 3 numbers are left; these 3 are sorted as above,
  then the numbers in `b` are pushed back with `pa`.

All the possible orders of 5 numbers are sorted in **10 operations or fewer**.

### 5. Simple strategy: selection sort, O(n²)

Repeat until `a` is empty: find the minimum of `a`, bring it to the top with
the shortest rotation (`ra` if it is in the first half, `rra` otherwise), and
push it to `b` with `pb`. Then push everything back with `pa`: the numbers come
back in ascending order.

- **Time**: when `a` contains m numbers, bringing its minimum to the top costs
  at most m/2 rotations. In total: at most n²/4 rotations, plus n `pb` and n
  `pa`, so **O(n²)** operations.
- **Space**: O(1) besides the two stacks.

### 6. Medium strategy: chunk sort, O(n√n)

After normalization, the numbers are sent to `b` through a **sliding window**
of `k = 1.4 × √n` ranks (14 for 100 numbers, 30 for 500). `pushed` is the
number of elements already in `b`.

- **Push phase**: for the number on top of `a`:
  - if its rank is ≤ `pushed`, it is pushed with `pb` and sent to the bottom of
    `b` with `rb`;
  - if its rank is ≤ `pushed + k`, it is pushed with `pb` and stays on top of
    `b`;
  - otherwise, `a` is rotated with `ra`.

  Each push moves the window one rank further. The smallest ranks go to the
  bottom of `b` and the largest ones stay near the top, so `b` is roughly
  sorted.
- **Pull phase**: the maximum of `b` is found, brought to the top with the
  shortest rotation (`rb` or `rrb`), and pushed back with `pa`. The numbers
  come back to `a` from the largest to the smallest.

Complexity:

- **Time**: during one full rotation of `a`, every number whose rank is inside
  the window is pushed, so the window moves by about k ranks per rotation.
  There are at most about n/k full rotations of at most n operations each, so
  the push phase costs O(n²/k) = O(n√n). Since `b` is built window by window,
  the maximum of `b` is always within about k positions of one of its ends,
  so the pull phase costs O(n·k) = O(n√n). In total: **O(n√n)** operations.
- **Space**: O(n) for the temporary array used to compute the ranks (freed
  right after), O(1) during the sort.

The factor 1.4 is a compromise measured on random inputs: smaller chunks cost
more `ra` in the push phase, bigger chunks leave `b` less sorted and cost more
rotations in the pull phase.

### 7. Complex strategy: 3-way quicksort, O(n log n)

The idea of a quicksort is to split the numbers into groups around a pivot,
then to sort each group the same way. Here, each group is split into **three
thirds** (small, medium, large) instead of two halves. With two stacks, there
are **four places** where numbers can be stored and taken back: the top of `a`
(TA), the bottom of `a` (BA), the top of `b` (TB) and the bottom of `b` (BB).
Three of them are always free to receive the three thirds, so a group is split
into three in a single pass.

The main function is `sort_chunk(place, lo, n)`: it sorts the n numbers of
ranks `lo .. lo+n-1` found at `place`, and leaves them **sorted on top of
`a`**. The final result is built from the top of `a`, from the largest numbers
to the smallest: each finished group is placed on top of the previous one.

1. **Split**: with `third = lo + n/3` and `two = lo + 2n/3`, each of the n
   numbers is read at its place and sent to a destination according to its
   class:

   | Read from | Large (≥ two) | Medium | Small (< third) |
   |---|---|---|---|
   | TA | `ra` → BA | `pb` → TB | `pb rb` → BB |
   | BA | `rra` → TA | `rra pb` → TB | `rra pb rb` → BB |
   | TB | `pa` → TA | `pa ra` → BA | `rb` → BB |
   | BB | `rrb pa` → TA | `rrb pa ra` → BA | `rrb` → TB |

   A number is never sent back to the place being read. Large numbers go to
   `a`, small numbers go to `b`, and medium numbers take the remaining place.
2. **Recursion**: `sort_chunk` is called on the large third, then the medium
   one, then the small one. The large numbers must be finished first because
   they end up at the bottom of the sorted block.
3. **Small groups** (3 numbers or fewer) are brought to the top of `a` and
   sorted there, without ever moving the already sorted numbers below (for
   example `pb sa pa` to swap the 2nd and 3rd numbers).

Each group is fully described by its place, its first rank and its size. The
newest groups are always stored at the ends of the stacks, beyond the older
ones, and are finished before the older ones (like the recursion itself), so
the n numbers of a group are always the first n numbers reachable from its
place: they never have to be searched for.

Two shortcuts save operations:

- **`to_top`**: if a group is at the bottom of a stack that contains only this
  group, it is also at the top, and is treated as such (no useless `rra` /
  `rrb`).
- **`easy_sort`**: if the number reachable at the group's place is the largest
  of the group, it is moved directly to its final position on top of `a`.

Complexity:

- **Time**: the ranks make the split exact, so every group is divided into
  three thirds and there is no worst case (unlike a quicksort with a bad
  pivot). There are at most ⌈log₃ n⌉ levels of recursion, each number costs
  at most 3 operations per level (`rrb pa ra`), and a group of 3 numbers or
  fewer is sorted with a constant number of operations. In total: at most
  about 3·n·log₃(n) + O(n) operations, so **O(n log n)**.
- **Space**: O(n) for the temporary array used to compute the ranks (freed
  right after), and O(log n) for the recursion (about 6 nested calls for 500
  numbers). No other memory is allocated.

### 8. Measured performance

Over 100 random inputs for each case (all verified `OK` with `checker_linux`):

| Strategy | 100 numbers (average / max) | 500 numbers (average / max) |
|---|---|---|
| `--adaptive` (default) | 610 / **674** | 4652 / **5219** |
| `--medium` | 574 / 621 | 5056 / 5224 |
| `--complex` | 659 / 679 | 4362 / 4400 |
| `--simple` | 1454 / 1663 | not suited to random inputs |

The subject asks for fewer than 700 operations for 100 numbers and fewer than
5500 for 500 numbers for an excellent performance: the default mode stays below
both limits on every test.

### 9. Bonus: checker

The checker builds stack `a` with the same parsing as `push_swap`, then reads
the operations line by line with **get_next_line**. Each line is compared with
the 11 valid operations and applied with the same move functions as
`push_swap`, without printing them. Once the standard input is finished, it
prints the result and frees both stacks.

## Testing

`checker_linux` is provided with the subject.

```bash
# correctness and number of operations
ARG=$(shuf -i 0-9999 -n 100 | tr '\n' ' ')
./push_swap $ARG | ./checker_linux $ARG      # OK
./push_swap $ARG | wc -l                     # number of operations

# worst case over 50 random inputs of 500 numbers
for i in $(seq 50); do
	ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')
	echo "$(./push_swap $ARG | wc -l) $(./push_swap $ARG | ./checker_linux $ARG)"
done | sort -n | tail -1

# errors are written on the standard error only
./push_swap 1 2 a 2>/dev/null | wc -c        # 0

# memory
valgrind --leak-check=full ./push_swap $ARG > /dev/null

# norm
norminette includes mains moves parse sort bench.c bonus
```

## Contributions

Both learners worked on the whole project, reviewed each other's code and can
explain every part of it.

- **besaipid**: project structure and Makefile, argument parsing and
  validation (`ft_split`, error handling), flags parsing and the `t_flags`
  structure, the stack operations, the small sort (5 numbers or fewer), the
  simple strategy (selection sort), the benchmark output (`bench.c`), the
  adaptive selection, and the `checker` bonus with `get_next_line`.
- **ealbespy**: disorder computation, rank normalization, the medium strategy
  (chunk sort), the complex strategy (3-way quicksort), the `ss` / `rr` /
  `rrr` operations, the error and memory fixes norm fixes, and the
  tests and measurements of the number of operations.

## Resources

- The push_swap subject (42).
- `man 2 write`, `man 2 read`, `man 3 malloc`, `man 3 free`.
- Our own `get_next_line` project (42), reused for the checker.
- **AI usage**: AI (Claude) was used to write test scripts, to test our functions and measure the number 
  of operations on many random inputs. And to help write this README.
