principal:	pessoas.o	disciplinas.o
	gcc principal.c pessoas.o disciplinas.o -o principal
	
pessoas.o:
	gcc -c pessoas.c

disciplinas.o:
	gcc -c disciplinas.c

clean:
	rm *.o