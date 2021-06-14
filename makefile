all: phaseB

syntax.tab.c syntax.tab.h: syntax.y
	bison -v -d syntax.y

lex.yy.c: scanner.l syntax.tab.h
	flex scanner.l

phaseB: lex.yy.c syntax.tab.c syntax.tab.h hashtbl.o quads.o target.o
	gcc -g -o syntax syntax.tab.c lex.yy.c hashtbl.o quads.o target.o -lm

hashtbl.o: hashtbl.c hashtbl.h
	gcc -g -o hashtbl.o -c hashtbl.c

quads.o: quads.c quads.h
	gcc -g -o quads.o -c quads.c

target.o:target.c target.h
	gcc -g -o target.o -c target.c

clean:
	rm -f syntax syntax.tab.c lex.yy.c syntax.tab.h hashtbl.o quads.o target.o
	rm -f syntax.output