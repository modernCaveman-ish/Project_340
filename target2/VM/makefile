all: avm

avm: arith.c assign.c vm.c arith.h assign.h vm.h arith.o assign.o vm.o
	gcc -g -o avm arith.c assign.c vm.c arith.o assign.o vm.o -lm

arith.o: arith.c arith.h
	gcc -g -o arith.o -c arith.c

assign.o: assign.c assign.h
	gcc -g -o assign.o -c assign.c

vm.o:vm.c vm.h
	gcc -g -o vm.o -c vm.c

clean:
	rm -f avm vm.o assign.o arith.o