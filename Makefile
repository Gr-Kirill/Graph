BUILD = ../build/
CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address
OBJ = graph.o stack.o postfix.o polish_notation.o draw.o

all: $(OBJ)
	$(CC) $(CFLAGS) -o $(BUILD)graph $^

graph.o: graph.c
	$(CC) $(CFLAGS) -c $< -o $@

stack.o: stack.c
	$(CC) $(CFLAGS) -c $< -o $@

polish_notation.o: polish_notation.c
	$(CC) $(CFLAGS) -c $< -o $@

postfix.o: postfix.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o $(BUILD)graph

rebuild: clean all