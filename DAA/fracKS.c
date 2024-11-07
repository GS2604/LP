#include <stdio.h>

struct Item {
    int value;
    int weight;
    float ratio;
};

/*
This function sorts the items based on their value-to-weight ratio 
in descending order using the bubble sort algorithm.

It loops through the items and compares their ratios.

If the ratio of the current item is less than the next item, it swaps them.
*/

void sortByRatio(struct Item items[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(items[j].ratio < items[j+1].ratio) {
                struct Item temp = items[j];
                items[j] = items[j+1];
                items[j+1] = temp;
            }
        }
    }
}

/*
This function calculates the maximum value that can be carried in the knapsack.
capacity: The maximum weight the knapsack can hold.
items[]: An array of items.
n: The number of items.
totalValue: A variable to keep track of the total value of items added to the knapsack.
currentWeight: A variable to keep track of the current weight of items in the knapsack.

*/
float fractionalKnapsack(int capacity, struct Item items[], int n) {
    float totalValue = 0.0;
    int currentWeight = 0;

    for(int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].value / items[i].weight;
    }
/*
This loop calculates the value-to-weight ratio for each item and 
 it in the ratio field of the Item structure.

*/
    sortByRatio(items, n);
/*
After calculating the ratios, we call the sortByRatio function to sort the items
 based on their ratios in descending order

*/
    for(int i = 0; i < n; i++) {
        if(currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        }
        else {
            int remainingWeight = capacity - currentWeight;
            totalValue += items[i].ratio * remainingWeight;
            break;
        }
    }
    return totalValue;
}


/*
This loop goes through the sorted items and adds them to the knapsack:
If adding the entire item does not exceed the capacity, it adds the item's weight and value to the knapsack.
If adding the entire item would exceed the capacity, it calculates how much of that item can be added 
(the remaining weight) and adds the corresponding value to the total.
The loop then breaks since the knapsack is full.

*/

int main() {
    int n, capacity;
    
    printf("Enter number of items: ");
    scanf("%d", &n);
    
    struct Item items[n];
    
    for(int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i+1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    
    printf("Enter capacity: ");
    scanf("%d", &capacity);
    
    printf("Maximum value: %.2f\n", fractionalKnapsack(capacity, items, n));
    
    return 0;
}