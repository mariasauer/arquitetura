CFLAGS = -Wall   # flags de compilacao
LDFLAGS = 

CC = gcc

# arquivos-objeto
	exec = entry_generator matriz vector_test

all: $(exec)

entry_generator: entry_generator.c
	$(CC) entry_generator.c -o entry_generator $(LDFLAGS)

matriz: matriz.c
	$(CC) matriz.c -o matriz $(CFLAGS)

vector_test: vector_test.c
	$(CC) vector_test.c -o vector_test $(CFLAGS)

clean:
	rm -f $(exec)