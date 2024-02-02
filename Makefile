CC=gcc
BIN_NAME=eca

build:
	$(CC) *.c -o $(BIN_NAME) -O3

run:
	$(CC) *.c -o $(BIN_NAME) -O3
	./$(BIN_NAME)

clean:
	rm $(BIN_NAME)