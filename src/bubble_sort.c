#include <stdio.h>
#include "../include/utils.h" 

void bubble_visualizer(int* arr, int len, int cur) {
    for (int i = 0; i < len; i++) { 
        if (cur == i || cur == i + 1) {
            printf(BHYEL REDB" %d " RESET, arr[i]); 
        } else {
            printf(" %d ", arr[i]); 
        }
    }
    printf("\n");
    printf("Press enter for next step\n");
    getchar(); 
}

void bubble_sort(int* arr, int len) {
    while (len > 1) { // Corrected loop condition
        for (int i = 0; i < len - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                bubble_visualizer(arr, len, i); 
            }
        }
        len--;
    }

    printf("\nSorted array: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
    int len = sizeof(arr) / sizeof(arr[0]); 

    bubble_sort(arr, len);
    return 0;
}
