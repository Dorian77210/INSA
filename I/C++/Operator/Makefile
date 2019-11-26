G = g++
CFLAGS = -Wall \
		 -g \
		 -Werror \
		 -ansi \
		 -pedantic \
		 -std=c++11 \
		#  -DMAP \
		 
EXE = main
OFILES = Main.o \
		 Point.o

all: $(EXE)

clean:
	rm $(EXE) *.o

$(EXE): $(OFILES)
	$(G) $(CFLAGS) -o $(EXE) $(OFILES)

Point.o: Point.h Point.cpp
	$(G) $(CFLAGS) -c Point.cpp

Main.o: Point.h
	$(G) $(CFLAGS) -c Main.cpp