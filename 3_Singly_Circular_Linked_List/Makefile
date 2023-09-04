Singly_Circular_LinkedList.out: SCLL_main.o SCLL_utils.o
	gcc -o Singly_Circular_LinkedList.out SCLL_utils.o SCLL_main.o

SCLL_utils.o: SCLL_utils.c
	gcc -c SCLL_utils.c

SCLL_main.o: SCLL_main.c
	gcc -c SCLL_main.c

clean:
	rm *.o *.out
run:
	./Singly_Circular_LinkedList.out

.PHONY: run clean	

