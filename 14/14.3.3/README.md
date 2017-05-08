单客户端单线程，各线程独自accept(),使用互斥锁
====
### 1、编译
``` bash
    $ gcc -o server server.c -lpthread
```
### 2、互斥锁基本操作  
    (1)初始化： 
``` c
        pthread_mutex_t ALOCK = PTHREAD_MUTEX_INITIALIZER;
```
    (2)上锁: 
``` c
        pthread_mutex_lock(&ALOCK);
```
    (3)进入互斥区， 本例程互斥区保护的仅仅是accept() 
``` c
        s_c = accept(s_s, (struct sockaddr*) &from, &len);
```
    (4)解锁 
``` c
        pthread_mutex_unlock(&ALOCK);
```
