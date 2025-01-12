
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define RED "\x1b[31m"
#define RESET "\x1b[0m"
#define YEL "\e[0;33m"

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
    for(int i = 0; i < len; i++){
	if(i == mid || i == left || i == right){
	    printf(RED "%d " RESET, arr[i]);
	} else {
	    printf("%d ", arr[i]);
	}
    }
    printf("\nPress Enter to perform the next step\n");
    getchar();
    getchar();
}

void binarySearch(){
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

    while(left <= right){
	mid = (left + right) / 2;
	if(arr[mid] == num){
	    printf("Number found at index %d.\n", mid);
	    free(arr);
	    return;
	} else if(arr[mid] < num){
	    left = mid + 1;
	    binaryVisualizer(len, mid, left, right, arr);
	} else {
	    right = mid - 1;
	    binaryVisualizer(len, mid, left, right, arr);
	}
    }
    printf("The number %d doesn't exist in the array.\n", num);
    free(arr);
}

void mainLoop(){
    int menu;
    while(1){
	printMenu();

	if(scanf("%d", &menu) != 1){
	    printWarning("You have entered a non-integer value, please enter an integer between 1-3.\n");
	    while(getchar() != '\n');
	    continue;
	} else if(menu < 1 || menu > 3){
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
