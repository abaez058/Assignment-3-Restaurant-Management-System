/*
 * addMenuItem()
 *  
 * OBJECTIVE: Add new menu item to arrays and update count using call-by-reference
 * 
 * PARAMETERS:
 * - names[][MAX_NAME_LENGTH]: 2D array to store item names
 * - categories[][MAX_CATEGORY_LENGTH]: 2D array to store categories  
 * - prices: 1D array to store prices (float*)
 * - count: pointer to current number of items (int*)
 * - name: name of new item to add (const char*)
 * - category: category of new item (const char*)
 * - price: price of new item (float)
 * 
 * RETURNS:
 * - OPERATION_SUCCESS (1) if item added successfully
 * - OPERATION_FAILURE (0) if operation failed
 * 
 * REQUIREMENTS:
 * - Implement safe string copying using strncpy() to prevent buffer overflow
 * - Validate all inputs before processing
 * - Use proper pointer dereferencing for count modification
 * - Ensure proper null termination of copied strings
 * 
 * STRING SAFETY CONCEPTS:
 * - Using strncpy() for bounded string copying
 * - Manual null termination after strncpy()
 * - Buffer overflow prevention with length limits
 * 
 * RELEVANT CONSTANTS:
 * - OPERATION_SUCCESS, OPERATION_FAILURE (return values)
 * - MAX_MENU_ITEMS (array capacity limit)
 * - MIN_PRICE, MAX_PRICE (price validation range)
 * - MAX_NAME_LENGTH, MAX_CATEGORY_LENGTH (string buffer limits)
 */

#include "restaurant.h"

int addMenuItem(char names[][MAX_NAME_LENGTH], 
               char categories[][MAX_CATEGORY_LENGTH],
               float* prices, int* count,
               const char* name, const char* category, float price) {
    
    // TODO: Implement addMenuItem with proper validation and string safety
    // 1. INPUT VALIDATION:
    if (names == NULL || categories == NULL || prices == NULL || count == NULL || 
    name == NULL || category == NULL) {
    return OPERATION_FAILURE;
    }

    if (name[0] == '\0' || category[0] == '\0') {
        return OPERATION_FAILURE;
    }
    // 2. CAPACITY AND PRICE VALIDATION:
    if (*count >= MAX_MENU_ITEMS) return OPERATION_FAILURE;
    if (price < MIN_PRICE || price > MAX_PRICE) return OPERATION_FAILURE;
    // 3. SAFE STRING COPYING:
    int index = *count;
    strncpy(names[index], name, MAX_NAME_LENGTH - 1);
    names[index][MAX_NAME_LENGTH - 1] = '\0';

    strncpy(categories[index], category, MAX_CATEGORY_LENGTH - 1);
    categories[index][MAX_CATEGORY_LENGTH - 1] = '\0';
    // 4. ADD PRICE AND UPDATE COUNT:
    prices[index] = price;  
    (*count)++;              
    return OPERATION_SUCCESS;
}