KDIR=/lib/modules/$(shell uname -r)/build
cc=x86_64-linux-gnu-gcc-12
obj-m += hello.o
obj-m += uname.o
obj-m += param.o
obj-m += ps_command.o
obj-m += stack.o
# This one is depended on stack.o
obj-m += stack_advance.o

all:
	make -C $(KDIR) M=$(PWD) modules
clean:
	make -C $(KDIR) M=$(PWD) clean
