CC = gcc 
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -lm

SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/binary_search.c \
       $(SRC_DIR)/utils.c \
       $(SRC_DIR)/bubble_sort.c \
       $(SRC_DIR)/visualizer.c \
       $(SRC_DIR)/selection_sort.c \
       $(SRC_DIR)/insertion_sort.c \
       $(SRC_DIR)/merge_sort.c \
       $(SRC_DIR)/quick_sort.c \
       $(SRC_DIR)/heap_sort.c \
       $(SRC_DIR)/shell_sort.c \
       $(SRC_DIR)/linear_search.c \
       $(SRC_DIR)/jump_search.c \
       $(SRC_DIR)/interpolation_search.c \
       $(SRC_DIR)/stubs.c

OBJS = $(SRCS:.c=.o)

EXEC = $(BUILD_DIR)/program

all: $(BUILD_DIR) $(EXEC)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

program: $(EXEC) 
	./$(EXEC)

clean:
	rm -f $(SRC_DIR)/*.o $(EXEC)
	rm -rf $(BUILD_DIR)
