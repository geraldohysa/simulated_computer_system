CC = g++
CFLAGS = -Wall

all: main

main: console.o rom.o ram.o mmu.o cpu.o main.o
	$(CC) $(CFLAGS) -o main console.o rom.o ram.o mmu.o cpu.o main.o

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o main
