#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#define RED "\x1b[31m"
#define RESET "\x1b[0m"
#define YEL "\e[0;33m"


void printWarning(const char* warning){
    printf(YEL "Warning: %s\n" RESET ,warning);
}

void printError(const char* error){
    printf(RED "Error: %s\n" RESET ,error);
}

int printMenu(){
    int menu;
    printf("Select what would you like to do:\n");
    printf("1. Binary search\n");
    printf("2. Sorting algorithm\n");
    printf("3. Quit\n");
    scanf("%d", &menu);
    return menu;
}

int arrManage(int len, int*arr){
    int dup = len;
    while(dup){
	printf("Enter the value at index: %d", len - dup);
	scanf("%d", &arr[len-dup]);
	dup--;
    }
    return 0;
}



int binarySearch(){
    int len, num, left, right, mid;

    printf("Enter the number of elements in the array");
    scanf("%d", &len);
    int *arr = (int*) malloc(len * sizeof(int));
    if(arr == NULL) return -1;
    arrManage(len, arr);

    printf("Enter the number to be searched in the array");
    scanf("%d", &num);

    while(true){
	if(arr[len/2] == num){
	    printf("Number found at index");
	} else if( arr[len] < num){
	    printf("The number might be on the right half");
	}
    }
    free(arr);
    return 0;
}

int main(){
    int menu = -1;
    while(menu != 3){
	int menu = printMenu();

	if(menu < 1 || menu > 3){
	    printWarning("Input Range from 1 to 3 \n");
	    printMenu();

	}

	switch(menu){
	    case 1:
		//binary search
		printf("binary search");
		break;
	    case 2:
		//sorting algo
		printf("sorting algo");
		break;
	    case 3:
		//quit
		break;
	}
    }

    return 0;
}
