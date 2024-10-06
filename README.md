# Tic Tac Toe Game

## Overview

This is a simple console-based Tic Tac Toe game written in C. The game allows two players to play against each other, taking turns marking positions on a 3x3 board. 
The first player to align three of their symbols (either 'X' or 'O') in a row, column, or diagonal wins the game. If the board is filled without any player meeting the winning condition, the game ends in a tie.

## How to Play

1. The game starts with an empty 3x3 board. Each player takes turns to mark a position on the board.
2. Player 1 will use the symbol 'X', while Player 2 will use the symbol 'O'.
3. To make a move, a player enters a number between 1 and 9 corresponding to the position they want to mark on the board:
   - `1`: Top-left
   - `2`: Top-center
   - `3`: Top-right
   - `4`: Middle-left
   - `5`: Center
   - `6`: Middle-right
   - `7`: Bottom-left
   - `8`: Bottom-center
   - `9`: Bottom-right
4. The game checks if the position is already taken or if the input is valid. If not, the player is prompted to make another choice.
5. The game will continue until one player wins or the board is full (resulting in a tie).

## Features

- **Turn-based gameplay:** Players alternate between turns to mark their symbol on the board.
- **Input validation:** The game checks whether the player's input is valid (between 1 and 9) and if the selected position is available.
- **Win detection:** The game checks for any winning condition after each move. If a player has aligned three symbols in a row, column, or diagonal, they win.
- **Tie condition:** If all positions are filled and no one wins, the game declares a tie.

## Board Representation

The game board is represented as follows:

```
 1 | 2 | 3
 --+---+--
 4 | 5 | 6
 --+---+--
 7 | 8 | 9
```

Players will input the number corresponding to the position they wish to mark.

## Instructions

1. When the game starts, you will be prompted with the instructions and asked to press any key to begin.
2. The board will be displayed after every valid move, showing the current state of the game.
3. The game will display a message declaring the winner, or if the game ends in a tie.

## Code Structure

- **`main()`**: Initializes the game and controls the game loop.
- **`instructions()`**: Displays the game's instructions at the start.
- **`printBoard()`**: Prints the current state of the Tic Tac Toe board.
- **`updateBoard()`**: Clears the screen and prints the updated board after each valid move.
- **`isPositionTaken()`**: Checks if a position on the board is already taken.
- **`checkWin()`**: Checks if any player has won by analyzing the board for winning patterns.

## Running the Game

1. Compile the code using any C compiler:
   ```
   gcc tic_tac_toe.c -o tic_tac_toe
   ```
2. Run the game:
   ```
   ./tic_tac_toe
   ```

Enjoy playing Tic Tac Toe!
