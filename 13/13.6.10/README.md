1、编译：
``` bash
	$ gcc -o ping ping.c -lpthread
```
2、可能会遇到错误"socket: Operation not permitted"，管理员权限运行即可
``` bash
	$ sudo ./ping www.baidu.com
```
