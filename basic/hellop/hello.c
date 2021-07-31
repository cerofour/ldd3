#include <linux/init.h>
#include <asm/current.h>
#include <linux/sched.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("dlb04");
MODULE_DESCRIPTION("Prints \"Hello <whom>\" <howmany> times");

static char* whom = "world";
static unsigned int howmany = 1;

module_param(howmany, uint, S_IRUGO);
module_param(whom, charp, S_IRUGO);

static int hello_init(void) {
    {
        unsigned int i;
        for (i = 0; i < howmany; ++i) {
            printk(KERN_ALERT "Hello %s\n", whom);
        }
    }
    return 0;
}

static void hello_exit(void) {
    printk(KERN_ALERT "Stopping ma modul");
}

module_init(hello_init);
module_exit(hello_exit);
