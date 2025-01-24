#include <stdio.h>
#include <stdlib.h>
#include "../include/shell_sort.h"
#include "../include/visualizer.h"
#include "../include/utils.h"

static int total_steps;
static int current_step;

void shellSort(void) {
    drawHeader("Shell Sort Visualization");
    
    // Get array from user
    int size;
    int* arr = arrManage(&size);
    if (!arr) return;
    
    // Calculate total steps (approximate)
    total_steps = size * 2;
    current_step = 0;
    
    printf("\nOriginal Array:\n");
    drawArray(arr, size, -1, "Initial state of the array");
    sleep_ms(1);
    
    // Start with a big gap, then reduce the gap
    for (int gap = size/2; gap > 0; gap /= 2) {
        char message[100];
        snprintf(message, sizeof(message), "Current gap size: %d", gap);
        drawHeader(message);
        sleep_ms(1);
        
        // Do a gapped insertion sort for this gap size
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            
            // Show current element being considered
            snprintf(message, sizeof(message), "Considering element %d at index %d", arr[i], i);
            drawArrayWithComparison(arr, size, i, -1, message);
            sleep_ms(1);
            
            // Shift earlier gap-sorted elements up until the correct location for arr[i] is found
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                snprintf(message, sizeof(message), "Comparing elements at gap %d: %d > %d ?", 
                         gap, arr[j - gap], temp);
                drawArrayWithComparison(arr, size, j, j - gap, message);
                sleep_ms(1);
                
                arr[j] = arr[j - gap];
                
                snprintf(message, sizeof(message), "Shifted element %d up by gap %d", 
                         arr[j], gap);
                drawArray(arr, size, j, message);
                sleep_ms(1);
                
                current_step++;
                drawStep(current_step, total_steps, "Sorting Progress");
            }
            
            // Place temp in its correct location
            arr[j] = temp;
            snprintf(message, sizeof(message), "Placed %d in its correct position", temp);
            drawArray(arr, size, j, message);
            sleep_ms(1);
        }
    }
    
    // Show final sorted array
    drawArray(arr, size, -1, "Final Sorted Array");
    drawFooter("Shell Sort Complete!");
    
    // Clean up
    free(arr);
} 