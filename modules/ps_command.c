#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h> // task structure
#include <linux/oom.h>

static int __init my_init(void) {
	struct task_struct *p;

	pr_info("Mini ps: pid, command, state\n\n");

	for_each_process(p) {
		pr_info("pid=%d, comm=%s, stats=%ld\n",
				p->pid, p->comm, p->stats);
	}
	return 0;
}

static void __exit my_exit(void) {
	pr_info("Module unloading\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Anup Sharma, anupnewsmail@gmail.com");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("PS demo");

