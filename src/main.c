#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "binary_search.h"
#include "utils.h"


/*void getInput(void *input, char *type) {
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
}*/


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
		binary_search();
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
