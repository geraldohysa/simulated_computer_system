CC = g++
CFLAGS = -Wall

all: main

main: console.o rom.o ram.o mmu.o cpu.o machine_program.o main.o
	$(CC) $(CFLAGS) -o simulated_computer_system console.o rom.o ram.o mmu.o cpu.o machine_program.o main.o

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o simulated_computer_system
