# Simple Sudoku Solver
A simple sudoku solver utilizing recursion with backtracking. 

> [!IMPORTANT]  
> This solver returns the *first solution* found. The current version does not handle cases in which multiple solutions exist.

## Authors
**Colton Cox:** ccox60@uco.edu



## Compilation Instructions
To compile the project, ensure you have a C++ compiler (e.g., `g++`) installed on your machine.
---

### Compilation Command (Windows)
A makefile is provided for g++ compilation with options for optimization:
Use `make` for standard compilation.

`make fast` adds the `-o1` tag which will optimize for speed.

`make faster` adds the `-o2` tag, further optimizing for speed.


## Execution Instructions (Windows)
To run the program after compilation, use the following syntax:
```bash
sudoku '{file}'
```
For running the program using the example puzzles provided, use
```bash
sudoku 'examples\{file}`
```


### Input File Format
The input file should contain 9 lines of 9 integer characters, separated by spaces

Example `puzzle.dat`:
```
6 8 0 1 0 0 0 9 0
0 3 4 5 0 8 0 2 0
2 1 0 7 6 0 3 0 0
5 0 0 4 0 7 0 0 9
3 4 2 9 0 0 0 0 6
0 0 7 6 8 0 5 0 0
9 2 0 8 0 0 0 5 3
0 0 3 2 0 0 9 1 8
0 0 0 3 0 0 0 6 7
```

Example files are included for easy, medium, and hard puzzles, as well as an unsolvable example

`easy.dat`
`medium.dat`
`hard.dat`
`expert.dat`
`extreme.dat`
`unsolvable.dat`

Unsolvable example from http://sudopedia.enjoysudoku.com/Test_Cases.html

Other example puzzles from https://sudoku.com/