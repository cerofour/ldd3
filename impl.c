#include <linux/init.h>
#include <asm/current.h>
#include <linux/sched.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

void do_something(void) {
	printk(KERN_ALERT "The current process is %s with PID %d",
			current->comm,
			current->pid
		  );
}
