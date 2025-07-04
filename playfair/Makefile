# variables
CC=gcc
CFLAGS=-std=c11 -Wall -Werror
LDLIBS=
OUTPUT=playfair

# targets
all: $(OUTPUT)

$(OUTPUT): playfair.o main.o
	cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c
	$(CC) $(CFLAGS) playfair.o main.o $(LDLIBS) -o $(OUTPUT)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c $(LDLIBS) -o main.o

playfair.o: playfair.c playfair.h
	$(CC) $(CFLAGS) -c playfair.c $(LDLIBS) -o playfair.o

# remove compiled files
clean: 
	rm -rf $(OUTPUT) *.o
