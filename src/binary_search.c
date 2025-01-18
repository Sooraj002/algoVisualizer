#include <stdio.h>
#include <stdlib.h>
#include "../include/utils.h"


#define RED "\x1b[31m"
#define RESET "\x1b[0m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define WHTB "\e[47m"
#define REDB "\e[41m"
#define GRN "\e[0;32m"
#define BHYEL "\e[1;93m"


void binary_visualization(int len, int mid, int left, int right, int* arr){
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

void binary_search(){
    CLEAN_SCREEN();
    int len, num;

    int* arr = arrManage(&len);

    printf("Enter the number to be searched in the array: ");
    scanf("%d", &num);

    int left = 0, right = len - 1;

    CLEAN_BUFFER();

    while (left <= right) {
	int mid = left + (right - left) / 2;
	printf("Press enter to see next step...");
	getchar();
	binary_visualization(len, mid, left, right, arr); 

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



