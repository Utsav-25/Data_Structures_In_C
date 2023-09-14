Doubly_Circular_LinkedList.out: DCLL_main.o DCLL_utils.o
	gcc -o Doubly_Circular_LinkedList.out DCLL_utils.o DCLL_main.o

DCLL_utils.o: DCLL_utils.c
	gcc -c DCLL_utils.c

DCLL_main.o: DCLL_main.c
	gcc -c DCLL_main.c

clean:
	rm *.o *.out
run:
	./Doubly_Circular_LinkedList.out

.PHONY: run clean	

