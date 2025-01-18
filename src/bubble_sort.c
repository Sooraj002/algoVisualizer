#include <stdio.h>
#include <stdlib.h>
#include "../include/utils.h" 

void bubble_visualizer(int* arr, int len, int cur) {
    for (int i = 0; i < len; i++) { 
	if (cur == i ) {
	    printf(BHRED BLKB" %d " RESET, arr[i]); 
	} else if (i == cur + 1){
	    printf(BHGRN BLKB" %d " RESET, arr[i]); 
	} else {
	    printf(" %d ", arr[i]); 
	}
    }
    printf("\n");
    printf("Press enter for next step\n");
    getchar(); 
}

void bubble_sort() {
    CLEAN_SCREEN();
    int len;
    int* arr = arrManage(&len);
    CLEAN_BUFFER();
    int og = len;
    while (len > 1) { 
	for (int i = 0; i < len - 1; i++) {
	    if (arr[i] > arr[i + 1]) {
		int temp = arr[i];
		arr[i] = arr[i + 1];
		arr[i + 1] = temp;
		bubble_visualizer(arr, og, i); 
	    }
	}
	len--;
    }

    printf("The array has been sorted:");
    for (int i = 0; i < og; i++) {
	printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    getchar();
}

