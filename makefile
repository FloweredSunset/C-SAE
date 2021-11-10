exoExo : exo.o testExo.o
	gcc -Wall exo.o testExo.o -o exoExo

exo.o : exo.h exo.c
	gcc -Wall exo.c -c

testExo.o : testExo.c
	gcc -Wall testExo.c -c

clean :
	rm *.o exoExo
