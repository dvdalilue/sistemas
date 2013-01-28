GCC="gcc"
OPS="-O0"
OBJS=""
all: ejemplo

ejemplo: libreria2.o libreria.o main.o
	$(GCC) $(OPS) libreria2.o libreria.o main.o -o ejemplo

libreria2.o: libreria2.c
	gcc -c libreria2.c
	
libreria.o: libreria.c
	gcc -c libreria.c
	
main.o: main.c
	gcc -c main.c

clean: 
	rm -f *.o ejemplo
