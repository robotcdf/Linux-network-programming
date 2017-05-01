all:client server
client: process.o client.o 
	gcc -o client process.o client.o
server: process.o server.o
	gcc -o server process.o server.o
process.o:
	gcc -o process.o -c process.c


