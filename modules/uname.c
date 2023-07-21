#include <linux/module.h>
#include <linux/kernel.h>
// ustname header contain uname structure.
#include <linux/utsname.h>

static int __init uname_init(void) {
	printk("Hello, you currently using kernel-%s\n", init_utsname()->release);
	printk("Hello, your system name is %s\n",init_utsname()->sysname);
	printk("Hello, your version name is %s\n",init_utsname()->version);
	printk("Hello, your domainname is %s\n",init_utsname()->domainname);
	printk("Hello, your machine name is %s\n",init_utsname()->machine);
	return 0;
}

static void __exit uname_exit(void) {
	printk("Bye: Unloading the module\n");
}

module_init(uname_init);
module_exit(uname_exit);

MODULE_DESCRIPTION("Uname Module");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anup Sharma, anupnewsmail@gmail.com");
