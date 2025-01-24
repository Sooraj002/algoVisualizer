#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <stdio.h>
#include <unistd.h>

// Enhanced color definitions
#define COLOR_BLACK "\e[0;30m"
#define COLOR_RED "\e[0;31m"
#define COLOR_GREEN "\e[0;32m"
#define COLOR_YELLOW "\e[0;33m"
#define COLOR_BLUE "\e[0;34m"
#define COLOR_MAGENTA "\e[0;35m"
#define COLOR_CYAN "\e[0;36m"
#define COLOR_WHITE "\e[0;37m"
#define COLOR_RESET "\e[0m"

// Bright colors
#define COLOR_BRIGHT_BLACK "\e[0;90m"
#define COLOR_BRIGHT_RED "\e[0;91m"
#define COLOR_BRIGHT_GREEN "\e[0;92m"
#define COLOR_BRIGHT_YELLOW "\e[0;93m"
#define COLOR_BRIGHT_BLUE "\e[0;94m"
#define COLOR_BRIGHT_MAGENTA "\e[0;95m"
#define COLOR_BRIGHT_CYAN "\e[0;96m"
#define COLOR_BRIGHT_WHITE "\e[0;97m"

// Background colors
#define BG_BLACK "\e[40m"
#define BG_RED "\e[41m"
#define BG_GREEN "\e[42m"
#define BG_YELLOW "\e[43m"
#define BG_BLUE "\e[44m"
#define BG_MAGENTA "\e[45m"
#define BG_CYAN "\e[46m"
#define BG_WHITE "\e[47m"

// Special effects
#define STYLE_BOLD "\e[1m"
#define STYLE_UNDERLINE "\e[4m"
#define STYLE_REVERSED "\e[7m"

// Screen control
#define CLEAR_SCREEN() printf("\033[2J\033[H")
#define CURSOR_UP(n) printf("\033[%dA", (n))
#define CURSOR_DOWN(n) printf("\033[%dB", (n))
#define CURSOR_HOME() printf("\033[H")
#define SAVE_CURSOR() printf("\033[s")
#define RESTORE_CURSOR() printf("\033[u")

// Animation delay in microseconds
#define ANIMATION_SPEED_FAST 100000
#define ANIMATION_SPEED_MEDIUM 300000
#define ANIMATION_SPEED_SLOW 500000

// Visualization functions
void drawBox(int width, int height, const char* title);
void drawProgressBar(int progress, int total);
void drawArray(int* arr, int size, int highlightIndex, const char* message);
void drawArrayWithComparison(int* arr, int size, int idx1, int idx2, const char* message);
void drawStep(int step, int totalSteps, const char* operation);
void animateOperation(const char* operation);
void drawTree(int* arr, int size, int root, int highlightNode);
void drawGraph(int** adjacencyMatrix, int size, int* visited);
void drawMainMenu(void);
void drawSubMenu(const char* title, char** options, int numOptions);
void drawHeader(const char* title);
void drawFooter(const char* message);

// Helper functions
void sleep_ms(int milliseconds);
void clearLines(int count);
void centerText(const char* text, int width);

#endif // VISUALIZER_H 