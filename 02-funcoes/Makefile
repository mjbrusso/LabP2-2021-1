
CC=gcc
CFLAGS=-O3 -Wall
 
# compila tudo
all: funcoes.o main.o programa

funcoes.o: funcoes.c
	$(CC) $(CFLAGS) -c funcoes.c

main.o: main.c funcoes.h
	$(CC) $(CFLAGS)  -c main.c

programa: funcoes.o main.o
	$(CC) $(CFLAGS)  funcoes.o main.o -o programa

# limpa tudo que foi criado
clean:
	rm -f *.o programa

install: programa
	sudo cp programa /usr/bin

uninstall: 
	sudo rm -f /usr/bin/programa