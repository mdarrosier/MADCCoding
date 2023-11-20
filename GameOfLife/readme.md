# Conway's Game of Life

## Rules (from wikipedia)
The universe of the Game of Life is an infinite, two-eimensional orthogonal grid of square cells, each of which is in one of two possible states,
live or dead (or populated and unpopulated, respectively).
Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent.
At each step in time, the following transitions occur:

- Any live cell with fewer than two live neighbours dies, as if by underpopulation.
- Any live cell with two or three live neighbours lives on to the next generation.
- Any live cell with more than three live neighbours dies, as if by overpopulation.
- Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction

The initial pattern constitutes the seed of the system.
The first generation is created by applying the above rules simultaneously to every cell in the seed, live or dead;
births and deaths occur simultaneously, and the discrete moment at which this happens is sometimes called a tick. 
[nb 1] Each generation is a pure function of the preceding one.
The rules continue to be applied repeatedly to create further generations.


## Things to improve once you/I get more familiar with C.

[ ] Use a stuct to keep cell's status and live neighbor count.
[ ] Implement using a Byte instead of array and have an 8x8 matrix? Reference bit to know if alive or dead.
[ ] Add a randomizer, Add predifined patterns to chose from.
[ ] Is there some sort of canvas we can leverage to rewrite the matrix instead of printing every state.
[ ] Create a header file and move logic also a makefile


