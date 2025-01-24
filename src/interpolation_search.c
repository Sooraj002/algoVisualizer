#include <stdio.h>
#include "../include/interpolation_search.h"
#include "../include/visualizer.h"

int interpolation_search(int* arr, int size, int target) {
    int low = 0;
    int high = size - 1;
    int step = 1;

    // Clear screen and show initial state
    printf("\033[2J\033[H"); // Clear screen and move cursor to top
    printf("\n╔════════════════════════════════════════════════════════════╗\n");
    printf("║      " COLOR_BRIGHT_CYAN "INTERPOLATION SEARCH VISUALIZATION" COLOR_RESET "              ║\n");
    printf("╠════════════════════════════════════════════════════════════╣\n");
    printf("║ Target: " COLOR_BRIGHT_YELLOW "%-4d" COLOR_RESET "                                            ║\n", target);
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        // Calculate probe position with formula visualization
        double pos_calc = ((double)(high - low) / (arr[high] - arr[low]));
        int pos;
        if (high == low) {
            pos = low;
        } else {
            pos = low + (int)(pos_calc * (target - arr[low]));
        }

        // Show formula and calculation
        printf("\n" COLOR_BRIGHT_BLUE "Step %d:" COLOR_RESET "\n", step);
        printf("╭───────────────────────────────────────────────────────────╮\n");
        printf("│ Formula: pos = low + ((high-low)/(A[high]-A[low])) × (target-A[low]) │\n");
        printf("│ Values:  pos = %d + ((%d-%d)/(%d-%d)) × (%d-%d)          │\n", 
               low, high, low, arr[high], arr[low], target, arr[low]);
        printf("╰───────────────────────────────────────────────────────────╯\n");

        // Show current range
        printf("\n" COLOR_YELLOW "Searching in range [%d, %d]" COLOR_RESET "\n", low, high);

        // Draw array with current range highlighted
        printf("\n");
        for (int i = 0; i < size; i++) {
            if (i == pos) {
                printf(COLOR_BRIGHT_GREEN "┌──┐" COLOR_RESET);
            } else {
                printf("────");
            }
        }
        printf("\n");
        
        for (int i = 0; i < size; i++) {
            if (i >= low && i <= high) {
                if (i == pos) {
                    printf(COLOR_BRIGHT_GREEN "│%2d│" COLOR_RESET, arr[i]);
                } else {
                    printf(COLOR_YELLOW "%3d " COLOR_RESET, arr[i]);
                }
            } else {
                if (i == pos) {
                    printf(COLOR_BRIGHT_GREEN "│%2d│" COLOR_RESET, arr[i]);
                } else {
                    printf("%3d ", arr[i]);
                }
            }
        }
        printf("\n");
        
        for (int i = 0; i < size; i++) {
            if (i == pos) {
                printf(COLOR_BRIGHT_GREEN "└──┘" COLOR_RESET);
            } else {
                printf("────");
            }
        }
        printf("\n");

        // Show probe position indicator
        for (int i = 0; i < pos; i++) printf("    ");
        printf(COLOR_BRIGHT_GREEN "↑" COLOR_RESET "\n");
        for (int i = 0; i < pos; i++) printf("    ");
        printf(COLOR_BRIGHT_GREEN "Probe" COLOR_RESET "\n");

        // Check if element is found
        if (arr[pos] == target) {
            printf("\n╔════════════════════════════════════════════════════════════╗\n");
            printf("║ " COLOR_BRIGHT_GREEN "TARGET FOUND at index %-3d" COLOR_RESET "                              ║\n", pos);
            printf("╚════════════════════════════════════════════════════════════╝\n");
            return pos;
        }

        // Update search range
        if (arr[pos] < target) {
            printf("\n" COLOR_CYAN "Target is larger, moving right..." COLOR_RESET "\n");
            low = pos + 1;
        } else {
            printf("\n" COLOR_CYAN "Target is smaller, moving left..." COLOR_RESET "\n");
            high = pos - 1;
        }

        step++;
        sleep_ms(2); // Slightly longer delay for better visualization
    }

    // Element not found
    printf("\n╔════════════════════════════════════════════════════════════╗\n");
    printf("║ " COLOR_BRIGHT_RED "TARGET NOT FOUND IN ARRAY" COLOR_RESET "                               ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n");
    return -1;
} 