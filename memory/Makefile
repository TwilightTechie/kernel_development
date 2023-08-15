KDIR = /lib/modules/$(shell uname -r)/build

obj-m += alloc_page.o
obj-m += maxmem.o
obj-m += vmalloc.o

all:
	make -C $(KDIR) M=$(PWD) modules
clean:
	make -C $(KDIR) M=$(PWD) clean
