#include <stdio.h>
#include <stdlib.h>
#include "../include/linear_search.h"
#include "../include/visualizer.h"
#include "../include/utils.h"

void linearSearch(void) {
    drawHeader("Linear Search Visualization");
    
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
    drawArray(arr, size, -1, "Starting Linear Search");
    sleep_ms(1);
    
    char message[100];
    snprintf(message, sizeof(message), "Searching for value: %d", target);
    drawHeader(message);
    
    // Linear Search with visualization
    int found = 0;
    for (int i = 0; i < size; i++) {
        // Show current element being checked
        snprintf(message, sizeof(message), "Checking element at index %d", i);
        drawArrayWithComparison(arr, size, i, -1, message);
        sleep_ms(1);
        
        if (arr[i] == target) {
            snprintf(message, sizeof(message), "Found %d at index %d!", target, i);
            drawArray(arr, size, i, message);
            sleep_ms(1);
            found = 1;
            break;
        }
        
        // Show progress
        drawStep(i + 1, size, "Search Progress");
    }
    
    if (!found) {
        snprintf(message, sizeof(message), "Value %d not found in the array", target);
        drawArray(arr, size, -1, message);
    }
    
    drawFooter(found ? "Search Complete - Value Found!" : "Search Complete - Value Not Found!");
    
    // Clean up
    free(arr);
} 