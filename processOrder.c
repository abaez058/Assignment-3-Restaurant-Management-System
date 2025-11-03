/*
 * processOrder()
 * 
 * OBJECTIVE: Calculate order totals and return multiple values through pointers
 *            Demonstrate returning multiple results from a single function
 * 
 * PARAMETERS:
 * - prices: array of menu item prices (float*)
 * - quantities: array of quantities ordered for each item (int*)
 * - menuSize: total number of items in menu
 * - subtotal: pointer to store calculated subtotal (float*)
 * - tax: pointer to store calculated tax amount (float*)
 * - total: pointer to store final total (float*)
 * 
 * RETURNS: void (results returned through pointer parameters)
 * 
 * REQUIREMENTS:
 * - Calculate subtotal from price and quantity data
 * - Calculate tax using the defined tax rate
 * - Calculate final total
 * - Store all results through pointer parameters
 * - Implement loop safety protection against infinite loops
 * - Handle edge cases and invalid input appropriately
 * 
 * POINTER CONCEPTS:
 * - Multiple return values using pointer parameters
 * - Pointer dereferencing for output assignment
 * - Working with input and output pointers simultaneously
 * 
 * LOOP SAFETY CONCEPTS:
 * - Infinite loop protection using iteration counters
 * - Breaking out of loops when safety limits exceeded
 * - Maximum iteration limits for safety
 * 
 * BUSINESS LOGIC CONCEPTS:
 * - Parallel array processing (prices and quantities)
 * - Conditional inclusion based on quantity values
 * - Multi-step calculation workflow
 * 
 * RELEVANT CONSTANTS:
 * - TAX_RATE: Tax percentage for calculation
 * - MAX_LOOP_ITERATIONS: Maximum allowed loop iterations for safety
 */

#include "restaurant.h"

void processOrder(float* prices, int* quantities, int menuSize,
                 float* subtotal, float* tax, float* total) {
    
    // TODO: Calculate order totals with loop safety protection
    // 1. INPUT VALIDATION:
    if (prices == NULL || quantities == NULL || subtotal == NULL ||
    tax == NULL || total == NULL || menuSize < 0) {

    if (subtotal) *subtotal = 0.0f;
    if (tax)      *tax = 0.0f;
    if (total)    *total = 0.0f;

    return; 
    }
                    
    // 2. INITIALIZE VARIABLES:
    float localSubtotal = 0.0f;
    int iterations = 0;
    // 3. CALCULATE SUBTOTAL WITH SAFETY:
        for (int i = 0; i < menuSize && iterations < MAX_LOOP_ITERATIONS; i++, iterations++) {
        if (quantities[i] > 0) {            
            localSubtotal += prices[i] * quantities[i]; 
        }
    }
    // 4. CALCULATE TAX AND TOTAL:
    float localTax = localSubtotal * TAX_RATE;
    float localTotal = localSubtotal + localTax;
    // 5. STORE RESULTS THROUGH POINTERS:
    *subtotal = localSubtotal;
    *tax = localTax;
    *total = localTotal;
}