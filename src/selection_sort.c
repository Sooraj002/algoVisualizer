#include <stdio.h>
#include <stdlib.h>
#include "../include/selection_sort.h"
#include "../include/visualizer.h"
#include "../include/utils.h"

void selectionSort(void) {
    drawHeader("Selection Sort Visualization");
    
    // Get array from user
    int size;
    int* arr = arrManage(&size);
    if (!arr) return;
    
    printf("\nOriginal Array:\n");
    drawArray(arr, size, -1, "Initial state of the array");
    sleep_ms(1);
    
    // Selection Sort with visualization
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        
        // Show current minimum
        drawArrayWithComparison(arr, size, i, min_idx, 
            "Finding minimum element in unsorted portion");
        sleep_ms(1);
        
        // Find minimum element in unsorted portion
        for (int j = i + 1; j < size; j++) {
            drawArrayWithComparison(arr, size, min_idx, j,
                "Comparing elements to find minimum");
            sleep_ms(1);
            
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
                drawArrayWithComparison(arr, size, i, min_idx,
                    "Found new minimum element");
                sleep_ms(1);
            }
        }
        
        // Swap elements if needed
        if (min_idx != i) {
            drawArrayWithComparison(arr, size, i, min_idx,
                "Swapping elements");
            sleep_ms(1);
            
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            
            drawArray(arr, size, i,
                "After swapping elements");
            sleep_ms(1);
        }
        
        // Show progress
        drawStep(i + 1, size - 1, "Sorting Progress");
        sleep_ms(1);
    }
    
    // Show final sorted array
    drawArray(arr, size, -1, "Final Sorted Array");
    drawFooter("Selection Sort Complete!");
    
    // Clean up
    free(arr);
} 