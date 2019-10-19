CC = gcc
CFLAGS = -Wall \
		-ansi \
		-Werror \
		-pedantic

OFILES = robot.o \
		 main.o

EXE = robot

but: ${EXE}

${EXE}: ${OFILES}
	$(CC) $(CFLAGS) -o ${EXE} ${OFILES}

main.o: main.c robot.h
	$(CC) -c main.c

robot.o: robot.c robot.h
	$(CC) -c robot.c


clean:
	rm -f ${OFILES}

mrproper: clean but