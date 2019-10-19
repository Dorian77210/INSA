CFLAGS = -ansi \
		 -pedantic \
		 -Werror \
		 -Wall \
		 -DMAP

OFILES = Main.o \

GPP = g++
EXE = main

all: $(EXE)

clean: 
	rm *.o main


$(EXE) : $(OFILES)
	$(GPP) $(CFLAGS) -o $(EXE) $(OFILES)

Main.o: Main.cpp Comptage.h FilsComptage.h
	$(GPP) $(CFLAGS) -c Main.cpp