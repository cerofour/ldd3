#include <linux/init.h>
#include <asm/current.h>
#include <linux/sched.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

void do_something(void);

static int hello_init(void) {
	/*
	printk(KERN_ALERT "The current process is %s with PID %d",
			current->comm,
			current->pid
		  );
	*/
	do_something();
    return 0;
}

static void hello_exit(void) {
    printk(KERN_ALERT "Stopping ma modul");
}

module_init(hello_init);
module_exit(hello_exit);
