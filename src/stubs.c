#include <stdio.h>
#include <stdlib.h>
#include "../include/visualizer.h"
#include "../include/interpolation_search.h"
#include "../include/utils.h"

// Searching algorithms
void interpolationSearch(void) {
    // Clear screen
    printf("\033[2J\033[H");
    
    // Draw welcome screen
    printf("\n╔════════════════════════════════════════════════════════════╗\n");
    printf("║             " COLOR_BRIGHT_CYAN "INTERPOLATION SEARCH" COLOR_RESET "                      ║\n");
    printf("╠════════════════════════════════════════════════════════════╣\n");
    printf("║ " COLOR_YELLOW "Interpolation Search is a variant of binary search that   " COLOR_RESET "║\n");
    printf("║ " COLOR_YELLOW "estimates the position of the target value, assuming a   " COLOR_RESET "║\n");
    printf("║ " COLOR_YELLOW "uniform distribution of values in the array.            " COLOR_RESET "║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");

    // Get array size
    int size;
    printf("╭───────────────────────────╮\n");
    printf("│ Enter array size (1-20): ");
    scanf("%d", &size);
    getchar(); // Clear newline

    // Validate size
    if (size <= 0 || size > 20) {
        printf(COLOR_BRIGHT_RED "\nError: Array size must be between 1 and 20\n" COLOR_RESET);
        printf("\nPress Enter to continue...");
        getchar();
        return;
    }

    // Create array
    int* arr = (int*)malloc(size * sizeof(int));
    if (!arr) {
        printf(COLOR_BRIGHT_RED "\nError: Memory allocation failed\n" COLOR_RESET);
        printf("\nPress Enter to continue...");
        getchar();
        return;
    }

    // Get array elements
    printf("│ Enter %d sorted numbers:    │\n", size);
    printf("╰───────────────────────────╯\n");
    
    for (int i = 0; i < size; i++) {
        printf(COLOR_BRIGHT_BLUE "Enter number %2d: " COLOR_RESET, i + 1);
        scanf("%d", &arr[i]);
        
        // Validate sorting
        if (i > 0 && arr[i] < arr[i-1]) {
            printf(COLOR_BRIGHT_RED "\nError: Numbers must be in ascending order!\n" COLOR_RESET);
            free(arr);
            printf("\nPress Enter to continue...");
            getchar();
            getchar();
            return;
        }
    }

    // Get target value
    printf("\n╭───────────────────────────╮\n");
    printf("│ Enter number to find: ");
    int target;
    scanf("%d", &target);
    printf("╰───────────────────────────╯\n");

    // Perform search
    printf("\nPress Enter to start visualization...");
    getchar();
    getchar();
    
    int result = interpolation_search(arr, size, target);

    // Show search summary
    printf("\n╔════════════════════════════════════════════════════════════╗\n");
    printf("║                    " COLOR_BRIGHT_CYAN "SEARCH SUMMARY" COLOR_RESET "                        ║\n");
    printf("╠════════════════════════════════════════════════════════════╣\n");
    if (result != -1) {
        printf("║ • Target Value: " COLOR_BRIGHT_YELLOW "%-4d" COLOR_RESET "                                      ║\n", target);
        printf("║ • Found at Index: " COLOR_BRIGHT_GREEN "%-4d" COLOR_RESET "                                    ║\n", result);
        printf("║ • Status: " COLOR_BRIGHT_GREEN "SUCCESS" COLOR_RESET "                                         ║\n");
    } else {
        printf("║ • Target Value: " COLOR_BRIGHT_YELLOW "%-4d" COLOR_RESET "                                      ║\n", target);
        printf("║ • Status: " COLOR_BRIGHT_RED "NOT FOUND" COLOR_RESET "                                        ║\n");
    }
    printf("╚════════════════════════════════════════════════════════════╝\n");

    // Clean up
    free(arr);
    printf("\nPress Enter to continue...");
    getchar();
}

// Graph algorithms
void bfs(void) {
    drawHeader("Breadth First Search");
    drawFooter("Coming soon!");
}

void dfs(void) {
    drawHeader("Depth First Search");
    drawFooter("Coming soon!");
}

void dijkstra(void) {
    drawHeader("Dijkstra's Algorithm");
    drawFooter("Coming soon!");
}

// Tree algorithms
void bstOperations(void) {
    drawHeader("Binary Search Tree Operations");
    drawFooter("Coming soon!");
}

void avlOperations(void) {
    drawHeader("AVL Tree Operations");
    drawFooter("Coming soon!");
}

// Dynamic Programming
void fibonacciDP(void) {
    drawHeader("Fibonacci with Dynamic Programming");
    drawFooter("Coming soon!");
}

void longestCommonSubsequence(void) {
    drawHeader("Longest Common Subsequence");
    drawFooter("Coming soon!");
}

// Pattern Matching
void kmpSearch(void) {
    drawHeader("KMP Pattern Matching");
    drawFooter("Coming soon!");
}

void rabinKarp(void) {
    drawHeader("Rabin-Karp Algorithm");
    drawFooter("Coming soon!");
} 