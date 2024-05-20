CC = g++-14
CFLAGS += -g -Og -Wall -pthread -pedantic -fdiagnostics-color=always
# SANITIZER = -fsanitize=address  -fsanitize=undefined -fsanitize=leak

SRC = $(shell find ./* -name '*.cpp' -print)
OBJ = $(shell find ./* -name '*.o' -print)
DSYM = $(shell find ./* -name '*.dSYM' -print)
TRG = $(SRC:%.cpp=%)

all: $(TRG)

%: %.cpp
	@$(CC) -c $< $(CFLAGS) $(SANITIZER) -o $@.o
	@$(CC) $@.o $(CFLAGS) $(SANITIZER) -o $@

clean:
	@rm -f $(TRG)
	@rm -f $(OBJ)
	@rm -rf $(DSYM)

.PHONY: all clean
