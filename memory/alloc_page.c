#include <linux/module.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/mm.h>

static int __init my_init(void) {
	static char *kbuf;
	static unsigned long order;
	int size;
	struct page *page;
// Try alloc_page
	for (size = PAGE_SIZE, order = 0; order < MAX_ORDER + 1;
			order++, size *=2){
	pr_info(" order=%2ld, pages=%5ld, size=%8ld", order, size / PAGE_SIZE, size);
	page = alloc_pages(GFP_KERNEL, order);
	if (!page) {
		pr_err("....alloc_page failed\n");
		break;
		}
	kbuf = page_address(page);
	strcpy(kbuf, "Testing_page_address");
	pr_info("Page buffer contents = %s\n", kbuf);
	pr_info("...alloc_page OK\n");
		
		__free_pages(page, order);
	}
		return 0;
	}

static void __exit my_exit(void) {
	pr_info("Memory Module Unloading\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Anup Sharma, anupnewsmail@gmail.com");
MODULE_DESCRIPTION("Allocating pages");
MODULE_LICENSE("GPL v2");
