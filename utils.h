#ifndef UTILS_H
#define UTILS_H

void printWarning(const char* warning);
void printError(const char* error);
void printText(const char* text, const char* color);

#define CLEAN_BUFFER() while (getchar() != '\n')
#define CLEAN_SCREEN() printf("\033[2J\033[H")

void arrManage(int len, int* arr);

#endif // UTILS_H
