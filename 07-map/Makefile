
CC=gcc
CFLAGS=-O2 -Wall
 
# compila tudo
all: map.o testamap.o testamap

# regra para compilar a map
map.o: map.c
	$(CC) $(CFLAGS) -c map.c

# regra para compilar a testamap
testamap.o: testamap.c map.h
	$(CC) $(CFLAGS)  -c testamap.c

# limpa tudo que foi criado
clean:
	rm -f *.o testamap
