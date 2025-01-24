#include <stdio.h>
#include <stdlib.h>
#include "../include/insertion_sort.h"
#include "../include/visualizer.h"
#include "../include/utils.h"

void insertionSort(void) {
    drawHeader("Insertion Sort Visualization");
    
    // Get array from user
    int size;
    int* arr = arrManage(&size);
    if (!arr) return;
    
    printf("\nOriginal Array:\n");
    drawArray(arr, size, -1, "Initial state of the array");
    sleep_ms(1);
    
    // Insertion Sort with visualization
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Show current element to be inserted
        drawArrayWithComparison(arr, size, i, -1, 
            "Current element to be inserted");
        sleep_ms(1);
        
        // Find the correct position and shift elements
        while (j >= 0 && arr[j] > key) {
            drawArrayWithComparison(arr, size, j, j+1,
                "Comparing and shifting elements");
            sleep_ms(1);
            
            arr[j + 1] = arr[j];
            drawArray(arr, size, j,
                "Shifted element right");
            sleep_ms(1);
            
            j--;
        }
        
        arr[j + 1] = key;
        drawArray(arr, size, j+1,
            "Inserted element in correct position");
        sleep_ms(1);
        
        // Show progress
        drawStep(i, size - 1, "Sorting Progress");
        sleep_ms(1);
    }
    
    // Show final sorted array
    drawArray(arr, size, -1, "Final Sorted Array");
    drawFooter("Insertion Sort Complete!");
    
    // Clean up
    free(arr);
} 