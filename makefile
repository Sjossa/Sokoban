all: Sokoban


Sokoban: main.o  mouvement.o
	gcc main.o  mouvement.o -o Sokoban 


main.o: main.c header.h
	gcc -c main.c



mouvement.o: mouvement.c header.h
	gcc -c mouvement.c	


clean:
	rm -f *.o Sokoban