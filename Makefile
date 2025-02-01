CC=gcc
FLAGS=-Wall -Wextra
MAIN=cwaifu

all:
	$(CC) $(FLAGS) $(MAIN).c -o $(MAIN)
	./$(MAIN)

.PHONY: all
