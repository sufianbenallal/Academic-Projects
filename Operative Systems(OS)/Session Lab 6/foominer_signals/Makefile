all: foominer fooblockcheck

foominer: foominer.o foominerlib.o
	cc -o foominer foominer.o foominerlib.o -lcrypto
	
fooblockcheck: fooblockcheck.o foominerlib.o
	cc -o fooblockcheck fooblockcheck.o foominerlib.o -lcrypto

foominer.o: foominer.c
	cc -c foominer.c

foominerlib.o: foominerlib.c
	cc -c foominerlib.c
	
fooblockcheck.o: fooblockcheck.c
	cc -c fooblockcheck.c

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf *.solved
	rm -rf foominer
	rm -rf fooblockcheck
