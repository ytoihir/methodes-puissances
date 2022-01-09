main: main.o GHANNOUMJihad-TOIHIRYoa_codeSourcePUISS.o
	@gcc main.o GHANNOUMJihad-TOIHIRYoa_codeSourcePUISS.o -fopenmp -lm -o main
	
main.o: main.c
	@gcc -c main.c
	
GHANNOUMJihad-TOIHIRYoa_codeSourcePUISS.o: GHANNOUMJihad-TOIHIRYoa_codeSourcePUISS.c GHANNOUMJihad-TOIHIRYoa_codeSourcePUISS.h
	@gcc -c GHANNOUMJihad-TOIHIRYoa_codeSourcePUISS.c
	
clean:
	@rm *.o main
