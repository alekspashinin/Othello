OPTIONS=-Wall `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV`
OPTIONS2=`pkg-config --libs-only-l MLV`

othello:clean game.o coup.o 1v1.o level1.o arbre.o level2.o level3.o menu.o
	gcc $(OPTIONS) game.o coup.o 1v1.o level1.o arbre.o level2.o level3.o menu.o main.c $(OPTIONS2) -o OTHELLO

game.o:game.c game.h
	gcc $(OPTIONS) -c $(OPTIONS2) game.c

coup.o:coup.c coup.h
	gcc $(OPTIONS) -c $(OPTIONS2) coup.c

1v1.o:1v1.c 1v1.h
	gcc $(OPTIONS) -c $(OPTIONS2) 1v1.c

level1.o:level1.c level1.h
	gcc $(OPTIONS) -c $(OPTIONS2) level1.c

arbre.o:arbre.c arbre.h
	gcc $(OPTIONS) -c $(OPTIONS2) arbre.c

level2.o:level2.c level2.h
	gcc $(OPTIONS) -c $(OPTIONS2) level2.c

level3.o:level3.c level3.h
	gcc $(OPTIONS) -c $(OPTIONS2) level3.c

menu.o:menu.c menu.h
	gcc $(OPTIONS) -c $(OPTIONS2) menu.c

rapport:
	pdflatex rapport.tex

clean:
	rm -f *.o *.log *.aux *.out OTHELLO