#include <stdio.h>

// Function to find maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve knapsack problem
int knapsack(int capacity, int weights[], int values[], int n) {
    // Create and initialize dp array
    int dp[n+1][capacity+1];
    
    // Initialize first row and column to 0
    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= capacity; w++) {
            if(i == 0 || w == 0)
                dp[i][w] = 0;
        }
    }
    
    // Fill dp table
    for(int i = 1; i <= n; i++) {
        for(int w = 1; w <= capacity; w++) {
            if(weights[i-1] <= w) {
                dp[i][w] = max(values[i-1] + dp[i-1][w-weights[i-1]], 
                             dp[i-1][w]);
            }
            else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    return dp[n][capacity];
}

int main() {
    int n, capacity;
    
    // Input number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    // Declare arrays for weights and values
    int weights[n], values[n];
    
    // Input weights and values for each item
    printf("\nEnter details for %d items:\n", n);
    for(int i = 0; i < n; i++) {
        printf("\nFor item %d:\n", i+1);
        printf("Enter value: ");
        scanf("%d", &values[i]);
        printf("Enter weight: ");
        scanf("%d", &weights[i]);
    }
    
    // Input knapsack capacity
    printf("\nEnter the knapsack capacity: ");
    scanf("%d", &capacity);
    
    // Display entered data
    printf("\nItems entered:\n");
    printf("Item\tValue\tWeight\n");
    printf("------------------------\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", i+1, values[i], weights[i]);
    }
    printf("\nKnapsack capacity: %d\n", capacity);
    
    // Calculate and display result
    int maxValue = knapsack(capacity, weights, values, n);
    printf("\nMaximum value that can be obtained = %d\n", maxValue);
    
    return 0;
}