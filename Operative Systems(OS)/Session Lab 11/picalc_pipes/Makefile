CFLAGS=-Wall -g

all: picalc_pipes

picalc_pipes: picalc_pipes.o picalc_agents.o integrate.o f1.o
	cc picalc_pipes.o picalc_agents.o integrate.o f1.o  -o picalc_pipes -lm
clean:
	rm -r *.o picalc_pipes 

