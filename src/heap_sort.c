#include <stdio.h>
#include <stdlib.h>
#include "../include/heap_sort.h"
#include "../include/visualizer.h"
#include "../include/utils.h"

static int total_steps;
static int current_step;

static void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int* arr, int n, int i, int size) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    char message[100];
    
    // Show current node being heapified
    snprintf(message, sizeof(message), "Heapifying at index %d", i);
    drawArrayWithComparison(arr, size, i, -1, message);
    sleep_ms(1);
    
    // Compare with left child
    if (left < n) {
        snprintf(message, sizeof(message), "Comparing with left child: %d > %d ?", arr[left], arr[largest]);
        drawArrayWithComparison(arr, size, left, largest, message);
        sleep_ms(1);
        
        if (arr[left] > arr[largest])
            largest = left;
    }
    
    // Compare with right child
    if (right < n) {
        snprintf(message, sizeof(message), "Comparing with right child: %d > %d ?", arr[right], arr[largest]);
        drawArrayWithComparison(arr, size, right, largest, message);
        sleep_ms(1);
        
        if (arr[right] > arr[largest])
            largest = right;
    }
    
    // If largest is not root
    if (largest != i) {
        snprintf(message, sizeof(message), "Swapping %d with %d", arr[i], arr[largest]);
        drawArrayWithComparison(arr, size, i, largest, message);
        sleep_ms(1);
        
        swap(&arr[i], &arr[largest]);
        
        // Show after swap
        drawArray(arr, size, largest, "After swap");
        sleep_ms(1);
        
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest, size);
    }
}

void heapSort(void) {
    drawHeader("Heap Sort Visualization");
    
    // Get array from user
    int size;
    int* arr = arrManage(&size);
    if (!arr) return;
    
    // Calculate total steps
    total_steps = size * 2; // Building heap + extracting elements
    current_step = 0;
    
    printf("\nOriginal Array:\n");
    drawArray(arr, size, -1, "Initial state of the array");
    sleep_ms(1);
    
    // Build heap (rearrange array)
    drawHeader("Building Max Heap");
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i, size);
        current_step++;
        drawStep(current_step, total_steps, "Building Heap Progress");
    }
    
    // Extract elements from heap one by one
    drawHeader("Extracting Elements from Heap");
    for (int i = size - 1; i > 0; i--) {
        char message[100];
        snprintf(message, sizeof(message), "Moving root to end: %d", arr[0]);
        drawArrayWithComparison(arr, size, 0, i, message);
        sleep_ms(1);
        
        // Move current root to end
        swap(&arr[0], &arr[i]);
        
        // Show swap
        drawArray(arr, size, i, "After moving root to end");
        sleep_ms(1);
        
        // Heapify reduced heap
        heapify(arr, i, 0, size);
        
        current_step++;
        drawStep(current_step, total_steps, "Sorting Progress");
    }
    
    // Show final sorted array
    drawArray(arr, size, -1, "Final Sorted Array");
    drawFooter("Heap Sort Complete!");
    
    // Clean up
    free(arr);
} 