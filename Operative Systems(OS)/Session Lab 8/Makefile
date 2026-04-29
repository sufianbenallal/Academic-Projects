all: picalc_1 picalc_2 picalc_mt_1 picalc_mt_2

picalc_1: picalc.o integrate.o f1.o
	cc -o picalc_1 picalc.o integrate.o f1.o -lm

picalc_2: picalc.o integrate.o f2.o
	cc -o picalc_2 picalc.o integrate.o f2.o -lm

picalc.o: picalc.c f.h integrate.h
	cc -c picalc.c

integrate.o: integrate.c integrate.h
	cc -c integrate.c

f1.o: f1.c f.h
	cc -c f1.c

f2.o: f2.c f.h
	cc -c f2.c

picalc_mt_1: picalc_mt.o integrate_mt.o integrate.o f1.o
	cc -o picalc_mt_1 picalc_mt.o integrate_mt.o integrate.o f1.o -lpthread -lm

picalc_mt_2: picalc_mt.o integrate_mt.o integrate.o f2.o
	cc -o picalc_mt_2 picalc_mt.o integrate_mt.o integrate.o f2.o -lpthread -lm

picalc_mt.o: picalc_mt.c f.h integrate_mt.h integrate.h
	cc -c picalc_mt.c

integrate_mt.o: integrate_mt.c integrate_mt.h
	cc -c integrate_mt.c

.PHONY: clean
clean:
	rm -f *.o
	rm -f test
	rm -f picalc_1
	rm -f picalc_2
	rm -f picalc_mt_1
	rm -f picalc_mt_2
