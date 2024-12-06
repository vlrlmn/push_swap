# Push Swap Project

## Overview
The "Push Swap" project is part of the 42 school's algorithmic curriculum that challenges students to sort numbers into ascending order using two stacks. The main goal is to sort the data with a limited set of instructions, using the smallest number of actions possible.

***Visual representation of how 5000 elements was sorted with my algorithm***
![Vizualizer](https://github.com/vlrlmn/push_swap/blob/main/images/vizualizer-ezgif.com-video-to-gif-converter.gif)

## Description
This project involves creating two programs: 
- `push_swap`: which calculates the instructions required to sort the stack of integers.
- `checker`: which takes integer arguments and reads instructions on the standard input. Once read, `checker` executes them and determines if the integers are sorted.

### Push_swap
The `push_swap` program outputs a series of operations that sort the numbers received as arguments. For example:

```bash
./push_swap 2 1 3 6 5 8
```
might output:

```bash
ra
pb
ra
ra
pa
```

### Checker
The checker program reads instructions from the standard input and executes them on the stacks initialized with the integers passed as arguments. It then displays OK if integers are sorted, otherwise KO.

```bash
./checker 2 1 3 6 5 8
```
### Usage

1. Clone the repository:
```bash
git clone https://github.com/vlrlmn/push_swap.git
```
2. Compile the programs:
```bash
make
```

3.Run push_swap:
```bash
./push_swap 2 1 3 6 5 8
```

4. Test with checker:
```bash
./checker 2 1 3 6 5 8
```

### Score and Evaluation

The score of this project is primarily based on the efficiency of the sorting algorithm implemented. The fewer operations push_swap generates to successfully sort the array, the higher the score awarded. Striving for optimization is crucial to achieving a high score in this project.

