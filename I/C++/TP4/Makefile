CC = g++
CFLAGS = -Wall \
		 -Werror \
		 -ansi \
		 -pedantic \
		 -std=c++11 \
		 -g

BIN = bin
SRC = src
INCLUDES = includes
EXE = analog
OFILES = $(BIN)/Main.o \
	     $(BIN)/FileIO.o \
		 $(BIN)/ApplicationManager.o \
		 $(BIN)/Referers.o \
		 $(BIN)/Graph.o

all: $(EXE)

clean:
	rm -rf $(BIN)/* $(EXE)

$(EXE): $(OFILES)
	$(CC) $(CFLAGS) -o $(EXE) $(OFILES)

$(BIN)/ApplicationManager.o: $(INCLUDES)/ApplicationManager.h $(SRC)/ApplicationManager.cpp $(INCLUDES)/FileIO.h $(INCLUDES)/Graph.h
	$(CC) $(CFLAGS) -o $(BIN)/ApplicationManager.o -c $(SRC)/ApplicationManager.cpp

$(BIN)/FileIO.o: $(INCLUDES)/FileIO.h $(SRC)/FileIO.cpp
	$(CC) $(CFLAGS) -o $(BIN)/FileIO.o -c $(SRC)/FileIO.cpp

$(BIN)/Graph.o: $(INCLUDES)/Graph.h $(SRC)/Graph.cpp $(INCLUDES)/Referers.h
	$(CC) $(CFLAGS) -o $(BIN)/Graph.o -c $(SRC)/Graph.cpp	

$(BIN)/Main.o: $(INCLUDES)/ApplicationManager.h $(SRC)/Main.cpp
	$(CC) $(CFLAGS) -o $(BIN)/Main.o -c $(SRC)/Main.cpp

$(BIN)/Referers.o: $(INCLUDES)/Referers.h $(SRC)/Referers.cpp
	$(CC) $(CFLAGS) -o $(BIN)/Referers.o -c $(SRC)/Referers.cpp