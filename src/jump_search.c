#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/jump_search.h"
#include "../include/visualizer.h"
#include "../include/utils.h"

static int min(int a, int b) {
    return (a < b) ? a : b;
}

void jumpSearch(void) {
    drawHeader("Jump Search Visualization");
    
    // Get array from user
    int size;
    int* arr = arrManage(&size);
    if (!arr) return;
    
    // Get target value to search
    int target;
    printf("\nEnter the value to search for: ");
    scanf("%d", &target);
    getchar(); // Clear newline
    
    printf("\nOriginal Array:\n");
    drawArray(arr, size, -1, "Starting Jump Search");
    sleep_ms(1);
    
    char message[100];
    snprintf(message, sizeof(message), "Searching for value: %d", target);
    drawHeader(message);
    
    // Calculate jump step size
    int step = (int)sqrt(size);
    snprintf(message, sizeof(message), "Jump step size: %d", step);
    drawHeader(message);
    sleep_ms(1);
    
    // Finding the block where element is present (if it is present)
    int prev = 0;
    int current_step = 1;
    int total_steps = (size / step) + size % step;
    
    // Jump to next block as long as target is greater than value at next block
    while (prev < size && arr[prev] <= target) {
        snprintf(message, sizeof(message), "Checking block starting at index %d", prev);
        drawArrayWithComparison(arr, size, prev, min(prev + step, size - 1), message);
        sleep_ms(1);
        
        if (arr[prev] == target) {
            snprintf(message, sizeof(message), "Found %d at index %d!", target, prev);
            drawArray(arr, size, prev, message);
            drawFooter("Search Complete - Value Found!");
            free(arr);
            return;
        }
        
        if (arr[min(prev + step, size - 1)] >= target) {
            break;
        }
        
        prev += step;
        drawStep(current_step++, total_steps, "Jump Search Progress");
    }
    
    // Do linear search in the identified block
    snprintf(message, sizeof(message), "Performing linear search in block from index %d", prev);
    drawHeader(message);
    
    for (int i = prev; i < min(prev + step, size); i++) {
        snprintf(message, sizeof(message), "Checking element at index %d", i);
        drawArrayWithComparison(arr, size, i, -1, message);
        sleep_ms(1);
        
        if (arr[i] == target) {
            snprintf(message, sizeof(message), "Found %d at index %d!", target, i);
            drawArray(arr, size, i, message);
            drawFooter("Search Complete - Value Found!");
            free(arr);
            return;
        }
        
        drawStep(current_step++, total_steps, "Linear Search Progress");
    }
    
    // If element is not found
    snprintf(message, sizeof(message), "Value %d not found in the array", target);
    drawArray(arr, size, -1, message);
    drawFooter("Search Complete - Value Not Found!");
    
    // Clean up
    free(arr);
} 