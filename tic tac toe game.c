#include <stdio.h>
char board[3][3];
void initializeBoard() {
    char ch = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ch++;
        }
    }
}
void displayBoard() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}
int checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return 1;
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return 1;
    }
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return 1;
    return 0;
}
int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
        }
    }
    return 1;
}
void makeMove(char player, int choice) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;
    if (board[row][col] != 'X' && board[row][col] != 'O')
        board[row][col] = player;
    else
        printf("Invalid move! place already occupied.\n");
}
int main() {
    char playAgain;
    do {
        initializeBoard();
        char currentPlayer = 'X';
        int choice;
        while (1) {
            displayBoard();
            printf("Player %c, enter position (1-9): ", currentPlayer);
            scanf("%d", &choice);
            if (choice < 1 || choice > 9) {
                printf("Invalid position! Try it again.\n");
                continue;
            }
            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;

            if (board[row][col] == 'X' || board[row][col] == 'O') {
                printf("Position already taken! Try it again.\n");
                continue;
            }
            makeMove(currentPlayer, choice);
            if (checkWin()) {
                displayBoard();
                printf("Player %c wins!\n", currentPlayer);
                break;
            }
            if (checkDraw()) {
                displayBoard();
                printf("Game is draw!\n");
                break;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');
    printf("Game over!\n");
    return 0;
}
