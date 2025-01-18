#include <stdio.h>
#include <stdlib.h>
//#include <string.h>


#define RED "\x1b[31m"
#define RESET "\x1b[0m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define WHTB "\e[47m"
#define REDB "\e[41m"
#define GRN "\e[0;32m"
#define BHYEL "\e[1;93m"
#define BHRED "\e[1;91m"
#define BHGRN "\e[1;92m"
#define BLKB "\e[40m"

void printText(const char* text, const char* color) {
    printf("%s%s%s\n", color, text, RESET);
}

void printWarning(const char* warning){
    printf(YEL "Warning: %s\n" RESET, warning);
}

void printError(const char* error){
    printf(RED "Error: %s\n" RESET, error);
}


int* arrManage(int* len) {
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", len) != 1 || *len <= 0) {
        printf("Invalid input or length can't be zero or negative. Exiting the program...\n");
        return NULL;
    }

    int* arr = (int*) malloc(*len * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed...\n");
        return NULL;
    }

    for (int i = 0; i < *len; i++) {
        printf("Enter the value at index %d: ", i);
        scanf("%d", &arr[i]);
    }
    return arr;
}

void printMenu(){
    printf("Algorithm Visualizer\n");
    printf("1. Binary search\n");
    printf("2. Sorting algorithm\n");
    printf("3. Quit\n");
    printf("Select what would you like to do: ");
}

