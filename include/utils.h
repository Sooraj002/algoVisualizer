#ifndef UTILS_H
#define UTILS_H


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


void printWarning(const char* warning);
void printError(const char* error);
void printText(const char* text, const char* color);
void printMenu();

#define CLEAN_BUFFER() while (getchar() != '\n')
#define CLEAN_SCREEN() printf("\033[2J\033[H")

int* arrManage(int* len);

#endif // UTILS_H
