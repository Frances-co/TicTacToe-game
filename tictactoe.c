#include <stdio.h>
#include <stdlib.h>

void instructions();
void printBoard(char board[9]);
void updateBoard(char board[9]);
int isPositionTaken(int x, char board[9]);
int checkWin(char board[9]);



int main() {
    instructions();
    char board[9]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}; //The board is empty at the beginning, so each position is an empty space.
    printBoard(board);

    int maxTurns= 9;
    int playerInput;
    while (maxTurns--) {
        if (maxTurns % 2 == 0)
            printf("Player 1 turn: ");
        else
            printf("Player 2 turn: ");

        int validMove = 0;  // Flag to check if a valid move has been made
        do {
            // Read player input
            scanf("%d", &playerInput);

            // Process the input through a switch
            switch (playerInput) {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                    if (!isPositionTaken(playerInput, board)) {
                        if (maxTurns % 2 == 0)
                            board[playerInput - 1] = 'X';  // Player 1 move
                        else
                            board[playerInput - 1] = 'O';  // Player 2 move

                        validMove = 1;  // Valid move made, exit the loop
                    } else {
                        printf("Position already taken, try again.\n");
                    }
                    break;

                default:
                    printf("Invalid input, please enter a number between 1 and 9.\n");
                    break;
            }
        } while (!validMove);  // Repeat until a valid move is made

        // Update the board after a valid move
        updateBoard(board);
        if(maxTurns <= 5){
            if(checkWin(board)== 1){
                printf("Player 1 Wins!");
                break;
            }
            else if(checkWin(board)== 2){
                printf("Player 2 Wins!");
                break;
            }
            else if(maxTurns==0){
                printf("Tie!");
                break;
            }
        }
    }
    return 0;
}

//Initialize Board:
void printBoard(char board[9]){
    int boardIndex=0;
    int innerWhileIterator= 3;
    int outerWhileIterator= 3;
    while(outerWhileIterator--){
        while(innerWhileIterator--){
            printf("%c", board[boardIndex]);

            if(innerWhileIterator!=0)
                printf(" | ");

            boardIndex++;
    }
    if(outerWhileIterator!=0)
        printf("\n--+---+--\n");

    innerWhileIterator= 3;
    }
    printf("\n\n");
}

//instructions:
void instructions(){
    printf("Welcome to the TicTacToe game.\n\nEach player chooses a number from 1 to 9 to indicate which box they want to mark.\n\nPress any key to continue.\n");
    getchar();
    system("cls");
}

//Is the position taken already?
int isPositionTaken(int x, char board[9]){
    if (board[x-1]!=' ') return 1;
    return 0;
}

void updateBoard(char board[9]){
    system("cls");
    printBoard(board);
}

int checkWin(char board[9]) {
    // Array of winning triplets
    int winningTriplets[8][3] = {
        {0, 1, 2},  // 1 2 3
        {0, 3, 6},  // 1 4 7
        {3, 4, 5},  // 4 5 6
        {6, 7, 8},  // 7 8 9
        {1, 3, 7},  // 2 4 8
        {2, 5, 8},  // 3 6 9
        {0, 4, 8},  // 1 5 9
        {2, 4, 6}   // 3 5 7
    };

    // Loop over each triplet and check if the player has filled any
    for (int i = 0; i < 8; i++) {
        int a = winningTriplets[i][0];
        int b = winningTriplets[i][1];
        int c = winningTriplets[i][2];

        // Check if all three positions have the same non-empty value
        if (board[a] == board[b] && board[b] == board[c] && board[a] != ' ') {
            int winner= board[a]=='X' ? 1 : 2;
            return winner;
        }
    }

    return 0;  // Return 0 if no winning condition is found
}

