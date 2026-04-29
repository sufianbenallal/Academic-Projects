all: race

race: race.o player.o
	cc -o race race.o player.o

race.o: race.c
	cc -c race.c

player.o: player.c
	cc -c player.c


.PHONY: clean
clean:
	rm -rf *.o
	rm -rf race
