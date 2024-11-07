#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int board[20], count;
void print(int n)
{
    printf("\n\nSolution: %d: \n\n", ++count);

    for (int i = 1; i <= n; i++)
    {
        printf("\t%d", i);
    }

    for (int i = 1; i <= n; i++)
    {   
        printf("\n\n%d",i);
        for (int j = 1; j <= n; j++)
        {
            if (board[i] == j)
            {
                printf("\tQ");
            }
            else
            {

                printf("\t-");
            }
        }
    }
}

int place(int row, int column)
{
    for (int i = 1; i <= row - 1; ++i)
    {
        // checking column and digonal conflicts
        if ((board[i] == column) || (abs(board[i] - column) == abs(i - row)))
            return 0;
    }

    return 1; // no conflicts
}

void queen(int row, int n) {
    for (int column = 1; column <= n; ++column) {  // Loop through each column in the current row
        if (place(row, column)) {                  // Check if placing queen at (row, column) is valid
            board[row] = column;                   // Place queen in this column for the current row
            
            if (row == n) {                        // If we have placed queens in all rows, we found a solution
                print(n);                          // Print the current solution
            } else {
                queen(row + 1, n);                 // Recur to place queen in the next row
            }
            // Here we return from the recursive call above, either due to success or a dead end
        }
        // If 'place' fails for all columns, we exit this loop, returning control to the previous row.
    }
    // If no column is valid in the current row, this function call ends, and we go back (backtrack) 
    // to the previous row, trying the next column in the previous recursive call.
}

int main()
{
    int n, i, j;
    void queen(int row, int n);//recursive backtracking algorithm
   
    printf("Enter number of queens: ");
    scanf("%d", &n);
    queen(1, n);
   
    
    return 0;
}
