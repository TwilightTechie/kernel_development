/*
 * Testing Maximum Memory Allocation
 *
 * See how much memory you can obtain dynamically, using both
 * kmalloc() and __get_free_pages().
 *
 * Start with requesting 1 page of memory, and then keep doubling
 * until *your request fails for each type fails.
 *
 * Make sure you free any memory you receive.
 */

#include <linux/module.h>
#include <linux/slab.h>
#include <linux/init.h>

static int __init my_init(void)
{
	static char *kbuf;
	static unsigned long order;
	int size;

	/* try __get_free_pages__ */

	for (size = PAGE_SIZE, order = 0; order < MAX_ORDER + 1;
	     order++, size *= 2) {
		pr_info(" order=%2ld, pages=%5ld, size=%8d ", order,
			size / PAGE_SIZE, size);
		kbuf = (char *)__get_free_pages(GFP_ATOMIC, order);
		if (!kbuf) {
			pr_err("... __get_free_pages failed\n");
			break;
		}
		pr_info("... __get_free_pages OK\n");
		free_pages((unsigned long)kbuf, order);
	}

	/* try kmalloc */

	for (size = PAGE_SIZE, order = 0; order < MAX_ORDER + 1;
	     order++, size *= 2) {
		pr_info(" order=%2ld, pages=%5ld, size=%8d ", order,
			size / PAGE_SIZE, size);
		kbuf = kmalloc((size_t)size, GFP_ATOMIC);
		if (!kbuf) {
			pr_err("... kmalloc failed\n");
			break;
		}
		pr_info("... kmalloc OK\n");
		kfree(kbuf);
	}
	return 0;
}

static void __exit my_exit(void)
{
	pr_info("Memory Module Unloading\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Anup Sharma, anupnewsmail@gmail.com");
MODULE_DESCRIPTION("max memory check");
MODULE_LICENSE("GPL v2");
