all: ejemplo5_prod ejemplo5_cons ejemplo6_prod ejemplo6_cons

ejemplo5_prod:
	cc ejemplo5_prod.c -o ejemplo5_prod

ejemplo5_cons:
	cc ejemplo5_cons.c -o ejemplo5_cons

ejemplo6_prod:
	cc ejemplo6_prod.c -o ejemplo6_prod

ejemplo6_cons.c:
	cc ejemplo6_cons.c -o ejemplo6_cons

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf ejemplo5_prod
	rm -rf ejemplo5_cons
	rm -rf ejemplo6_prod
	rm -rf ejemplo6_cons
