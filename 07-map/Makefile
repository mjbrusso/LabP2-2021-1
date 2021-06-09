CC=gcc
CFLAGS=-O2 -Wall
 
# compila tudo
all: map.o testamap words

# regra para compilar a map
map.o: map.c
	$(CC) $(CFLAGS) -c map.c

testamap:  map.o testamap.c
	$(CC) $(CFLAGS) testamap.c map.o -o testamap

words: words.c map.o
	$(CC) $(CFLAGS) words.c map.o -o words

# limpa tudo que foi criado
clean:
	rm -f *.o testamap *.csv
