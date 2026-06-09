CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c99 -pedantic-errors -Iinclude
LDFLAGS =
DEPFLAGS = -MMD -MP

BIN_DIR = bin
SRC_DIR = src
INC_DIR = include
TEST_DIR = tests

EXEC = main
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(BIN_DIR)/%.o)
HEADERS = $(wildcard $(INC_DIR)/*.h)
DEPFILES = $(OBJECTS:.o=.d)

all: $(EXEC) test1 test2

$(EXEC): $(BIN_DIR)/$(EXEC)

run: $(BIN_DIR)/$(EXEC)
	@$(BIN_DIR)/$(EXEC)

$(BIN_DIR)/$(EXEC): $(SRC_DIR)/string-search.c $(SRC_DIR)/$(EXEC).c $(INC_DIR)/string-search.h
	@$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
	@echo "Main built"

test1: $(BIN_DIR)/test1

run-test1: $(BIN_DIR)/test1
	@$(BIN_DIR)/test1

$(BIN_DIR)/test1: $(SRC_DIR)/string-search.c $(TEST_DIR)/testing.c $(INC_DIR)/string-search.h
	@$(CC) $(CFLAGS) $^ -o $@

test2: $(BIN_DIR)/test2

run-test2: $(BIN_DIR)/test2
	@$(BIN_DIR)/test2

$(BIN_DIR)/test2: $(TEST_DIR)/badsymboltest.c
	@$(CC) $(CFLAGS) $^ -o $@

debug: CFLAGS += -g
debug: clean all

release: CFLAGS += -O2 -DNDEBUG
release: LDFLAGS += -s
release: clean all

clean:
	@rm -f $(BIN_DIR)/*
	echo "Clean"

.PHONY: main run run-test1 run-test2 clean
