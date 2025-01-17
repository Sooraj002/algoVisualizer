CC = gcc 
CFLAGS = -Wall -Wextra -std=c11

SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/binary_search.c $(SRC_DIR)/utils.c

OBJS = $(SRCS:.c=.o)

EXEC = $(BUILD_DIR)/program

all: $(EXEC)

$(EXEC):$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -f $(SRC_DIR)/*.o $(EXEC)
