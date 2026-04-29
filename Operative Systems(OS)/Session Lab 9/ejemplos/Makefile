all: ejemplo1_create ejemplo1_read ejemplo1_write ejemplo2_create ejemplo2_acc ejemplo3_create ejemplo3_acc ejemplo4_acc ejemplo5_prod ejemplo5_cons

ejemplo1_create:
	cc ejemplo1_create.c -o ejemplo1_create

ejemplo1_read:
	cc ejemplo1_read.c -o ejemplo1_read

ejemplo1_write:
	cc ejemplo1_write.c -o ejemplo1_write

ejemplo2_create:
	cc ejemplo2_create.c -o ejemplo2_create

ejemplo2_acc:
	cc ejemplo2_acc.c -o ejemplo2_acc

ejemplo3_create:
	cc ejemplo3_create.c -o ejemplo3_create

ejemplo3_acc:
	cc ejemplo3_acc.c -o ejemplo3_acc

ejemplo4_acc:
	cc ejemplo4_acc.c -o ejemplo4_acc

ejemplo5_prod:
	cc ejemplo5_prod.c -o ejemplo5_prod

ejemplo5_cons:
	cc ejemplo5_cons.c -o ejemplo5_cons

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf ejemplo1_create
	rm -rf ejemplo1_write
	rm -rf ejemplo1_read
	rm -rf ejemplo2_create
	rm -rf ejemplo2_acc
	rm -rf ejemplo3_create
	rm -rf ejemplo3_acc
	rm -rf ejemplo4_acc
	rm -rf ejemplo5_prod
	rm -rf ejemplo5_cons
