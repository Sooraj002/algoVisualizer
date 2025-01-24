#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/visualizer.h"
#include "../include/binary_search.h"
#include "../include/bubble_sort.h"
#include "../include/utils.h"

// Function declarations for new algorithms (to be implemented)
void selectionSort(void);
void insertionSort(void);
void mergeSort(void);
void quickSort(void);
void heapSort(void);
void shellSort(void);

void linearSearch(void);
void jumpSearch(void);
void interpolationSearch(void);

void bfs(void);
void dfs(void);
void dijkstra(void);

void bstOperations(void);
void avlOperations(void);

void fibonacciDP(void);
void longestCommonSubsequence(void);

void kmpSearch(void);
void rabinKarp(void);

void handleSortingMenu(void) {
    char* options[] = {
        "Bubble Sort",
        "Selection Sort",
        "Insertion Sort",
        "Merge Sort",
        "Quick Sort",
        "Heap Sort",
        "Shell Sort"
    };
    
    while (1) {
        drawSubMenu("Sorting Algorithms", options, 7);
        int choice;
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1: bubble_sort(); break;
            case 2: selectionSort(); break;
            case 3: insertionSort(); break;
            case 4: mergeSort(); break;
            case 5: quickSort(); break;
            case 6: heapSort(); break;
            case 7: shellSort(); break;
            case 8: return;
            default:
                drawFooter("Invalid choice! Please try again.");
        }
    }
}

void handleSearchingMenu(void) {
    char* options[] = {
        "Binary Search",
        "Linear Search",
        "Jump Search",
        "Interpolation Search"
    };
    
    while (1) {
        drawSubMenu("Searching Algorithms", options, 4);
        int choice;
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1: binary_search(); break;
            case 2: linearSearch(); break;
            case 3: jumpSearch(); break;
            case 4: interpolationSearch(); break;
            case 5: return;
            default:
                drawFooter("Invalid choice! Please try again.");
        }
    }
}

void handleGraphMenu(void) {
    char* options[] = {
        "Breadth First Search (BFS)",
        "Depth First Search (DFS)",
        "Dijkstra's Shortest Path"
    };
    
    while (1) {
        drawSubMenu("Graph Algorithms", options, 3);
        int choice;
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1: bfs(); break;
            case 2: dfs(); break;
            case 3: dijkstra(); break;
            case 4: return;
            default:
                drawFooter("Invalid choice! Please try again.");
        }
    }
}

void handleTreeMenu(void) {
    char* options[] = {
        "Binary Search Tree Operations",
        "AVL Tree Operations"
    };
    
    while (1) {
        drawSubMenu("Tree Algorithms", options, 2);
        int choice;
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1: bstOperations(); break;
            case 2: avlOperations(); break;
            case 3: return;
            default:
                drawFooter("Invalid choice! Please try again.");
        }
    }
}

void handleDPMenu(void) {
    char* options[] = {
        "Fibonacci Series",
        "Longest Common Subsequence"
    };
    
    while (1) {
        drawSubMenu("Dynamic Programming", options, 2);
        int choice;
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1: fibonacciDP(); break;
            case 2: longestCommonSubsequence(); break;
            case 3: return;
            default:
                drawFooter("Invalid choice! Please try again.");
        }
    }
}

void handlePatternMenu(void) {
    char* options[] = {
        "KMP Pattern Matching",
        "Rabin-Karp Algorithm"
    };
    
    while (1) {
        drawSubMenu("Pattern Matching", options, 2);
        int choice;
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1: kmpSearch(); break;
            case 2: rabinKarp(); break;
            case 3: return;
            default:
                drawFooter("Invalid choice! Please try again.");
        }
    }
}

int main() {
    while (1) {
        drawMainMenu();
        int choice;
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1:
                handleSortingMenu();
                break;
            case 2:
                handleSearchingMenu();
                break;
            case 3:
                handleGraphMenu();
                break;
            case 4:
                handleTreeMenu();
                break;
            case 5:
                handleDPMenu();
                break;
            case 6:
                handlePatternMenu();
                break;
            case 7:
                drawHeader("Thank you for using Algorithm Visualizer!");
                sleep_ms(1500);
                return 0;
            default:
                drawFooter("Invalid choice! Please try again.");
        }
    }
    return 0;
}
