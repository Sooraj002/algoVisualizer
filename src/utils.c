#include <stdio.h>
//#include <string.h>


#define RED "\x1b[31m"
#define RESET "\x1b[0m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define WHTB "\e[47m"
#define REDB "\e[41m"
#define GRN "\e[0;32m"
#define BHYEL "\e[1;93m"

void printText(const char* text, const char* color) {
    printf("%s%s%s\n", color, text, RESET);
}

void printWarning(const char* warning){
    printf(YEL "Warning: %s\n" RESET, warning);
}

void printError(const char* error){
    printf(RED "Error: %s\n" RESET, error);
}

void arrManage(int len, int* arr){
    int dup = len;
    while(dup){
	printf("Enter the value at index %d: ", len - dup);
	scanf("%d", &arr[len - dup]);
	dup--;
    }
}

void printMenu(){
    printf("Algorithm Visualizer\n");
    printf("1. Binary search\n");
    printf("2. Sorting algorithm\n");
    printf("3. Quit\n");
    printf("Select what would you like to do: ");
}


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



