CC = gcc
CFLAGS = -Wall \
		 -ansi \
		 -pedantic \
		 -Werror

EXE = main

OFILES = main.o \
		 liste.o

${EXE}: ${OFILES}
	$(CC) $(CFLAGS) -o ${EXE} ${OFILES}


main.o: main.c liste.h
	$(CC) -c main.c

liste.o: liste.h liste.c
	$(CC) -c liste.c

clean: 
	rm -f ${OFILES}
	rm -f ${EXE}