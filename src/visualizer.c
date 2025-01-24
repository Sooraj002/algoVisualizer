#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/visualizer.h"

void sleep_ms(int x) {
    sleep(x);
}

void clearLines(int count) {
    for (int i = 0; i < count; i++) {
        printf("\033[A\033[2K");
    }
}

void centerText(const char* text, int width) {
    int padding = (width - strlen(text)) / 2;
    for (int i = 0; i < padding; i++) printf(" ");
    printf("%s", text);
}

void drawBox(int width, int height, const char* title) {
    // Top border
    printf("╔");
    for (int i = 0; i < width - 2; i++) printf("═");
    printf("╗\n");

    // Title
    printf("║");
    centerText(title, width - 2);
    printf("║\n");

    // Separator
    printf("╠");
    for (int i = 0; i < width - 2; i++) printf("═");
    printf("╣\n");

    // Content area
    for (int i = 0; i < height - 4; i++) {
        printf("║");
        for (int j = 0; j < width - 2; j++) printf(" ");
        printf("║\n");
    }

    // Bottom border
    printf("╚");
    for (int i = 0; i < width - 2; i++) printf("═");
    printf("╝\n");
}

void drawProgressBar(int progress, int total) {
    int barWidth = 50;
    float percentage = (float)progress / total;
    int filled = (int)(barWidth * percentage);

    printf("[");
    for (int i = 0; i < barWidth; i++) {
        if (i < filled) printf("█");
        else printf(" ");
    }
    printf("] %d%%\r", (int)(percentage * 100));
    fflush(stdout);
}

void drawArray(int* arr, int size, int highlightIndex, const char* message) {
    printf("\n%s\n", message);
    printf("┌");
    for (int i = 0; i < size; i++) {
        printf("────");
        if (i < size - 1) printf("┬");
    }
    printf("┐\n");

    printf("│");
    for (int i = 0; i < size; i++) {
        if (i == highlightIndex)
            printf(COLOR_BRIGHT_GREEN " %2d " COLOR_RESET, arr[i]);
        else
            printf(" %2d ", arr[i]);
        printf("│");
    }
    printf("\n");

    printf("└");
    for (int i = 0; i < size; i++) {
        printf("────");
        if (i < size - 1) printf("┴");
    }
    printf("┘\n");
}

void drawArrayWithComparison(int* arr, int size, int idx1, int idx2, const char* message) {
    printf("\n%s\n", message);
    printf("┌");
    for (int i = 0; i < size; i++) {
        printf("────");
        if (i < size - 1) printf("┬");
    }
    printf("┐\n");

    printf("│");
    for (int i = 0; i < size; i++) {
        if (i == idx1)
            printf(COLOR_BRIGHT_RED " %2d " COLOR_RESET, arr[i]);
        else if (i == idx2)
            printf(COLOR_BRIGHT_BLUE " %2d " COLOR_RESET, arr[i]);
        else
            printf(" %2d ", arr[i]);
        printf("│");
    }
    printf("\n");

    printf("└");
    for (int i = 0; i < size; i++) {
        printf("────");
        if (i < size - 1) printf("┴");
    }
    printf("┘\n");
}

void drawStep(int step, int totalSteps, const char* operation) {
    printf("\nStep %d/%d: %s\n", step, totalSteps, operation);
    drawProgressBar(step, totalSteps);
}

void animateOperation(const char* operation) {
    const char* frames[] = {"⠋", "⠙", "⠹", "⠸", "⠼", "⠴", "⠦", "⠧", "⠇", "⠏"};
    for (int i = 0; i < 10; i++) {
        printf("\r%s %s ", frames[i], operation);
        fflush(stdout);
        sleep_ms(1);
    }
    printf("\n");
}

void drawMainMenu(void) {
    CLEAR_SCREEN();
    printf("\n");
    printf(COLOR_BRIGHT_CYAN);
    printf("    ╔══════════════════════════════════════════╗\n");
    printf("    ║          ALGORITHM VISUALIZER            ║\n");
    printf("    ╚══════════════════════════════════════════╝\n");
    printf(COLOR_RESET "\n");
    
    printf("    1. Sorting Algorithms\n");
    printf("    2. Searching Algorithms\n");
    printf("    3. Graph Algorithms\n");
    printf("    4. Tree Algorithms\n");
    printf("    5. Dynamic Programming\n");
    printf("    6. Pattern Matching\n");
    printf("    7. Exit\n\n");
    
    printf("    Enter your choice: ");
}

void drawSubMenu(const char* title, char** options, int numOptions) {
    CLEAR_SCREEN();
    printf("\n");
    printf(COLOR_BRIGHT_YELLOW);
    printf("    ╔══════════════════════════════════════════╗\n");
    printf("    ║  %-36s  ║\n", title);
    printf("    ╚══════════════════════════════════════════╝\n");
    printf(COLOR_RESET "\n");
    
    for (int i = 0; i < numOptions; i++) {
        printf("    %d. %s\n", i + 1, options[i]);
    }
    printf("    %d. Back to Main Menu\n\n", numOptions + 1);
    
    printf("    Enter your choice: ");
}

void drawHeader(const char* title) {
    CLEAR_SCREEN();
    printf("\n");
    printf(COLOR_BRIGHT_MAGENTA);
    printf("    ╔══════════════════════════════════════════╗\n");
    printf("    ║  %-36s  ║\n", title);
    printf("    ╚══════════════════════════════════════════╝\n");
    printf(COLOR_RESET "\n");
}

void drawFooter(const char* message) {
    printf("\n");
    printf(COLOR_BRIGHT_CYAN);
    printf("    ╔══════════════════════════════════════════╗\n");
    printf("    ║  %-36s  ║\n", message);
    printf("    ╚══════════════════════════════════════════╝\n");
    printf(COLOR_RESET "\n");
    printf("    Press Enter to continue...");
    getchar();
} 