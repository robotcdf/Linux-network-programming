一个简单的web服务器例子 SHTTPD
====
## 1、源文件说明：
``` c
    shttpd.h                            \*shttpd头文件，存放数据结构*\
    shttpd_parameters.c                 \*配置文件和命令行参数解析*\
    shttpd.c                            \*主函数*\
    shttpd_worker.c                     \*多客户端框架,客户端请求的业务处理*\
    shttpd_uri.c                        \*URI分析*\
    shttpd_request.c                    \*客户端请求分析*\
    shttpd_method.c                     \*请求方法处理*\
    shttpd_mine.c                       \*请求内容的类别相关变量和函数*\
    shttpd_error.c                      \*错误处理*\
    shttpd_cgihandler.c                 \*CGI处理*\
```
## 2、编译
``` bash 
    $ sudo make
```
## 3、添加html文件
  将超文本文件index.html，复制到“/usr/local/var/www/”目录下。
  运行服务器，不输入任何参数，则服务器会在端口8080侦听，本机IP地址为192.168.1.100。则访问web服务器的请求为:
  http://192.168.1.100:8080/

