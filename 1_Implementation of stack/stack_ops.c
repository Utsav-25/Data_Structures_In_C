//C program to implement the stack functions.

#include"stack_ops.h"
#include<stdio.h>
//function definition to initialize the stack
void stack_init(stack_t *st)
{
	st->top = -1; //initialising the top pointer with -1
}

//function definition to check if the stack is full
bool_t if_stack_full(stack_t *st)
{
	if(st->top == SIZE-1)
		return TRUE;
	else
		return FALSE;
}

//function defintion to check if the stack is empty
bool_t if_stack_empty(stack_t* st)
{
	if(st->top == -1)
		return TRUE;
	else
		return FALSE;
}

//function definition to add data into the stack.
void stack_push(stack_t* st, int data)
{
	//check if the stack is full or not.
	if(if_stack_full(st))
		printf("The stack is currently full\n");
	else
	{
		//increment the top counter first
		st->top++;
		st->arr[st->top] = data;
	}
}

//function definition to pop out the topmost elemnt from stack
void stack_pop(stack_t *st)
{
	//first check if the stack is empty
	if(if_stack_empty(st))
		printf("The stack is currently empty\n");
	else	
		st->top--;	//decrementing the top counter so it points to the data value at previous index
}

//function definition to get the value at the top of stack
int stack_peek(stack_t *st)
{
	//first check if the stack is empty
 	if(if_stack_empty(st))
 		printf("The stack is currently empty\n");
 	else
		return st->arr[st->top];

}

