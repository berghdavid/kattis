CC=gcc
CFLAGS=-Wall -pedantic-errors
LDFLAGS=-lm
OPT_FLAGS=
DEBUG_FLAGS=-ggdb3

DATA_DIR = data
SRC_DIR = src
GEN_DIR = gensrc
SRC = $(wildcard $(SRC_DIR)/*.c)
GEN = $(wildcard $(GEN_DIR)/*.c)

all: main debug

# Run all
run_data: $(DATA_DIR) main
	for file in $(basename $(wildcard $(DATA_DIR)/*.in)) ; do \
		echo "\nRunning $${file}..." ; \
		./main < data/$${file} ; \
	done

# Run a test case
run: main
	./main < data/2.in

main: $(SRC)
	$(CC) -o main $(CFLAGS) $(OPT_FLAGS) $(SRC) $(LDFLAGS)

# Run a default test case with valgrind
valgrind: debug
	valgrind --leak-check=full --track-origins=yes ./debug < data/2.in

debug: $(SRC)
	$(CC) -o debug $(DEBUG_FLAGS) $(CFLAGS) $(SRC) $(LDFLAGS)

run_gen: gen
	./gen

gen: $(GEN)
	$(CC) -o gen $(CFLAGS) $(OPT_FLAGS) $(GEN) $(LDFLAGS)

clean: all
	rm main
	rm debug
	rm gen
