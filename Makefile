socket: main.o
	gcc -o socket main.o

main.o: main.c
	gcc -c main.c

clean: 
	rm -f main *.o

install: socket
	cp socket /usr/bin/ 
