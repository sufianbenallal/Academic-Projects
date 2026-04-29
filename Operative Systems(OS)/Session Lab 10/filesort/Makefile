CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99

.PHONY: all clean datos

all: filesort_std showgrades filesort_mmap

filesort_std: filesort.o gradesort_std.o
	$(CC) -g -o filesort_std filesort.o gradesort_std.o 

filesort_mmap: filesort.o gradesort_mmap.o
	$(CC) -g -o filesort_mmap filesort.o gradesort_mmap.o

showgrades: showgrades.o
	$(CC) -o showgrades showgrades.o

filesort.o: filesort.c filesort.h
	$(CC) $(CFLAGS) -c filesort.c

showgrades.o: showgrades.c
	$(CC) $(CFLAGS) -c showgrades.c

gradesort_std.o: gradesort_std.c
	$(CC) $(CFLAGS) -c gradesort_std.c

gradesort_mmap.o: gradesort_mmap.c
	$(CC) $(CFLAGS) -g -c gradesort_mmap.c

datos:
	tar -xzf datos.tgz

clean:
	rm -f *.o filesort_std showgrades datos.bin

