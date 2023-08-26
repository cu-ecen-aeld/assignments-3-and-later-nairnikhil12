default:
ifeq ($(CROSS_COMPILE), aarch64-none-linux-gnu-)
	aarch64-none-linux-gnu-gcc writer.c -o writer
else
	gcc writer.c -o writer
endif

clean:
	rm -f writer
	rm -f writer.o
