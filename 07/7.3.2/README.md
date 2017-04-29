1.先进行编译,输入
``` bash
$ make
gcc -c tcp_procress.c -o tcp_process.o
cc   -c -o tcp_client.o tcp_client.c
gcc -o client tcp_process.o tcp_client.o 
cc   -c -o tcp_server.o tcp_server.c
gcc -o server tcp_process.o tcp_server.o
```

2.先运行服务器端可执行程序server
``` bash
$ ./server 
```

3.在另一个窗口运行客户端程序client，需要输入本机IP。
``` bash
$ ./client 127.0.0.1
```

4.在client窗户输入数据即可
``` bash
$ fuck server!  
fuck server!    
13 bytes altogether    
```
