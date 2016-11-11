all: debug

PROJ = rogue

CC   = g++

CFLAGS = -std=c++98 -g -Wall -pedantic -DDEBUG

BIN  = $(PROJ).bin

SRC  = main.cpp
SRC += game.cpp
SRC += entity.cpp

OBJ  = termio.o $(SRC:.cpp=.o)

debug: clean $(BIN)
	valgrind --leak-check=full ./$(BIN)
	#./$(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

termio.o: termio.c
	gcc -std=gnu99 -DDEBUG -Wall -pedantic -c -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -f $(BIN) *.o
