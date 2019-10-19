G = g++
CFLAGS = -Wall \
		 -g \
		 -Werror \
		 -ansi \
		 -pedantic \
		 
EXE = main
OFILES = Ensemble.o \
		 EnsembleTest.o \

all: $(EXE)

clean:
	rm $(EXE) *.o

$(EXE): $(OFILES)
	$(G) $(CFLAGS) -o $(EXE) $(OFILES)

Ensemble.o: Ensemble.cpp Ensemble.h
	$(G) $(CFLAGS) -c Ensemble.cpp

EnsembleTest.o: EnsembleTest.cpp Ensemble.h
	$(G) $(CFLAGS) -c EnsembleTest.cpp