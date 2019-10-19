CC = gcc
CFLAGS = -Wall \
		 -Werror \
		 -ansi \
		 -pedantic \
		 -g \
		 -I/usr/include/libpng16 \

BIN_DIR = bin/

OFILES = $(BIN_DIR)main.o \
		 $(BIN_DIR)sprite.o \
		 ${BIN_DIR}coordinate.o \
		 $(BIN_DIR)core.o \
		 $(BIN_DIR)graphic-element.o \
		 $(BIN_DIR)level.o \
		 $(BIN_DIR)player.o \
		 $(BIN_DIR)game.o \
		 ${BIN_DIR}home-view.o \
		 ${BIN_DIR}progress.o \
		 ${BIN_DIR}home-controller.o \
		 ${BIN_DIR}window-controller.o \
		 ${BIN_DIR}app-state.o \


EXE = main
SDL2 = -lSDL2 -lSDL2_image

but: ${EXE}


${EXE}: ${OFILES}
	$(CC) $(CFLAGS) -o ${EXE} ${OFILES} ${SDL2}

${BIN_DIR}app-state.o: app-state.c app-state.h window-controller.h home-view.h home-controller.h game.h
	$(CC) -c app-state.c -o ${BIN_DIR}app-state.o ${SDL2}

${BIN_DIR}coordinate.o: coordinate.c coordinate.h
	$(CC) -c coordinate.c -o ${BIN_DIR}coordinate.o

$(BIN_DIR)core.o: core.c core.h window.h
	$(CC) -c core.c -o ${BIN_DIR}core.o ${SDL2}

$(BIN_DIR)home-controller.o: home-controller.c home-controller.h graphic-element.h coordinate.h graphic-element.h
	$(CC) -c home-controller.c -o ${BIN_DIR}home-controller.o

$(BIN_DIR)home-view.o: home-view.c home-view.h graphic-element.h progress.h
	$(CC) -c home-view.c -o ${BIN_DIR}home-view.o ${SDL2}

$(BIN_DIR)game.o: game.c game.h player.h level.h coordinate.h sprite.h
	$(CC) -c game.c -o ${BIN_DIR}game.o ${SDL2}

$(BIN_DIR)graphic-element.o: graphic-element.c graphic-element.h coordinate.h
	$(CC) -c graphic-element.c -o ${BIN_DIR}graphic-element.o ${SDL2}

$(BIN_DIR)level.o: level.c level.h sprite.h window.h
	$(CC) -c level.c -o ${BIN_DIR}level.o

$(BIN_DIR)main.o: main.c core.h
	$(CC) -c main.c -o ${BIN_DIR}main.o ${SDL2}

$(BIN_DIR)player.o: player.c player.h coordinate.h sprite.h action.h level.h
	$(CC) -c player.c -o ${BIN_DIR}player.o

$(BIN_DIR)progress.o: progress.c progress.h coordinate.h
	$(CC) -c progress.c -o ${BIN_DIR}progress.o

$(BIN_DIR)sprite.o: sprite.c sprite.h coordinate.h
	$(CC) -c sprite.c -o ${BIN_DIR}sprite.o ${SDL2}

$(BIN_DIR)window-controller.o: window-controller.c window-controller.h
	$(CC) -c window-controller.c -o ${BIN_DIR}window-controller.o ${SDL2}

clean:
	rm -rf bin/*