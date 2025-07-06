#include <stdio.h>

// Function to return maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve 0/1 Knapsack Problem
int knapsack(int weights[], int values[], int n, int capacity) {
    int dp[n+1][capacity+1];

    // Build table dp[][] in bottom up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i-1] <= w)
                dp[i][w] = max(values[i-1] + dp[i-1][w - weights[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    // Return the maximum value that can be put in the knapsack
    return dp[n][capacity];
}

int main() {
    int n, capacity;

    // User input
    printf("Enter number of items: ");
    scanf("%d", &n);

    int values[n], weights[n];

    printf("Enter the values and weights of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &values[i]);
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &weights[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    // Solve knapsack problem
    int maxProfit = knapsack(weights, values, n, capacity);

    printf("Maximum value that can be put in knapsack = %d\n", maxProfit);

    return 0;
}
