// A menu driven C program to implement the simple functions of a stack.

#include<stdio.h>
#include<stdint.h>
#include "stack_ops.h"
int main(void)
{
	//declaring a stack object
	stack_t s;
	int data;
	uint8_t choice;

	//menu driven program
	do
	{
		printf("\n0. EXIT\n1.PUSH DATA\n2.POP DATA\n3.PEEK DATA\n");
		printf("Enter the operation you want to perform : \n");
		scanf("%hhd",&choice);
		switch(choice)
		{
			case 1: //push data to stack
					printf("Enter the data to be added into the stack:\n");
					scanf("%d",&data);
					stack_push(&s, data);
					break;
			case 2: //pop data from stack
					stack_pop(&s);
					break;
			case 3:	//read topmost element value
					printf("Peeked data = %d\n",stack_peek(&s));
		}
	}while(choice!=0);

}
