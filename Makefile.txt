CC = gcc
CFLAGS = -Wall -Wextra -g -std=c99
SRC = src/main.c src/product.c src/branch.c src/bst.c src/graph.c src/utils.c
OBJ = $(SRC:.c=.o)
INCLUDE = -I src

all: bin/stockship

bin/stockship: $(OBJ)
	mkdir -p bin
	$(CC) $(CFLAGS) $(OBJ) -o bin/stockship

# Regla para compilar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -rf bin

.PHONY: all clean