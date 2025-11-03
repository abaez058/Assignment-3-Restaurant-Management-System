/*
 * copyString()
 * 
 * OBJECTIVE: Copy a string from source to destination using ONLY pointer arithmetic
 *            No use of string.h functions (strcpy, strncpy, etc.) allowed
 * 
 * PARAMETERS:
 * - dest: pointer to destination buffer (char*)
 * - src: pointer to source string (const char*)
 * 
 * RETURNS: void
 * 
 * REQUIREMENTS:
 * - Use pointer arithmetic only (no array indexing)
 * - Copy character by character until null terminator
 * - Ensure destination string is properly null-terminated
 * - Implement input validation for safety
 * - Handle edge cases appropriately
 * 
 * POINTER CONCEPTS:
 * - Pointer dereferencing (*ptr) to access character values
 * - Pointer increment (ptr++) to move through string
 * - Null terminator ('\0') detection and handling
 * 
 * SAFETY CONCEPTS:
 * - NULL pointer validation before processing
 * - Proper handling of edge cases
 */

#include "restaurant.h"

void copyString(char* dest, const char* src) {
    
    // TODO: Implement string copying using pointer arithmetic only
    
    // 1. INPUT VALIDATION:
          if(dest == NULL || src == NULL){
             return;
          }

    // 2. CHARACTER-BY-CHARACTER COPYING:
          while (*src != '\0') {
            *dest = *src; 
            src++;
            dest++;
        }
    // 3. NULL TERMINATION:
        *dest = '\0';
}