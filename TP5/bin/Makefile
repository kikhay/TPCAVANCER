 CFLAGS = -Wall -Wfatal-errors -O2 -ansi -fPIC
OBJ = Main.o Population.o Aleatoire.o code.o

coffre: $(OBJ)
	gcc -o coffre $(OBJ) $(CFLAGS)

Main.o: ../src/Main.c ../include/Population.h ../include/code.h
	gcc -c $< $(CFLAGS)
	
Population.o: ../src/Population.c ../include/Population.h ../include/code.h
	gcc -c $< $(CFLAGS)

Aleatoire.o: ../src/Aleatoire.c ../include/Aleatoire.h ../include/code.h
	gcc -c $< $(CFLAGS)


