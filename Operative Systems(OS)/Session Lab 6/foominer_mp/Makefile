all: foominer fooblockcheck foominer_mp

foominer: foominer.o foominerlib.o
	cc -o foominer foominer.o foominerlib.o -lcrypto

fooblockcheck: fooblockcheck.o foominerlib.o
	cc -o fooblockcheck fooblockcheck.o foominerlib.o -lcrypto

foominer_mp: foominer_mp.o foominerlib.o
	cc -o foominer_mp foominer_mp.o foominerlib.o -lcrypto

foominer.o: foominer.c
	cc -c foominer.c

fooblockcheck.o: fooblockcheck.c
	cc -c fooblockcheck.c

foominerlib.o: foominerlib.c
	cc -c foominerlib.c

foominer_mp.o: foominer_mp.c foominer_mp.h
	cc -c foominer_mp.c

.PHONY: clean
clean:
	rm -rf *.o
	rm -rf *.solved
	rm -rf foominer
	rm -rf fooblockcheck
	rm -rf foominer_mp
