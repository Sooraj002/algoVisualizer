#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/quick_sort.h"
#include "../include/visualizer.h"
#include "../include/utils.h"

static int total_steps;
static int current_step;

static void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int low, int high, int size) {
    int pivot = arr[high];
    int i = low - 1;
    char message[100];
    
    // Show pivot selection
    snprintf(message, sizeof(message), "Selected pivot: %d", pivot);
    drawArrayWithComparison(arr, size, high, -1, message);
    sleep_ms(1);
    
    for (int j = low; j < high; j++) {
        current_step++;
        
        // Show comparison
        snprintf(message, sizeof(message), "Comparing %d with pivot %d", arr[j], pivot);
        drawArrayWithComparison(arr, size, j, high, message);
        sleep_ms(1);
        
        if (arr[j] <= pivot) {
            i++;
            if (i != j) {
                swap(&arr[i], &arr[j]);
                snprintf(message, sizeof(message), "Swapped %d and %d", arr[i], arr[j]);
                drawArray(arr, size, i, message);
                sleep_ms(1);
            }
        }
        drawStep(current_step, total_steps, "Partitioning Progress");
    }
    
    if (i + 1 != high) {
        swap(&arr[i + 1], &arr[high]);
        snprintf(message, sizeof(message), "Placing pivot in correct position");
        drawArray(arr, size, i + 1, message);
        sleep_ms(1);
    }
    
    return i + 1;
}

void quickSortRecursive(int* arr, int low, int high, int size) {
    if (low < high) {
        char message[100];
        
        // Show current subarray
        snprintf(message, sizeof(message), "Sorting subarray[%d-%d]", low, high);
        drawArrayWithComparison(arr, size, low, high, message);
        sleep_ms(1);
        
        int pi = partition(arr, low, high, size);
        
        // Show partitioned array
        snprintf(message, sizeof(message), "After partitioning: pivot at index %d", pi);
        drawArray(arr, size, pi, message);
        sleep_ms(1);
        
        quickSortRecursive(arr, low, pi - 1, size);
        quickSortRecursive(arr, pi + 1, high, size);
    }
}

void quickSort(void) {
    drawHeader("Quick Sort Visualization");
    
    // Get array from user
    int size;
    int* arr = arrManage(&size);
    if (!arr) return;
    
    // Calculate total steps (approximately)
    total_steps = size * (int)log2(size);
    current_step = 0;
    
    printf("\nOriginal Array:\n");
    drawArray(arr, size, -1, "Initial state of the array");
    sleep_ms(1);
    
    // Perform quick sort
    quickSortRecursive(arr, 0, size - 1, size);
    
    // Show final sorted array
    drawArray(arr, size, -1, "Final Sorted Array");
    drawFooter("Quick Sort Complete!");
    
    // Clean up
    free(arr);
}
