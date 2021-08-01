PWD := $(shell pwd)

hellop:
	$(MAKE) -C basic/hellop M=$(PWD)

clean:
	$(MAKE) -C basic/hellop M=$(PWD) clean
