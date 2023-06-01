CC=gcc
CFLAGS=-Wall -pedantic-errors
LDFLAGS=-lm
OPT_FLAGS=
DEBUG_FLAGS=-ggdb3

SRC_DIR := src
DATA_DIR = data
SRC = $(wildcard $(SRC_DIR)/*.c)

all: main debug

# Run all
run_data: $(DATA_DIR) main
	for file in $(basename $(wildcard $(DATA_DIR)/*.in)) ; do \
		echo "\nRunning $${file}..." ; \
		./main < data/$${file} ; \
	done

# Run a test case
run: main
	./main < data/1.in

main: $(SRC)
	$(CC) -o main $(CFLAGS) $(OPT_FLAGS) $(SRC) $(LDFLAGS)

# Run a default test case with valgrind
valgrind: debug
	valgrind --leak-check=full --track-origins=yes ./debug < data/1.in

debug: $(SRC)
	$(CC) -o debug $(DEBUG_FLAGS) $(CFLAGS) $(SRC) $(LDFLAGS)

clean: all
	rm main
	rm debug
