Single_LinkedList.out: SLL_Utils.o SLL_main.o
	gcc -o Single_LinkedList.out SLL_Utils.o SLL_main.o

SLL_Utils.o: SLL_Utils.c
	gcc -c SLL_Utils.c

SLL_main.o: SLL_main.c
	gcc -c SLL_main.c

clean:
	rm *.o *.out
run:
	./Single_LinkedList.out

.PHONY: run clean	

