内核“Hello Word!”程序
====
1、编译
``` bash
    $ make
```
2、加载内核模块
``` bash
    $ sudo insmod hello.ko
```
3、卸载内核模块
``` bash
    $ sudo rmmod hello
```
4、查看消息（不同的运行坏境可能不会显式的输出信息）
``` bash
    $ dmesg
```
