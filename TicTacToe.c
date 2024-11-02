#include <stdio.h>
#include <stdlib.h>

char board[3][3];

void initBoard();
void printBoard();
int getEmptySpaces();
void playerMove();
void computerMove();
char checkWinner();

int main(){
    char winner = ' ';
    initBoard();

    while(winner == ' ' && getEmptySpaces() > 0){
        printBoard();
        playerMove();
        computerMove();
        checkWinner();

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
    } while(board[row-1][col-1] != ' ');

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
    char winner = ' ';    

    return winner;
}