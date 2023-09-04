# Rule 1 - to create the final executable file.

Stack_Implementation.out: Stack_Implementation.o stack_ops.o
	gcc -o Stack_Implementation.out Stack_Implementation.o stack_ops.o

#Rule 2 - to create the obj file.
stack_ops.o: stack_ops.c
	gcc -c stack_ops.c
Stack_Implementation.o: Stack_Implementation.c
	gcc -c Stack_Implementation.c

clean:
	rm *.o Stack_Implementation.out
run:
	./Stack_Implementation.out
phony: run clean	
