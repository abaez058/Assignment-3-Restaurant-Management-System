/*
 * calculateSum()
 * 
 * OBJECTIVE: Calculate sum of all prices using pointer arithmetic
 *            Master pointer increment and dereferencing operations
 * 
 * PARAMETERS:
 * - prices: pointer to first element of price array (float*)
 * - count: number of prices in the array
 * 
 * RETURNS:
 * - Sum of all prices as float
 * - 0.0 if array is empty or invalid
 * 
 * REQUIREMENTS:
 * - Use pointer arithmetic for array traversal (not array indexing)
 * - Accumulate sum using pointer dereferencing
 * - Implement loop safety protection against infinite loops
 * - Handle edge cases appropriately
 * 
 * POINTER CONCEPTS:
 * - Pointer dereferencing (*ptr) to access values
 * - Pointer arithmetic (ptr++) to move between elements
 * - Array traversal without using subscript notation
 * 
 * LOOP SAFETY CONCEPTS:
 * - Infinite loop protection using iteration counters
 * - Breaking out of loops when safety limits exceeded
 * - Maximum iteration limits for safety
 * 
 * RELEVANT CONSTANTS:
 * - MAX_LOOP_ITERATIONS: Maximum allowed loop iterations for safety
 */

#include "restaurant.h"

float calculateSum(float* prices, int count) {
    
    // TODO: Calculate sum using pointer arithmetic with loop safety
    // 1. INPUT VALIDATION:
    if(prices == NULL || count <= 0){
        return 0.0;
    }

    // 2. INITIALIZE VARIABLES:
    float sum = 0.0;
    int iterations = 0;

    // 3. TRAVERSE ARRAY WITH POINTER ARITHMETIC:
    float* ptr = prices;
    while (count > 0 && iterations < MAX_LOOP_ITERATIONS) {
        sum += *ptr;    
        ptr++;          
        count--;        
        iterations++;   
    }

    // 4. RETURN RESULT:
    return sum;
}