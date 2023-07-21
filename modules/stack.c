#include <linux/module.h>
#include <linux/kernel.h>

void print_sub(int no1, int no2) {
	int sub;

	sub = no1 - no2;
	pr_info("Substraction of (%d) and (%d) = %d\n", no1, no2, sub);
}
EXPORT_SYMBOL(print_sub);

void print_sum(int no1, int no2) {
	int sum;

	sum = no1 + no2;
	pr_info("Sum of (%d) and (%d) = %d\n", no1, no2, sum);
}
EXPORT_SYMBOL(print_sum);

static int __init stack_init(void) {
	pr_info("Hello: Loading module stack\n");
	print_sum(10, 30);
	return 0;
}

static void __exit stack_exit(void) {
	printk("Bye: Unloading stack module");
}

module_init(stack_init);
module_exit(stack_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anup Sharma, anupnewsmail@gmail.com");
MODULE_DESCRIPTION("Stack module");
