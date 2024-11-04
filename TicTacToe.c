#include <stdio.h>
#include <stdlib.h>

char board[3][3];

void initBoard();
void printBoard();
int getEmptySpaces();
void playerMove();
void computerMove();
char checkWinner();

char winner = ' ';

int main(){
    initBoard();

    while(winner == ' ' && getEmptySpaces() > 0){
        printBoard();
        playerMove();
        printBoard();
        computerMove();
        printBoard();
        checkWinner();
        if (winner != ' '){
            printf("the winner is %c\n", winner);
        }
    }

} 

void initBoard(){
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            board[i][j] = ' ';
        }
    }
}

void printBoard(){
    printf("*************\n");
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int getEmptySpaces(){
    int emptySpaces = 0;

    for (int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if (board[i][j] == ' '){
                emptySpaces++;
            }
        }
    }

    return emptySpaces;
}

void playerMove(){
    int row, col;
    do {
        printf("Enter row: ");
        scanf("%d", &row);
        printf("\nEnter col: ");
        scanf("%d", &col);
    } while(board[row-1][col-1] != ' ' && getEmptySpaces() > 0);

    board[row-1][col-1] = 'X';

}

void computerMove(){
    int row, col;
    do {
        row = (rand() % 3) + 1;
        col = (rand() % 3) + 1;
    } while (board[row][col] != ' ' && getEmptySpaces() > 0);
    
    if (getEmptySpaces() == 0){
        printf("No empty spaces");
        return;
    }

    board[row][col] = 'O';

}

char checkWinner(){
    //char winner = ' ';

    // Check if player won
    // Check rows
    int playerCount = 0;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (board[i][j] == 'X'){
                playerCount++;
            }
        }
        if (playerCount < 3){
            playerCount = 0;
        } else {
            winner = 'X';
            return winner;
        }
    }

    // Check cols
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (board[j][i] == 'X'){
                playerCount++;
            }
        }
        if (playerCount < 3){
            playerCount = 0;
        } else {
            winner = 'X';
            return winner;
        }
    }

    // Check diagonals
    if ((board[0][0] == 'X' && board[1][1] == 'X' &&  board[2][2] == 'X') || (board[0][2] == 'X' && board[1][1] == 'X' &&  board[2][0] == 'X')){
        winner = 'X';
        return winner;
    }


    // Check if computer won
    // Check rows
    int computerCount= 0;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (board[i][j] == 'O'){
                computerCount++;
            }
        }
        if (computerCount < 3){
            computerCount = 0;
        } else {
            winner = 'O';
            return winner;
        }
    }

    // Check cols
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (board[j][i] == 'O'){
                computerCount++;
            }
        }
        if (computerCount < 3){
            computerCount = 0;
        } else {
            winner = 'O';
            return winner;
        }
    }

    // Check diagonals
    if ((board[0][0] == 'O' && board[1][1] == 'O' &&  board[2][2] == 'O') || (board[0][2] == 'O' && board[1][1] == 'O' &&  board[2][0] == 'O')){
        winner = 'O';
        return winner;
    }


    return winner;
}