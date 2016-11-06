###
### @file - intermediate_make_sample
### @author - Harlan James <waldroha@oregonstate.edu>
### @description - Intermediate example for reasonably complete Makefile
###

PROJ = menu_example

CC = g++
AR = ar

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

LIB = libmenu.a

BIN = $(PROJ).bin

CFLAGS  = -std=gnu++11 -Wall -pedantic
CFLAGS += -DNON_CANONICAL_MODE

LDFLAGS = -L./ -lmenu

.PHONY: debug zip 

default: clean $(LIB) $(BIN) debug

debug: $(BIN)

$(BIN): $(OBJ)
	@echo "CC	$@"
	@$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

%.o: %.cpp
	@echo "CC	$^"
	@$(CC) -c $^ $(CFLAGS)

$(LIB): terminal.o menu.o
	@echo "AR	$@"
	@$(AR) rs $@ $^

zip:
	zip $(PROJ).zip *.c *.h *.cpp *.hpp Makefile

clean:
	@echo "RM	*.o"
	@echo "RM	$(LIB)"
	@echo "RM	$(BIN)"
	@rm -f *.o $(BIN) $(LIB)
