all: Sokoban


Sokoban: main.o plateaux.o mouvement.o
	gcc main.o plateaux.o mouvement.o -o Sokoban 


main.o: main.c header.h
	gcc -c main.c

plateaux.o: plateaux.c header.h
	gcc -c plateaux.c

mouvement.o: mouvement.c header.h
	gcc -c mouvement.c	


clean:
	rm -f *.o Sokoban