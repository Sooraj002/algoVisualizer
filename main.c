#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define RED "\x1b[31m"
#define RESET "\x1b[0m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define WHTB "\e[47m"
#define REDB "\e[41m"
#define GRN "\e[0;32m"
#define BHYEL "\e[1;93m"

#define CLEAN_BUFFER() while (getchar() != '\n')
#define CLEAN_SCREEN() printf("\033[2J\033[H")

void getInput(void *input, char *type) {
    if (strcmp(type, "int") == 0) {
        while (scanf("%d", (int *)input) != 1) {
            CLEAN_BUFFER();
            printf("Invalid input. Please enter an integer: ");
        }
    } else if (strcmp(type, "float") == 0) {
        while (scanf("%f", (float *)input) != 1) {
            CLEAN_BUFFER();
            printf("Invalid input. Please enter a valid float: ");
        }
    } else if (strcmp(type, "str") == 0) {
        char buffer[100];
        CLEAN_BUFFER();  
        fgets(buffer, sizeof(buffer), stdin);
        strcpy((char *)input, buffer);
    }
    CLEAN_BUFFER();  
}

void printText(const char* text, const char* color) {
    printf("%s%s%s\n", color, text, RESET);
}

void printWarning(const char* warning){
    printf(YEL "Warning: %s\n" RESET, warning);
}

void printError(const char* error){
    printf(RED "Error: %s\n" RESET, error);
}


void printMenu(){
    printf("Algorithm Visualizer\n");
    printf("1. Binary search\n");
    printf("2. Sorting algorithm\n");
    printf("3. Quit\n");
    printf("Select what would you like to do: ");
}

void arrManage(int len, int* arr){
    int dup = len;
    while(dup){
	printf("Enter the value at index %d: ", len - dup);
	scanf("%d", &arr[len - dup]);
	dup--;
    }
}

void binaryVisualizer(int len, int mid, int left, int right, int* arr){
    printf("Array Index:  ");
    for(int i = 0; i < len; i++){
	if(i == mid){
	    printf(BHYEL REDB" %d " RESET, i);
	} else if(i == left || i == right){
	    printf(RED WHTB " %d " RESET, i);
	} else if (i > left && i < right) {
	    printf(BLU WHTB " %d " RESET, i);
	} else {
	    printf(" %d ", i);
	}
    }

    for(int i = 0; i < len; i++){
	printf("|");
	printf("-");
    }


    printf("\n");

    printf("Array Values: ");
    for(int i = 0; i < len; i++){
	if(i == mid){
	    printf(BHYEL REDB" %d " RESET, arr[i]);
	} else if(i == left || i == right){
	    printf(RED WHTB" %d " RESET, arr[i]);
	} else if (i > left && i < right) {
	    printf(BLU WHTB " %d " RESET, arr[i]);
	} else {
	    printf(" %d ", arr[i]);
	}

    }

    printf("\n");
    CLEAN_BUFFER();
}

void binarySearch(){
    CLEAN_SCREEN();
    int len, num;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &len);

    if(len == 0){
	printError("Array length can't be Zero. Exiting the program...\n");
	return;
    }

    int *arr = (int*) malloc(len * sizeof(int));
    if(arr == NULL){
	printError("Memory allocation failed...\n");
	free(arr);
	return;
    }
    arrManage(len, arr);

    printf("Enter the number to be searched in the array: ");
    scanf("%d", &num);

    int left = 0, right = len - 1, mid;

    CLEAN_BUFFER();

    while (left <= right) {
	int mid = left + (right - left) / 2;
	printf("Press enter to see next step...");
	getchar();
	binaryVisualizer(len, mid, left, right, arr); 

	if (arr[mid] == num) {
	    printf("Number found at index %d.\n", mid);
	    getchar();
	    free(arr); 
	    return;
	} else if (arr[mid] < num) {
	    left = mid + 1;
	} else {
	    right = mid - 1;
	}
    }
    printf("The number %d doesn't exist in the array.\n", num);
    getchar();
    free(arr);
}



void mainLoop(){
    int menu;
    while(1){
	CLEAN_SCREEN();
	printMenu();

	if(scanf("%d", &menu) != 1){
	    printWarning("You have entered a non-integer value, please enter an integer between 1-3.\n");
	    while(getchar() != '\n');
	    continue;
	} else if(menu < 1 || menu > 4){
	    printWarning("Input Range from 1 to 3 and your current input doesn't match any of them.\n");
	    continue;
	}

	switch(menu){
	    case 1:
		printf("binary search\n");
		binarySearch();
		break;
	    case 2:
		printf("sorting algorithm\n");
		break;
	    case 3:
		printf("Exiting the program...\n");
		return;
	}
    }
}

int main(){
    mainLoop();
    return 0;
}
