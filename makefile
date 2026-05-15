CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c99 -pedantic-errors

main: ./bin/main

./bin/main: ./src/string-search.c ./src/main.c
	$(CC) $(CFLAGS) $^ -o $@

run: main
	./bin/main

run.test: test
	./bin/main_test

test: ./bin/main_test

./bin/main_test: ./src/string-search.c ./testing/testing.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f ./bin/*

.PHONY: main run test run.test clean
