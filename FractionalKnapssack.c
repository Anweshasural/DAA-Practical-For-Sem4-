#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
typedef struct {
    int id;
    int value;
    int weight;
    double ratio; // Value-to-weight ratio
} Item;

// Comparison function for sorting items by ratio in descending order
int compareItems(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    if (itemA->ratio < itemB->ratio) return 1;
    if (itemA->ratio > itemB->ratio) return -1;
    return 0;
}

// Function to solve the Fractional Knapsack problem
double fractionalKnapsack(int capacity, Item items[], int n) {
    // Calculate value-to-weight ratio for each item
    for (int i = 0; i < n; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    // Sort items by ratio in descending order
    qsort(items, n, sizeof(Item), compareItems);

    double totalValue = 0.0;
    int currentWeight = 0;

    // Iterate through sorted items and add them to the knapsack
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // Take the whole item
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take a fraction of the item
            int remainingCapacity = capacity - currentWeight;
            totalValue += (double)remainingCapacity / items[i].weight * items[i].value;
            currentWeight = capacity; // Knapsack is now full
            break;
        }
    }
    return totalValue;
}

int main() {
    int capacity;
    int n;

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    printf("Enter number of items: ");
    scanf("%d", &n);

    Item items[n];
    for (int i = 0; i < n; i++) {
        items[i].id = i + 1;
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    double maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value in knapsack: %.2f\n", maxValue);

    return 0;
}