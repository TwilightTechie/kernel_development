#include <linux/module.h>
#include <linux/kernel.h>

int int_param = 10;

module_param(int_param, int, 0);
MODULE_PARM_DESC(int, "Integer parameter to pass value");

static int __init param_init(void) {
	printk("Hello: Interger parameter passed (%d)\n", int_param);
	return 0;
}

static void __exit param_exit(void) {
	printk("Bye, unloading this module\n");
}

module_init(param_init);
module_exit(param_exit);

MODULE_DESCRIPTION("Parameter passing module");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anup Sharma, anupnewsmail@gmail.com");
