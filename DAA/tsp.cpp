#include <stdio.h> // Standard input-output library for printf and scanf functions
#include <math.h>

int arr[10][10], completed[10], cost = 0, n; // Define a 10x10 array for the cost matrix, a completed array to track visited cities, cost variable, and n for the number of cities

// Function to take user input for the number of cities and the cost matrix
void take_ip() {
    int i, j; // Loop counters
    printf("Enter number of Cities: ");
    scanf("%d", &n); // Get number of cities from user
    printf("\nEnter Cost Matrix \n");

    // Loop to input the cost matrix
    for (int i = 0; i < n; i++) {
        printf("\nEnter element of %d th row: \n", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]); // Get each element of the row from user
        }
        completed[i] = 0; // Initialize each city as not visited
    }
}

// Function to find the nearest unvisited city from a given city `c`
int least(int c) {
    int nc = 999, kmin, min = 999; // Initialize nearest city as a high value (999)

    // Loop through each city to find the minimum path cost
    for (int i = 0; i < n; i++) {
        // Check if the city is connected and unvisited
        if ((arr[c][i] != 0) && (completed[i] == 0)) {
            // Update minimum if a shorter path is found
            if (arr[c][i] + arr[i][c] < min) {
                min = arr[i][0] + arr[c][i]; // Update minimum distance
                kmin = arr[c][i]; // Update minimum cost
                nc = i; // Set nearest city to the current city index
            }
        }
    }

    // If a minimum path is found, add its cost to the total
    if (min != 999) {
        cost += kmin;
    }

    return nc; // Return the nearest city
}

// Recursive function to find the minimum cost path starting from a given city
void mincost(int city) {
    int ncity; // Variable to store the nearest city
    completed[city] = 1; // Mark the current city as visited
    printf("%d--->", city + 1); // Print the current city (1-based index)
    ncity = least(city); // Get the nearest city

    // If no nearest city is found (nc == 999), return to the starting city
    if (ncity == 999) {
        ncity = 0; // Set nearest city to the starting city
        printf("%d", ncity + 1); // Print the starting city

        cost += arr[city][ncity]; // Add the cost to return to the start
        return; // End the recursive function
    }
    mincost(ncity); // Recursive call with the nearest city
}

int main() {
    take_ip(); // Get user input
    mincost(0); // Start finding minimum cost path from city 0

    printf("\n\nMinicost is %d: ", cost); // Print the total minimum cost
}

