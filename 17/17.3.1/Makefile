	obj-m += hello.o  
#generate the path  
	CURRENT_PATH:=$(shell pwd)  
#the current kernel version number  
	LINUX_KERNEL:=$(shell uname -r)  
#the absolute path  
LINUX_KERNEL_PATH:=/usr/src/linux-headers-$(LINUX_KERNEL) 
#complie object  
all:  
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH)  modules

#robotcdf add
#install:
#    insmod hello .ko
#uninstall:
#    rmmod hello .ko

#clean  
clean:  
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) clean
