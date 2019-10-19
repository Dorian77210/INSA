G = g++
CFLAGS = -Wall \
		 -g \
		 -Werror \
		 -ansi \
		 -pedantic \
		 -std=c++11 \
	#	 -DMAP \
		 
EXE = main
OFILES = Main.o \
		 Arbre.o \
		 TrajetCompose.o \
		 Catalogue.o \
		 Collection.o \
		 Interface.o \
		 Noeud.o \
		 Trajet.o \
		 TrajetSimple.o \

all: $(EXE)

clean:
	rm $(EXE) *.o

$(EXE): $(OFILES)
	$(G) $(CFLAGS) -o $(EXE) $(OFILES)

Arbre.o: Arbre.cpp Arbre.h Catalogue.h Collection.h Trajet.h
	$(G) $(CFLAGS) -c Arbre.cpp

Catalogue.o: Catalogue.cpp Catalogue.h Trajet.h TrajetCompose.h TrajetSimple.h Collection.h Arbre.h
	$(G) $(CFLAGS) -c Catalogue.cpp

Collection.o: Collection.cpp Collection.h Trajet.h
	$(G) $(CFLAGS) -c Collection.cpp

Main.o: Main.cpp Interface.h
	$(G) $(CFLAGS) -c Main.cpp

Interface.o: Interface.cpp Interface.h Catalogue.h Trajet.h TrajetSimple.h TrajetCompose.h Collection.h
	$(G) $(CFLAGS) -c Interface.cpp	

Noeud.o: Noeud.cpp Noeud.h Trajet.h
	$(G) $(CFLAGS) -c Noeud.cpp		

Trajet.o: Trajet.cpp Trajet.h
	$(G) $(CFLAGS) -c Trajet.cpp

TrajetCompose.o: TrajetCompose.cpp TrajetCompose.h Trajet.h
	$(G) $(CFLAGS) -c TrajetCompose.cpp

TrajetSimple.o: TrajetSimple.cpp TrajetSimple.h Trajet.h
	$(G) $(CFLAGS) -c TrajetSimple.cpp
