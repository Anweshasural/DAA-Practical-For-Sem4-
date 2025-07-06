#include <stdio.h>
#include <stdlib.h>

#define MAX 20  // Maximum board size

int board[MAX]; // board[i] represents the column position of queen in row i
int count = 0;

// Function to check if placing queen at row and col is safe
int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

// Function to print the board configuration
void printBoard(int n) {
    count++;
    printf("Solution %d:\n", count);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

// Recursive function to solve N-Queens
void solveNQueens(int row, int n) {
    if (row == n) {
        printBoard(n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solveNQueens(row + 1, n);
        }
    }
}

int main() {
    int n;

    printf("Enter the number of queens (N): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid board size. N should be between 1 and %d.\n", MAX);
        return 1;
    }

    solveNQueens(0, n);

    if (count == 0)
        printf("No solutions exist for N = %d\n", n);
    else
        printf("Total Solutions: %d\n", count);

    return 0;
}
