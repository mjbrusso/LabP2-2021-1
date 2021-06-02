
CC=gcc
CFLAGS=-O2 -Wall
 
# compila tudo
all: linkedlist.o main.o programa words

# regra para compilar a linkedlist
linkedlist.o: linkedlist.c
	$(CC) $(CFLAGS) -c linkedlist.c

# regra para compilar a main
main.o: main.c linkedlist.h
	$(CC) $(CFLAGS)  -c main.c

# regra para compilar a words
words.o: words.c linkedlist.h
	$(CC) $(CFLAGS)  -c words.c

# regra para linkar o programa
programa: linkedlist.o main.o
	$(CC) $(CFLAGS)  linkedlist.o main.o -o programa

# regra para linkar o words
words: linkedlist.o words.o
	$(CC) $(CFLAGS)  linkedlist.o words.o -o words

# limpa tudo que foi criado
clean:
	rm -f *.o programa words
