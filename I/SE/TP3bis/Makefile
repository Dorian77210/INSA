

default: all

all: crible cat-stdio cat-readwrite cat-mmap prenoms

##########################################
# compilation des programmes

crible: crible.c
	gcc -Wall -Werror -o crible crible.c

cat-stdio: cat-stdio.c
	gcc -Wall -Werror -o cat-stdio cat-stdio.c

cat-readwrite: cat-readwrite.c
	gcc -Wall -Werror -o cat-readwrite cat-readwrite.c

cat-mmap: cat-mmap.c
	gcc -Wall -Werror -o cat-mmap cat-mmap.c

prenoms: prenoms.c
	gcc -Wall -Werror -o prenoms prenoms.c

##########################################
# nettoyage des fichiers générés

clean:
	rm -f crible cat-stdio cat-readwrite cat-mmap prenoms
