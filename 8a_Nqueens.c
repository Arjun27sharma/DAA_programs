#include <stdio.h>
#include <stdbool.h>

#define MAX_N 10

bool isSafe(int row, int col, char board[][MAX_N], int n) {
    int duprow = row;
    int dupcol = col;

    while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q') {
            return false;
        }
        row--;
        col--;
    }

    row = duprow;
    col = dupcol;
    while (col >= 0) {
        if (board[row][col] == 'Q') {
            return false;
        }
        col--;
    }

    row = duprow;
    col = dupcol;
    while (row < n && col >= 0) {
        if (board[row][col] == 'Q') {
            return false;
        }
        row++;
        col--;
    }

    return true;
}

void solve(int col, char board[][MAX_N], int n) {
    if (col == n) {
        // Print the board
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';

            solve(col + 1, board, n);
            board[row][col] = '.';
        }
    }
}

void solveNqueens(int n) {
    char board[MAX_N][MAX_N];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = '.';
        }
    }

    solve(0, board, n);
}

int main() {
    int n;
    printf("Enter the number of queens (n): ");
    scanf("%d", &n);

    solveNqueens(n);

    return 0;
}
