CC = gcc
CFLAGS = -W -Wall
DEPS = IO.h Graph.h Prim_prog.h Dijkstra_prog.h Freq_prog.h
OBJ = main.o IO.o Graph.o Prim_prog.o Dijkstra_prog.o Freq_prog.o

Projeto_ED_2: $(OBJ)
	$(CC) -g -o $@ $^ $(CFLAGS)

%.o: %.c $(DEPS)
	$(CC) -g -o $@ -c $< $(CFLAGS)

.PHONY: clean

clean: 
	rm -rf *.o

