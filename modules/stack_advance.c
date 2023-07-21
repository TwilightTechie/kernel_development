#include <linux/module.h>
#include <linux/kernel.h>

# include "stack_advance.h"

static int __init stack_advance_init(void) {
	printk("Hello: Loading stack_advance Module\n");
	print_sum(23, 34);
	print_sub(34, 45);
	return 0;
}

static void __exit stack_advance_exit(void){
	printk("Bye Bye: Unloading stack_advance Module");
}

module_init(stack_advance_init);
module_exit(stack_advance_exit);

MODULE_DESCRIPTION("Stack Advance");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anup Sharma, anupnewsmail@gmail.com");
