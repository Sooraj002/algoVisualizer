#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/merge_sort.h"
#include "../include/visualizer.h"
#include "../include/utils.h"

static int total_steps;
static int current_step;

void merge(int* arr, int left, int mid, int right, int size) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temp arrays
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));
    
    // Copy data to temp arrays
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    
    // Show the subarrays being merged
    char message[100];
    snprintf(message, sizeof(message), "Merging subarrays: Left[%d-%d] and Right[%d-%d]", 
             left, mid, mid+1, right);
    drawArrayWithComparison(arr, size, left, right, message);
    sleep_ms(1);
    
    i = 0;
    j = 0;
    k = left;
    
    // Merge temp arrays back into arr[left..right]
    while (i < n1 && j < n2) {
        current_step++;
        snprintf(message, sizeof(message), "Comparing L[%d]=%d and R[%d]=%d", 
                 i, L[i], j, R[j]);
        drawArrayWithComparison(arr, size, left + i, mid + 1 + j, message);
        sleep_ms(1);
        
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        
        drawArray(arr, size, k-1, "After placing element");
        sleep_ms(1);
        drawStep(current_step, total_steps, "Merging Progress");
    }
    
    // Copy remaining elements of L[]
    while (i < n1) {
        current_step++;
        arr[k] = L[i];
        drawArray(arr, size, k, "Copying remaining from left array");
        sleep_ms(1);
        i++;
        k++;
        drawStep(current_step, total_steps, "Merging Progress");
    }
    
    // Copy remaining elements of R[]
    while (j < n2) {
        current_step++;
        arr[k] = R[j];
        drawArray(arr, size, k, "Copying remaining from right array");
        sleep_ms(1);
        j++;
        k++;
        drawStep(current_step, total_steps, "Merging Progress");
    }
    
    free(L);
    free(R);
}

void mergeSortRecursive(int* arr, int left, int right, int size) {
    if (left < right) {
        char message[100];
        int mid = left + (right - left) / 2;
        
        // Show division
        snprintf(message, sizeof(message), "Dividing array[%d-%d] at mid=%d", 
                 left, right, mid);
        drawArrayWithComparison(arr, size, left, right, message);
        sleep_ms(1);
        
        // Sort first and second halves
        mergeSortRecursive(arr, left, mid, size);
        mergeSortRecursive(arr, mid + 1, right, size);
        
        merge(arr, left, mid, right, size);
    }
}

void mergeSort(void) {
    drawHeader("Merge Sort Visualization");
    
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
    
    // Perform merge sort
    mergeSortRecursive(arr, 0, size - 1, size);
    
    // Show final sorted array
    drawArray(arr, size, -1, "Final Sorted Array");
    drawFooter("Merge Sort Complete!");
    
    // Clean up
    free(arr);
} 