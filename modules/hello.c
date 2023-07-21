#include <linux/module.h>
#include <linux/kernel.h>

static int __init hello_init(void) {
	printk("Hello: Loading my first kernel module on 27/07/2023\n");
	return 0;
}

static void __exit hello_exit(void) {
	printk("Bye: Unloading the module\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_DESCRIPTION("Greeting Module");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anup Sharma anupnewsmail@gmail.com");

