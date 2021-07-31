ifneq ($(KERNELRELEASE),)
	include Kbuild

else

	#KERNEL_DIR ?= /lib/modules/$(shell uname -r)/build
	KERNELDIR ?= /home/dlb/Code/linux-5.10
	PWD := $(shell pwd)

	CDB := compile_commands.json
	CC := clang
	
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) CC=$(CC) modules

cdb $(CDB):
	bear -- $(MAKE) -C $(KERNELDIR) M=$(PWD) CC=$(CC) modules

clean:
	rm $(CDB)
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean

.PHONY: default clean cdb

endif
