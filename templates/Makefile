CC = gcc-13
CFLAGS += -fcolor-diagnostics -fansi-escape-codes -g -Og -Wall -pthread -pedantic
SANITIZER = -fsanitize=address -fsanitize=undefined -fsanitize=leak

SRC = $(shell find ./* -name '*.cpp' -print)
OBJ = $(shell find ./* -name '*.o' -print)
DSYM = $(shell find ./* -name '*.dSYM' -print)
TRG = $(SRC:%.cpp=%)

all: $(TRG)

%: %.c
	@$(CC) -c $< $(CFLAGS) -o $@.o $(SANITIZER)
	@$(CC) $@.o $(CFLAGS) -o $@ $(SANITIZER)

clean:
	@rm -f $(TRG)
	@rm -f $(OBJ)
	@rm -rf $(DSYM)

.PHONY: all clean
