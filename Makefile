main: main.o methodes_puissances.o
	@gcc main.o methodes_puissances.o -fopenmp std=c99 -lm -o main
	
main.o: main.c
	@gcc -c main.c
	
methodes_puissances.o: methodes_puissances.c methodes_puissances.h
	@gcc -c methodes_puissances.c
	
clean:
	@rm *.o main
