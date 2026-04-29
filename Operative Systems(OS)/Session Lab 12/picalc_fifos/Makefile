CC=gcc
CFLAGS=-Wall -Wextra

all: picalc_fifos

picalc_fifos: picalc_dispatcher picalc_worker picalc_gatherer picalc_fifos.c
	$(CC) $(CFLAGS) -o picalc_fifos picalc_fifos.c picalc_pipes.c

picalc_dispatcher: picalc_dispatcher.c picalc_pipes.c
	$(CC) $(CFLAGS) -o picalc_dispatcher picalc_dispatcher.c picalc_pipes.c

picalc_worker: picalc_worker.c picalc_pipes.c
	$(CC) $(CFLAGS) -o picalc_worker picalc_worker.c picalc_pipes.c

picalc_gatherer: picalc_gatherer.c picalc_pipes.c
	$(CC) $(CFLAGS) -o picalc_gatherer picalc_gatherer.c picalc_pipes.c

run_fifos: picalc_dispatcher picalc_worker picalc_gatherer
	rm -f work result
	mkfifo work
	mkfifo result
	./picalc_gatherer result &
	./picalc_worker work result &
	./picalc_worker work result &
	./picalc_worker work result &
	sleep 1
	./picalc_dispatcher 1000000000 50000 work
	rm -f work result

clean:
	rm -f picalc_dispatcher picalc_worker picalc_gatherer picalc_fifos work result
