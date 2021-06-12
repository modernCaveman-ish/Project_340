all: avm

avm: arith.c  vm.c arith.h  vm.h arith.o vm.o
	gcc -g -o avm arith.c vm.c arith.o  vm.o -lm

arith.o: arith.c arith.h
	gcc -g -o arith.o -c arith.c


vm.o:vm.c vm.h
	gcc -g -o vm.o -c vm.c

clean:
	rm -f a.out vm.o 