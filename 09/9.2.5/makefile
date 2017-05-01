all:client server
client: process.o client.o 
	gcc -o client process.o client.o
server: process.o server.o
	gcc -o server process.o server.o
client.o:
	gcc -c ../9.2.1/client.c -o client.o 
server.o:
	gcc -c ../9.2.2/server.c -o server.o
process.o:
	gcc -c process.c -o process.o
clean:
	rm -f client server *.o
