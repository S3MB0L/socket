socket: main.o client.o server.o
	gcc -o socket main.o client.o server.o

main.o: main.c
	gcc -c main.c

client.o: client.c
	gcc -c client.c
	
server.o: server.c
	gcc -c server.c

clean: 
	rm -f main *.o

install: socket
	cp socket /usr/bin/ 
