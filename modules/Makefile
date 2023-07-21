KDIR=/lib/modules/$(shell uname -r)/build
cc=x86_64-linux-gnu-gcc-12
obj-m += hello.o
obj-m += uname.o

all:
	make -C $(KDIR) M=$(PWD) modules
clean:
	make -C $(KDIR) M=$(PWD) clean
