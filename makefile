LFLAGS:= -W -Wall -ggdb -lm
CFLAGS:= -W -Wall -ggdb	

main: main.c grafo.o lista_adjacencia.o prim_mst.o entrada.o
	gcc -o main main.c grafo.o lista_adjacencia.o prim_mst.o entrada.o $(LFLAGS)

grafo.o: grafo.c grafo.h lista_adjacencia.c
	gcc -c grafo.c lista_adjacencia.c $(LFLAGS)

lista_adjacencia.o: lista_adjacencia.c lista_adjacencia.h
	gcc -c lista_adjacencia.c $(CFLAGS)

prim_mst.o: prim_mst.c prim_mst.h lista_adjacencia.c
	gcc -c prim_mst.c lista_adjacencia.c $(LFLAGS)

entrada.o: entrada.c entrada.h lista_adjacencia.c grafo.c
	gcc -c entrada.c lista_adjacencia.c grafo.c $(LFLAGS)

clean: 
	rm -f *.o main