principal:	principal.o	pessoas.o disciplinas.o
	gcc principal.o pessoas.o disciplinas.o -o principal

principal.o:	principal.c
	gcc -c principal.c

pessoas.o:	pessoas.c	pessoas.h
	gcc -c pessoas.c

disciplinas.o:	disciplinas.c	disciplinas.h
	gcc -c disciplinas.c

clean:
	rm *.o