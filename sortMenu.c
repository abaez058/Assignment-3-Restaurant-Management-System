/*
 * sortMenu()
 * 
 * OBJECTIVE: Sort menu items using function pointer for comparison strategy
 *            Demonstrate advanced function pointer concepts with dynamic data selection
 * 
 * PARAMETERS:
 * - names[][MAX_NAME_LENGTH]: 2D array of item names
 * - categories[][MAX_CATEGORY_LENGTH]: 2D array of categories
 * - prices: 1D array of prices (float*)
 * - count: number of items to sort
 * - 💡compare: function pointer for comparison strategy
 * 
 * RETURNS: void (arrays are sorted in-place)
 * 
 * REQUIREMENTS:
 * - Sort all three arrays simultaneously to maintain data consistency
 * - 💡Use function pointer array to identify which comparison function was passed
 * - Dynamically select appropriate data (prices, names, or categories) for comparison
 * - Implement a sorting algorithm with loop safety protection
 * - Handle edge cases and invalid input appropriately
 * - Keep related data together across all arrays
 * 
 * 💡ADVANCED FUNCTION POINTER CONCEPTS:
 * - Function pointer identity comparison for strategy detection
 * - Function pointer arrays for mapping strategies to behaviors
 * - Dynamic data selection based on function pointer analysis
 * - Strategy pattern implementation with function pointers
 * 
 * SORTING CONCEPTS:
 * - Multi-array sorting maintaining data relationships
 * - In-place sorting algorithm implementation
 * - Comparison-based sorting logic
 * 
 * LOOP SAFETY CONCEPTS:
 * - Infinite loop protection using iteration counters
 * - Breaking out of nested loops when safety limits exceeded
 * - Maximum iteration limits for safety
 * 
 * 👍USE AVAILABLE COMPARISON FUNCTIONS (from driver):
 * - compareByName: sorts alphabetically by item name
 * - compareByPrice: sorts numerically by price (ascending)
 * - compareByCategory: sorts alphabetically by category
 * 
 * RELEVANT CONSTANTS:
 * - MAX_LOOP_ITERATIONS: Maximum allowed loop iterations for safety
 * - MAX_NAME_LENGTH, MAX_CATEGORY_LENGTH: For safe string operations
 */

#include "restaurant.h"
#include <string.h>

void sortMenu(char names[][MAX_NAME_LENGTH], 
              char categories[][MAX_CATEGORY_LENGTH],
              float* prices, int count, CompareFunction compare) {

    // 1. INPUT VALIDATION
    if (names == NULL || categories == NULL || prices == NULL || compare == NULL || count <= 1) {
        return; 
    }

    // 2. FUNCTION POINTER STRATEGY DETECTION
    CompareFunction strategies[] = {compareByName, compareByPrice, compareByCategory};
    int strategy = -1;
    for (int i = 0; i < 3; i++) {
        if (compare == strategies[i]) {
            strategy = i; 
            break;
        }
    }
    if (strategy == -1) return; 

    // 3. INITIALIZE LOOP SAFETY
    int iterations = 0;

    // 4. BUBBLE SORT IMPLEMENTATION WITH DYNAMIC DATA SELECTION
    for (int i = 0; i < count - 1 && iterations < MAX_LOOP_ITERATIONS; i++) {
        for (int j = 0; j < count - i - 1 && iterations < MAX_LOOP_ITERATIONS; j++) {
            int cmpResult = 0;

            switch (strategy) {
                case 0: 
                    cmpResult = compare(names[j], names[j + 1]);
                    break;
                case 1:
                    cmpResult = compare(&prices[j], &prices[j + 1]);
                    break;
                case 2: 
                    cmpResult = compare(categories[j], categories[j + 1]);
                    break;
            }

            if (cmpResult > 0) {
                
                char tempName[MAX_NAME_LENGTH];
                strncpy(tempName, names[j], MAX_NAME_LENGTH);
                strncpy(names[j], names[j + 1], MAX_NAME_LENGTH);
                strncpy(names[j + 1], tempName, MAX_NAME_LENGTH);

                char tempCat[MAX_CATEGORY_LENGTH];
                strncpy(tempCat, categories[j], MAX_CATEGORY_LENGTH);
                strncpy(categories[j], categories[j + 1], MAX_CATEGORY_LENGTH);
                strncpy(categories[j + 1], tempCat, MAX_CATEGORY_LENGTH);

                float tempPrice = prices[j];
                prices[j] = prices[j + 1];
                prices[j + 1] = tempPrice;
            }

            iterations++;
        }
    }
}