#include <stdio.h>

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
