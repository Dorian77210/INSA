CC = gcc
CFLAGS = -Wall \
		 -ansi \
		 -pedantic \
		 -Werror

EXE = main

OFILES = main.o \
		 chaines.o

${EXE}: ${OFILES}
	$(CC) $(CFLAGS) -o ${EXE} ${OFILES}


main.o: main.c chaines.h
	$(CC) -c main.c

chaines.o: chaines.h chaines.c
	$(CC) -c chaines.c

clean: 
	rm -f ${OFILES}
	rm -f ${EXE}